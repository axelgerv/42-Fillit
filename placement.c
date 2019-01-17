/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:30:29 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/16 14:53:58 by julaurai         ###   ########.fr       */
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
				if (!map[y + blocks_y] || !map[y + blocks_y][x + blocks_x] || map[y + blocks_y][x + blocks_x] != '.')
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

int		delete_placement(char **map, char letter, int x, int y)
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
int		backtracking(char **map, t_tetri **element, int side, int order)
{
	int x;
	int y;

	x = 0;
	y = 0;
	if (!element[order])
		return (1);
	while (map[y] && map[y][x])
	{
		//ft_putchar('o');
		//ft_putnbr(order);
		if(placement(map, element[order], x, y))
		{
			if (backtracking(map, element, side, order + 1))
				return (1);
		}
		delete_placement(map, element[order]->order, x, y);
		move_vector(&y, &x, side);
		/*if (x == side - 1)
		{
			x = 0;
			y++;
		}
		else
			x++;*/
	}
	return (0);
}

void	move_vector(int *y, int *x, int map_size)
{
	if (*x == map_size - 1)
	{
		*x = 0;
		*y += 1;
	}
	else
		*x += 1;
}


int		fill_or_grow(t_tetri **element, int nbr_blocks)
{
	int size;
	char **map;

	(void)nbr_blocks;
	size = 2;
	map = create_map(size);
	while (!backtracking(map, element, size, 0))
	{
		size++;
		delete_map(map);
		map = create_map(size);
	}
	print_map(map);
	delete_map(map);
	return (0);
}
