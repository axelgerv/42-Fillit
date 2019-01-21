/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:16:39 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/21 13:50:57 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_tetri	*new_tetri(char **block, int order)
{
	t_tetri	*block_list;

	if (!(block_list = (t_tetri *)ft_memalloc(sizeof(t_tetri))))
		return (NULL);
	block_list->tetri = NULL;
	block_list->order = 0;
	block_list->order = order + 'A';
	block_list->tetri = ft_strsplit(block[order], '\n');
	return (block_list);
}

int				storage(char **block, t_tetri **tetri)
{
	int i;

	i = 0;
	while (block[i] != 0)
	{
		if (!(tetri[i] = new_tetri(block, i)))
			return (-1);
		free(block[i]);
		block[i] = NULL;
		i++;
	}
	return (0);
}
