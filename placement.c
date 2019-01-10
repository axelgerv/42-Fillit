/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:30:29 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/10 15:52:58 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		placement(char **map, char **tetri, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (map[y][x])
	{
		j = 0;
		if (map[y][x] == '.' && tetri[i][j] == '#')
			map[y][x] == tetri[i][j];
		else if (map[y][x] == '#')


	}
}
