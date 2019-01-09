/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/09 14:14:21 by axelgerv         ###   ########.fr       */
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
	*storage = ft_strnew(BUFF_SIZE);
	while ((rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		if (check_error(buf) == -1)
		{
			ft_putstr("error\n");
			return (-1);
		}
		nbr_blocks++;
		*storage = ft_strjoinf(storage, &buf, 1);
		ft_strclr(buf);
	}
	return (nbr_blocks);
}
