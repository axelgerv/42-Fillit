/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:42:19 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/14 11:11:32 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*blocks[27];
	int		nbr_blocks;
	t_tetri	**element;

	nbr_blocks = 0;
	if (argc != 2)
		ft_putstr("usage: fillit target_file\n");
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if ((nbr_blocks = read_fd(fd, blocks)) == - 1)
		{
			ft_putstr("error\n");
			return (-1);
		}
		close(fd);
	}
	if (!(element = (t_tetri **)malloc(sizeof(t_tetri *) * (nbr_blocks + 1))))
		return (0);
	storage(blocks, element);
	fill_or_grow(element, nbr_blocks);
	return (0);
}
