/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzaytoun <yzaytoun@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 12:10:05 by yzaytoun          #+#    #+#             */
/*   Updated: 2022/06/22 13:12:28 by yzaytoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<fcntl.h>

# ifndef MAX_OPEN
#  define MAX_OPEN 4096
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_next(char *stat, size_t new_l, size_t len);
char	*ft_get_line(char **str, size_t n);
void	*ft_memmove(char *dest, const char *src, size_t n);
#endif
