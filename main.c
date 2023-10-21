#include "cub3d.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], 0);
	t_parse map;
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		printf("line: %s\n", line);
		if (line == 0)
			break;
		else if (ft_strncmp(line, "NO ", 3) == 0)
			map.NO = ft_substr(line, 4, ft_strlen(line));
		else if (ft_strncmp(line, "SO ", 3) == 0)
			map.SO = ft_substr(line, 4, ft_strlen(line));
		else if (ft_strncmp(line, "WE ", 3) == 0)
			map.WE = ft_substr(line, 4, ft_strlen(line));
		else if (ft_strncmp(line, "EA ", 3) == 0)
			map.EA = ft_substr(line, 4, ft_strlen(line));
		else if (ft_strncmp(line, "F ", 2) == 0)
			map.F = ft_substr(line, 3, ft_strlen(line));
		else if (ft_strncmp(line, "C ", 2) == 0)
			map.C = ft_substr(line, 3, ft_strlen(line));
		else if (line[0] != '\n')
		{
			map.array[i] = ft_strdup(line);
			i++;
		}
		free(line);
	}
	printf("NO: %s\n", map.NO);
	printf("SO: %s\n", map.SO);
	printf("WE: %s\n", map.WE);
	printf("EA: %s\n", map.EA);
	printf("F: %s\n", map.F);
	printf("C: %s\n", map.C);
	mapcheck(map.array, i - 1);
	for (int i = 0; i < 14; i++)
		printf("map: %s", map.array[i]);
}