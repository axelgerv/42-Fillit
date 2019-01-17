/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/16 18:03:52 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		read_fd(int fd, char **blocks)
{
	int		rd;
	char	*buf;
	char	*reduced;
	int		nbr_blocks;
	char	*tmp;

	tmp = ft_memalloc(21);
	nbr_blocks = 0;
	buf = ft_memalloc(21);
	while ((rd = read(fd, buf, 21)) > 0)
	{
		tmp = ft_strdup(buf);
		if (check_error(buf))
		{
			ft_strdel(&buf);
			return (-1);
		}
		if (check_error(buf) || !(reduced = reduce(buf, x_min(buf), y_min(buf), x_max(buf))))
			return (-1);
		if (!(blocks[nbr_blocks] = ft_strdup(reduced)))
			return (-1);
		nbr_blocks++;
		ft_strclr(buf);
	}
	if (tmp[20] == '\n')
		return (-1);
	ft_strdel(&tmp);
	ft_strdel(&buf);
	return (nbr_blocks <= 26 ? nbr_blocks : 0);
}
