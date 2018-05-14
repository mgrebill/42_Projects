/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:18:21 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/30 14:49:06 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "Libft/libft.h"
# define BUFF_SIZE 666

typedef struct		s_tris
{
	int				x_1;
	int				y_1;
	int				x_2;
	int				y_2;
	int				x_3;
	int				y_3;
	char			index;
	struct s_tris	*next;
}					t_tris;

t_tris				*ft_lst_new_piece(char index, char **piece);
t_tris				*check_parse(char *file);
void				ft_lst_del_one_piece(t_tris	**ptr_list);
void				ft_lst_del_pieces(t_tris **begin_list);
void				ft_lst_add_piece_end(t_tris **begin_list, t_tris *new);
void				ft_print_str_str_table(char ***tab);
void				ft_lst_print_pieces(t_tris *begin_list);
void				ft_error(void);
char				***ft_tab_tab_tab(char **tab);
char				**ft_generate_grid(size_t size);
char				**ft_strsplit_nn(char const *s, char c);
int					nb_pieces(char **tab);
int					check_coherence(char *s);
size_t				ft_nbpiecetab(t_tris *piece);
size_t				ft_sizeofgrid(size_t stab);
int					check_megatab(char ***megatab);
int					ft_fill_it(t_tris *piece, size_t p, size_t size,
								char **grid);

#endif
