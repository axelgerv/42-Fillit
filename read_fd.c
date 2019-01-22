/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/21 15:10:16 by julaurai         ###   ########.fr       */
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

	tmp = ft_memalloc(sizeof(char) * 22);
	buf = ft_memalloc(sizeof(char) * 22);
	nbr_blocks = 0;
	while ((rd = read(fd, buf, 21)) > 0)
	{
		ft_strdel(&tmp);
		tmp = ft_strdup(buf);
		if ((check_error(buf)) || (!(reduced = reduce(buf))))
			return (clean_exit(&buf, &tmp, &reduced, -1));
		if (!(blocks[nbr_blocks] = ft_strdup(reduced)))
			return (clean_exit(&buf, &tmp, &reduced, -1));
		ft_strdel(&reduced);
		nbr_blocks++;
		ft_strclr(buf);
	}
	if (tmp[20] == '\n')
		return (-1);
	clean_exit(&buf, &tmp, &reduced, 0);
	return (nbr_blocks <= 26 ? nbr_blocks : 0);
}
