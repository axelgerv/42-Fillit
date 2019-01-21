/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 14:45:45 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/18 09:03:47 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_link(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 0 && str[i - 1] == '#')
				count++;
			if (i > 4 && str[i - 5] == '#')
				count++;
			if (i < 15 && str[i + 5] == '#')
				count++;
			if (i < 18 && str[i + 1] == '#')
				count++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (-1);
	return (0);
}

static int		check_block2(char buf, int *dot, int *tetri, int *eof)
{
	if (buf != '.' && buf != '\n' && buf != '#')
		return (-1);
	if (buf == '.')
		*dot += 1;
	if (buf == '#')
		*tetri += 1;
	if (buf == '\n')
		*eof += 1;
	return (0);
}

static int		check_block_is_valid(char *buf)
{
	int i;
	int j;
	int tetri;
	int eof;
	int dot;

	eof = 0;
	j = 4;
	i = -1;
	dot = 0;
	tetri = 0;
	while (buf[++i])
	{
		if (buf[i] == '\n' && i != 20)
			if (i % j != 0)
				return (-1);
		if (buf[i] == '\n' && i != 20)
			j = j + 5;
		if (check_block2(buf[i], &dot, &tetri, &eof))
			return (-1);
	}
	buf[20] == '\0' ? eof++ : 0;
	if (dot != 12 || tetri != 4 || eof != 5)
		return (-1);
	return (0);
}

int				check_error(char *block)
{
	int i;

	i = 0;
	if (check_block_is_valid(block) < 0)
		return (-1);
	if (check_link(block) < 0)
		return (-1);
	return (0);
}
