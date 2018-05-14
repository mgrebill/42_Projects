# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrebill <mgrebill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:40:43 by mgrebill          #+#    #+#              #
#    Updated: 2017/10/19 15:57:46 by mgrebill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		lem-in

SRCS =		main.c\
			ft_print_ant.c\
			ft_print_room.c\
			ft_print_tube.c\
			ft_parse_ants.c\
			ft_parse_and_manage_rooms.c\
			ft_parse_and_manage_tubes.c\
			ft_parse_anthill.c\
			ft_connect_rooms.c\
			ft_set_distances.c\
			ft_release_the_ants.c\
			ft_init_ants.c\
			ft_free_anthill.c

SRCSDIR =	srcs

INCLUDES =	includes/

OBJ =		$(SRCS:.c=.o)

OBJDIR =	obj

CFLAGS =
CFLAGS +=	-Wall
CFLAGS +=	-Wextra
CFLAGS +=	-Wpadded
CFLAGS +=	-Werror
CFLAGS +=	-Weverything
CFLAGS +=	-Wconversion
CFLAGS +=	-Wredundant-decls
CFLAGS +=	-Winline
CFLAGS +=	-O3

all: $(NAME)

$(NAME):
	@echo "──────▄▀▄─────▄▀▄  Mgrebill's"
	@echo "─────▄█░░▀▀▀▀▀░░█▄     lem_in"
	@echo "─▄▄──█░░░░░░░░░░░█──▄▄─"
	@echo "█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█"
	@echo "***********************"
	@echo "Compilation in progress"
	@echo "***********************"
	@mkdir obj 2> /dev/null || true
	@gcc $(CFLAGS) -I $(INCLUDES) -c $(addprefix $(SRCSDIR)/, $(SRCS))
	@mv $(OBJ) $(OBJDIR)
	@make -C libft/
	@mv libft/libft.a .
	@gcc $(CFLAGS) -o $(NAME) $(addprefix $(OBJDIR)/, $(OBJ)) libft.a
	@echo "  Compilation done !  "
	@echo "lem_in ready for use !"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft/
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting objects... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "                          "

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting lem_in...  Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "                          "

re: fclean all
