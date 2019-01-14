/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:51:48 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/14 17:21:53 by axelgerv         ###   ########.fr       */
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
	char			**tetri;
}					t_tetri;

char				**create_map(int side);
char				*reduce(char *buf, int x_m, int y, int x_M);
void				print_map(char **map);
void				delete_map(char **map);
int					delete_placement(char **map, char letter, int x, int y);
int					placement(char **map, t_tetri *blocks, int x, int y);
int					ft_len(char *buf, int x_m,int y, int x_M);
int					check_link(char *str);
int					check_y(char *buf);
int					check_x(char *buf);
int					check_x_max(char *buf);
int					check_block_is_valid(char *buf);
int					check_error(char *block);
int					read_fd(int fd, char **storage);
t_tetri				*new_element(char **block, int order);
int					storage(char **block, t_tetri **tetri);
int					backtracking(char **map ,t_tetri **element, int side);
int					fill_or_grow(t_tetri **element, int blocks);

#endif
