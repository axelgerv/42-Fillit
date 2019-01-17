/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:42:19 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/16 18:28:38 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	**blocks;
	int		nbr;
	t_tetri	**tetri;

	fd = 0;
	nbr = 0;
	if (!(blocks = (char**)ft_memalloc(sizeof(char*) * (27))))
		return (ft_error());
	if (argc != 2)
		ft_putstr("usage: ./fillit target_file\n");
	else if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (ft_error());
		if (((nbr = read_fd(fd, blocks)) == -1 || nbr == 0))
			return (ft_error());
		close(fd);
		if (!(tetri = (t_tetri **)ft_memalloc(sizeof(t_tetri *) * (nbr + 1))))
			return (ft_error());
		if (storage(blocks, tetri) || fill_or_grow(tetri, nbr))
			return (ft_error());
	}
	return (0);
}
