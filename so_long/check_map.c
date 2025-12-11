/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:08:36 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/10 20:09:22 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_all(char **map, int line)
{
	while (line)
	{
		
	}
}

char	**get_map(int fd, int **map)
{
	char	*temp[1];
	int	readsize;
	int	line;
	int	i;

	i = 0;
	line = 0;
	readsize = 1;
	while (readsize)
	{
		readsize = read(fd, temp, 1);
		if (temp[0] != '\n')
			map[line][i] = ft_atoi(temp[0]);
		else
			line++;
		i++;
	}
	return (map);
}

char	**check_map(char *mapfile)
{
	int	fd;
	int	map[1000][1000];

	fd = open(mapfile);
	**map = get_map(fd, map);
	if (!map)
		return (NULL);
}	
