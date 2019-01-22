/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generator_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 11:48:48 by julaurai          #+#    #+#             */
/*   Updated: 2019/01/21 15:31:28 by julaurai         ###   ########.fr       */
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
		if (!(map[i] = ft_strnew(side)))
			return (NULL);
		ft_memset(map[i--], '.', side);
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
	{
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
}

int		map_size(int nbr_blocks)
{
	int i;

	i = 0;
	while (i < nbr_blocks)
	{
		if (i * i == nbr_blocks)
			return (i);
		if (i * i > nbr_blocks)
			return (i - 1);
		i++;
	}
	return (0);
}
