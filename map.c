/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:58:44 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/16 15:41:30 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int side)
{
	char	**map;
	int		i;

	if (!(map = (char **)ft_memalloc(sizeof(char *) * (side + 1))))
		return (NULL);
	i = side;
	map[i--] = 0;
	while (i >= 0)
	{
		if (!(map[i] = ft_memalloc(side)))
			return (NULL);
		ft_memset(map[i--], 46, side);
	}
	return (map);
}

void	print_map(char **map)
{
	int i;
	int j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			ft_putchar(map[j][i]);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	delete_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
		ft_strdel(&map[i++]);
	free(map);
}
