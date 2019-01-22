/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: axelgerv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:51:48 by axelgerv          #+#    #+#             */
/*   Updated: 2019/01/21 15:28:53 by julaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

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
char				*reduce(char *buf);
void				print_map(char **map);
void				delete_map(char **map);
void				del_struct(t_tetri **tetri);
int					map_size(int nbr_blocks);
int					ft_len(char *buf, int x_m, int y, int x_max);
int					read_fd(int fd, char **storage);
int					storage(char **block, t_tetri **tetri);
int					b_track(char **map, t_tetri **tetri, int side, int order);
int					fill_or_grow(t_tetri **tetri, int nbr_blocks);
int					check_error(char *block);
int					ft_error(void);
int					clean_exit(char **buf, char **tmp, char **reduced, int mod);

#endif
