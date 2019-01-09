/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:51:48 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/09 14:14:34 by axelgerv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 21

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct		s_tetri
{
	char			order;
	char			tetri[5][5];
	struct s_tetri	*next;
}					t_tetri;

char				**create_map(int side);
void				print_map(char **map);
void				delete_map(char **map);
int					check_link(char *str);
int					check_block_is_valid(char *buf);
int					check_error(char *block);
int					read_fd(int fd, char **storage);

#endif
