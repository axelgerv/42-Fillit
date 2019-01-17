/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:41:14 by julaurai          #+#    #+#             */
/*   Updated: 2019/01/16 17:12:15 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		x_min(char *buf)
{
	int i;
	int x;

	i = 0;
	x = 5;
	while (buf[i])
	{
		if (buf[i] == '#' && i % 5 < x)
			x = i % 5;
		i++;
	}
	return (x);
}

int		x_max(char *buf)
{
	int i;
	int x;

	x = 0;
	i = 20;
	while (i >= 0)
	{
		if (buf[i] == '#' && i % 5 > x)
			x = i % 5;
		i--;
	}
	return (x);
}

int		y_min(char *buf)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			return (y);
		if (buf[i] == '\n')
			y++;
		i++;
	}
	return (y);
}

int		ft_strlen_tetri(char *buf, int x_min, int y, int x_max)
{
	int i;
	int j;
	int k;
	int count;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	while (buf[i])
	{
		buf[i] == '#' ? count++ : 0;
		if (buf[i] == '\n')
		{
			j >= y ? k++ : 0;
			j++;
			if (count == 4)
				break ;
		}
		if (i % 5 >= x_min && i % 5 <= x_max && j >= y)
			k++;
		i++;
	}
	return (k + 1);
}

char	*reduce(char *buf, int x_min, int y, int x_max)
{
	char	*reduced;
	int		i;
	int		j;
	int		k;
	int		count;
	int		len;

	len = ft_strlen_tetri(buf, x_min, y, x_max) + 1;
	if (!(reduced = (char*)ft_memalloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	count = 0;
	j = 0;
	k = 0;
	while (buf[i])
	{
		buf[i] == '#' ? count++ : 0;
		if (buf[i] == '\n')
		{
			if (j >= y)
			{
				reduced[k] = buf[i];
				k++;
			}
			j++;
			if (count == 4)
				break ;
		}
		if (i % 5 >= x_min && i % 5 <= x_max && j >= y)
		{
			reduced[k] = buf[i];
			k++;
		}
		i++;
	}
	return (reduced);
}
