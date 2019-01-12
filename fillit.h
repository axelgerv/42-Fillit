/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:51:48 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/10 19:36:10 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF 21

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef	struct		s_tetri
{
	char			order;
	char			*tetri[5];
	struct s_tetri	*next;
}					t_tetri;

char				**create_map(int side);
char				*reduce(char *buf, int x_min, int y, int x_max);
void				print_map(char **map);
void				delete_map(char **map);
int					ft_strlen_tetri(char *buf, int x_min, int y, int x_max);
int					check_link(char *str);
int					check_y(char *buf);
int					check_x(char *buf);
int					check_x_max(char *buf);
int					check_block_is_valid(char *buf);
int					check_error(char *block);
int					read_fd(int fd, char **storage);
t_tetri				*new_element(char **block, int order);
int					storage(char **block, t_tetri **tetri);

#endif
