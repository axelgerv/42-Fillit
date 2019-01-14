/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:30:29 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/14 17:52:35 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		placement(char **map, t_tetri *blocks, int x, int y)
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
				if ((!map[y + blocks_y][x + blocks_x]) || map[y + blocks_y][x + blocks_x] != '.')
				{
					delete_placement(map, blocks->order, x, y);
					return (-1);
				}
				else
					map[y + blocks_y][x + blocks_x] = blocks->order;
			}
			blocks_x++;
		}
		blocks_y++;
	}
	return (0);
}

int		delete_placement(char **map, char letter, int x, int y)
{
	int i;

	i = 0;
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

int		backtracking(char **map, t_tetri **element, int side)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;

	while (map[y] && map[y][x])
	{
		if(placement(map, element[i], x, y))
		{
			if (backtracking(map, element[i++], side))
				return (0);
		}
		if ((x + 1) > side)
		{
			if ((y + 1) <= side )
			{
				x = 0;
				y++;
			}
			else
				return (1);
		}
		x++;
	}
	return (1);
}

int		fill_or_grow(t_tetri **element, int blocks)
{
	int size;
	char **map;
	(void)blocks;

	size = 4;
	map = create_map(size);
	while (!backtracking(map, element, size))
	{
		size++;
		delete_map(map);
		map = create_map(size);
	}
	print_map(map);
	delete_map(map);
	return (0);
}
