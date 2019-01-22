/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 09:08:45 by julaurai          #+#    #+#             */
/*   Updated: 2019/01/21 15:26:20 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		placement(char **map, t_tetri *blocks, int x, int y)
{
	int blocks_x;
	int blocks_y;

	blocks_y = 0;
	while (blocks->tetri[blocks_y])
	{
		blocks_x = 0;
		while (blocks->tetri[blocks_y][blocks_x])
		{
			if (blocks->tetri[blocks_y][blocks_x] == '#')
			{
				if (!map[y + blocks_y] || !map[y + blocks_y][x + blocks_x] ||
						map[y + blocks_y][x + blocks_x] != '.')
					return (0);
				else
					map[y + blocks_y][x + blocks_x] = blocks->order;
			}
			blocks_x++;
		}
		blocks_y++;
	}
	return (1);
}

static int		delete_placement(char **map, char letter, int x, int y)
{
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == letter)
				map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (0);
}

static void		move_vector(int *y, int *x, int map_size)
{
	if (*x == map_size - 1)
	{
		*x = 0;
		*y += 1;
	}
	else
		*x += 1;
}

int				btrack(char **map, t_tetri **tetri, int side, int order)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!tetri[order])
		return (1);
	while (map[y] && map[y][x])
	{
		if (placement(map, tetri[order], x, y))
		{
			if (btrack(map, tetri, side, order + 1))
				return (1);
		}
		delete_placement(map, tetri[order]->order, x, y);
		move_vector(&y, &x, side);
	}
	return (0);
}

int				fill_or_grow(t_tetri **tetri, int nbr_blocks)
{
	int		size;
	char	**map;

	size = map_size(nbr_blocks * 4);
	map = create_map(size);
	while (!btrack(map, tetri, size, 0))
	{
		size++;
		delete_map(map);
		map = create_map(size);
	}
	print_map(map);
	delete_map(map);
	del_struct(tetri);
	return (0);
}
