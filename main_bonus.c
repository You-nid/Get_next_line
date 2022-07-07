# define true 1
#define false !true
#include "get_next_line_bonus.h"

int	main(int ac, char **arg)
{
	int		fd[MAX_OPEN];
	char	*line;
	int		i;
	int		c;
	int		l;
	_Bool	still_read;


	i = 0;
	c = 0;
	line = "";
	still_read = true;
	if (ac > 1)
	{
		while (arg[i + 1])
		{
			fd[i] = open(arg[i + 1], O_RDONLY);
			if  (fd[i] < 0)
				return (0);
			printf("file opened %i and file value %i\n", i, fd[i]);
			++i;
		}
		while (still_read)
		{
			still_read = false;
			l = 0;
			while (l < i)
			{
				line = get_next_line(fd[l]);
				if (line)
				{
					still_read = true;
					printf("line %i ====== %s\n",l, line);
				}
				free(line);
				++l;
			}
		}
	}
	return (0);
}
