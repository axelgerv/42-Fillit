/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 19:41:14 by julaurai          #+#    #+#             */
/*   Updated: 2019/01/18 09:05:46 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		x(char *buf)
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

static int		xmax(char *buf)
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

static int		ymin(char *buf)
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

static int		len_tetri(char *buf, int x_min, int y, int x_max)
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

char			*reduce(char *b)
{
	char	*r;
	int		i;
	int		j;
	int		k;
	int		count;

	if (!(r = ft_memalloc(len_tetri(b, x(b), ymin(b), xmax(b)) + 1)))
		return (NULL);
	i = -1;
	count = 0;
	j = 0;
	k = -1;
	while (b[++i])
	{
		b[i] == '#' ? count++ : 0;
		if (b[i] == '\n')
		{
			j >= ymin(b) ? r[++k] = b[i] : 0;
			j++;
			if (count == 4)
				break ;
		}
		i % 5 >= x(b) && i % 5 <= xmax(b) && j >= ymin(b) ? r[++k] = b[i] : 0;
	}
	return (r);
}
