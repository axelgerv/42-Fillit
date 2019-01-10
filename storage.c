/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:16:39 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/10 16:29:08 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	  check_x(char *buf, int mod)
{
	int i;
	int x;

	mod == 1 ? (i = 0) : (i = 20);
	mod == 1 ? (x = 5) : (x = 0);
	if (mod == 1)
	{
		while (buf[i])
		{
			if (buf[i] == '#' && i % 5 < x)
				x = i % 5;
			i++;
		}
	}
	if (mod == -1)
	{
		while (i >= 0)
		{
			if (buf[i] == '#' && i % 5 > x)
				x = i % 5;
			i--;
		}
	}
	return (x);
}

int		check_y(char *buf, int mod)
{
	int i;
	int y;

	mod == 1 ? (i = 0) : (i = 19);
	mod == 1 ? (y = 0) : (y = 4);
	if (mod == 1)
	{
		while (buf[i])
		{
			if (buf[i] == '#')
				return (y);
			if (buf[i] == '\n')
				y++;
			i++;
		}
	}
	if (mod == -1)
	{
		while (i >= 0)
		{
			if (buf[i] == '#')
				return (y);
			if (buf[i] == '\n')
				y--;
			i--;
		}
	}
	return (y);
}

t_tetri	*new_element(char **block, int order)
{
	int		i;
	t_tetri	*block_list;

	if (!(block_list = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	i = 0;
	block_list->order = order + 'A';
	block_list->tetri[i] = ft_strdup(block[order]);
	ft_putchar('\n');
	ft_putchar(block_list->order);
	ft_putchar('\n');
	ft_putstr(block_list->tetri[i]);
	i++;
	ft_putchar('\n');
	return (NULL);
}

int		storage(char **block, t_tetri **tetri)
{
	int i;

	i = 0;
	while (block[i])
	{
		tetri[i] = new_element(block, i);
		i++;
	}
	return (0);
}
