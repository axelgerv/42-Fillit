/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:30:29 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/14 11:11:29 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		placement(char **map, t_tetri *blocks, int x, int y)
{
	int i;
	int xi;
	int yi;

	i = 0;
	xi = x;
	yi = y;
	while (blocks->tetri[i])
	{
		if (map[y][x] != '.' && blocks->tetri[i] != '.')
		{
			delete_placement(map, blocks->order, xi, yi);
			return (0);
		}
		if (map[y][x] == '.')
		{
			if(blocks->tetri[i] == '#')
				map[y][x] = blocks->order;
			x++;
			i++;
		}
		if (blocks->tetri[i] == '\n')
		{
			x = xi;
			y++;
			i++;
		}
		if (!map[y][x])
		{
			delete_placement(map, blocks->order, xi, yi);
			return (0);
		}
	}
	return (1);
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
				if (placement(map, element[i++], x, y))
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

	size = 10;
	map = create_map(size);
	while (!(backtracking(map, element, size)))
	{
		print_map(map);
		size++;
		delete_map(map);
		map = create_map(size);
	}
	return (0);
}
