/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:07:48 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/06/23 11:03:38 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

void	*ft_memmove(char *dest, const char *src, size_t n)
{
	if (!dest || !src)
		return (NULL);
	if (src < dest)
	{
		while (n--)
			*(dest + n) = *(src + n);
		return (dest);
	}
	else
		while (n--)
			*dest++ = *src++;
	return (dest);
}

static size_t	ft_find_len(const char *s, size_t *new_l)
{
	size_t	i;
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len] != '\0')
		++len;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			*new_l = i + 1;
			break ;
		}
		++i;
	}
	return (len);
}

static char	*ft_read(char *str, int fd)
{
	char	*buff;
	size_t	len;

	len = 1;
	buff = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (len > 0 && !ft_strchr(buff, '\n'))
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat[MAX_OPEN];
	size_t		len;
	size_t		new_l;

	len = 0;
	new_l = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!stat[fd])
		stat[fd] = ft_calloc(1, 1);
	stat[fd] = ft_read(stat[fd], fd);
	if (!stat[fd])
		return (NULL);
	len = ft_find_len(stat[fd], &new_l);
	if (new_l == 0)
		new_l = len;
	line = ft_get_line(&stat[fd], new_l);
	stat[fd] = ft_get_next(stat[fd], new_l, len);
	return (line);
}
