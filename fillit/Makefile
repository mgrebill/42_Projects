# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrebill <mgrebill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:40:43 by mgrebill          #+#    #+#              #
#    Updated: 2016/11/30 14:32:43 by nlaubres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS =	main.c\
		parser.c\
		check.c\
		ft_generate_grid.c\
		ft_lst_add_piece_end.c\
		ft_lst_del_pieces.c\
		ft_lst_new_piece.c\
		ft_nb_pieces.c\
		ft_place_it.c\
		ft_strsplit_charset.c\

OBJ = $(SRCS:.c=.o)

OBJDIR = obj

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "──────▄▀▄─────▄▀▄  Dragonborns"
	@echo "─────▄█░░▀▀▀▀▀░░█▄      Fillit"
	@echo "─▄▄──█░░░░░░░░░░░█──▄▄─"
	@echo "█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█"
	@echo "***********************"
	@echo "Compilation in progress"
	@echo "***********************"
	@mkdir obj 2> /dev/null || true
	@gcc $(FLAGS) -I. -c $(SRCS)
	@mv $(OBJ) $(OBJDIR)
	@make -C Libft/
	@mv Libft/libft.a .
	@gcc $(FLAGS) -o $(NAME) $(addprefix $(OBJDIR)/, $(OBJ)) libft.a
	@echo "  Compilation done !  "
	@echo "Fillit ready for use !"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C Libft/
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting objetcs... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"

fclean: clean
	@rm -f $(NAME)
	@rm -f libft.a
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting Fillit...  Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "                          "
	@tail -39 extern_file.txt

re: fclean all

credits:
	@tail -39 extern_file.txt
