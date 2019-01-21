/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:57:06 by julaurai          #+#    #+#             */
/*   Updated: 2019/01/17 15:16:34 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_error(void)
{
	ft_putendl("error");
	return (-1);
}

int		clean_exit(char **buf, char **tmp, char **reduced, int mod)
{
	if (buf)
	{
		free(*buf);
		*buf = NULL;
	}
	if (tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
	if (reduced)
	{
		free(*reduced);
		*reduced = NULL;
	}
	return (mod);
}
