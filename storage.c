/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   storage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:16:39 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/12 15:50:19 by julaurai         ###   ########.fr       */
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
	block_list->tetri = ft_strdup(block[order]);
	ft_putchar('\n');
	ft_putchar(block_list->order);
	ft_putchar('\n');
	ft_putstr(block_list->tetri);
	i++;
	ft_putchar('\n');
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

