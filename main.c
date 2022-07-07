#include "get_next_line.h"
	
int	main()
{
	int	i;
	int	fd;
	char 	*line;

	i = 0;
	fd = open("41_no_nl", O_RDONLY);
	if (fd == -1)
		return (-1);
	line = "";
	printf("fd %i\n",fd);
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("line %i text >> %s",i ,line);
		++i;
	}
//	system("leaks a.out");
	close(fd);
	return (0);
}
