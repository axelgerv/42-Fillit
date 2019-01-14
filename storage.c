/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:16:39 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/14 17:24:31 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*new_element(char **block, int order)
{
	int		i;
	t_tetri	*block_list;

	if (!(block_list = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	i = 0;
	block_list->order = order + 'A';
	block_list->tetri = ft_strsplit(block[order], '\n');
	i++;
	return (block_list);
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

