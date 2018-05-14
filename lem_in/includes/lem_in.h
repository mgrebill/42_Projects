/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:48:19 by mgrebill          #+#    #+#             */
/*   Updated: 2017/10/19 14:43:06 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../libft/includes/ft_printf.h"

typedef struct			s_room
{
	struct s_lst_rooms	*connections;
	char				*name;
	int					x;
	int					y;
	int					distance;
	bool				start;
	bool				end;
	bool				ant;
	char				pad__[1];
}						t_room;

typedef struct			s_lst_rooms
{
	t_room				*room;
	struct s_lst_rooms	*next;
}						t_lst_rooms;

typedef struct			s_tube
{
	char				*room1;
	char				*room2;
}						t_tube;

typedef struct			s_lst_tubes
{
	t_tube				*tube;
	struct s_lst_tubes	*next;
}						t_lst_tubes;

typedef struct			s_ant
{
	t_room				*room;
	int					num;
	int					color;
	bool				moved;
	char				pad__[7];
}						t_ant;

typedef struct			s_lst_ants
{
	t_ant				*ant;
	struct s_lst_ants	*next;
}						t_lst_ants;

typedef struct			s_anthill
{
	int					start;
	int					end;
	int					room_manager;
	int					tube_manager;
	t_lst_rooms			*rooms;
	t_lst_tubes			*tubes;
	t_lst_ants			*ants;
	bool				color;
	char				pad__[7];
}						t_anthill;

void					ft_print_ant(t_ant ant, bool color);
void					ft_print_room(t_room room);
void					ft_print_tube(t_tube tube);
int						ft_parse_anthill(t_anthill **anthill);
t_lst_ants				*ft_parse_ants(char *str);
int						ft_parse_and_manage_rooms(char *str,
															t_anthill *anthill);
int						ft_parse_and_manage_tubes(char *str,
															t_anthill *anthill);
int						ft_connect_rooms(t_anthill *anthill);
int						ft_set_distances(t_anthill *anthill);
void					ft_release_the_ants(t_anthill *anthill);
void					ft_init_ants(t_anthill *anthill);
void					ft_free_anthill(t_anthill *anthill);

#endif
