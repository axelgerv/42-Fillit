/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 15:42:19 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/09 14:15:23 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*storage;
	int		nbr_blocks;
	t_tetri	**element;

	nbr_blocks = 0;
	if (argc != 2)
		ft_putstr("usage: fillit target_file\n");
	else if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		storage = NULL;
		nbr_blocks = read_fd(fd, &storage);
		if (nbr_blocks == -1)
			return (0);
		close(fd);
	}
	if (!(element = (t_tetri **)malloc(sizeof(t_tetri *) * (nbr_blocks + 1))))
		return (0);
	ft_putstr(storage);
	ft_putchar('\n');
	ft_putnbr(nbr_blocks);
	return (0);
}
