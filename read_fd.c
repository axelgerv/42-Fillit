/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/09 15:34:26 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_fd(int fd, char **storage)
{
	int		rd;
	char	*buf;
	int		nbr_blocks;

	nbr_blocks = 0;
	buf = ft_strnew(BUFF_SIZE);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (check_error(buf) == -1)
		{
			ft_strdel(&buf);
			ft_putstr("error\n");
			return (-1);
		}
		storage[nbr_blocks] = ft_strdup(buf);
		nbr_blocks++;
		ft_strclr(buf);
	}
	ft_strdel(&buf);
	return (nbr_blocks);
}
