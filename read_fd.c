/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/13 15:44:49 by julaurai         ###   ########.fr       */
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
		if (check_error(buf))
		{
			ft_strdel(&buf);
			return (-1);
		}
		if (!(reduced = reduce(buf, check_x(buf), check_y(buf), check_x_max(buf))))
			return(-1);
		if(!(blocks[nbr_blocks] = ft_strdup(reduced)))
			return (-1);
		nbr_blocks++;
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	blocks[nbr_blocks] = 0;
	return (nbr_blocks);
}
