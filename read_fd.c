/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/10 19:37:56 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_fd(int fd, char **blocks)
{
	int		rd;
	char	*buf;
	char	*reduced;
	int		nbr_blocks;

	nbr_blocks = 0;
	buf = ft_strnew(BUFF);
	while ((rd = read(fd, buf, BUFF)) > 0)
	{
		if (check_error(buf) == -1)
		{
			ft_strdel(&buf);
			ft_putstr("error\n");
			return (-1);
		}
		reduced = reduce(buf, check_x(buf), check_y(buf), check_x_max(buf));
		blocks[nbr_blocks] = ft_strdup(reduced);
		nbr_blocks++;
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	blocks[nbr_blocks] = 0;
	return (nbr_blocks);
}
