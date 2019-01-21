/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:14:04 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/21 14:21:49 by axelgerv         ###   ########.fr       */
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

	tmp = ft_memalloc(sizeof(char) * 21);
	buf = ft_memalloc(sizeof(char) * 21);
	nbr_blocks = 0;
	while ((rd = read(fd, buf, 21)) > 0)
	{
		ft_strdel(&tmp);
		tmp = ft_strdup(buf);
		if ((check_error(buf)) || (!(reduced = reduce(buf))))
			return (clean_exit(&buf, &tmp, &reduced, -1));
		if (!(blocks[nbr_blocks] = ft_strdup(reduced)))
			return (clean_exit(&buf, &tmp, &reduced, -1));
		nbr_blocks++;
		ft_strclr(buf);
	}
	if (tmp[20] == '\n')
		return (-1);
	clean_exit(&buf, &tmp, &reduced, 0);
	free(reduced);
	return (nbr_blocks <= 26 ? nbr_blocks : 0);
}
