# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrebill <mgrebill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:40:43 by mgrebill          #+#    #+#              #
#    Updated: 2017/10/11 12:42:20 by mgrebill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 =		push_swap

NAME2 =		checker

SRCS =		ft_param_to_stack.c\
			ft_stdin_to_lst_cmd.c\
			cmd.c\
			ft_push_half.c\
			ft_push_mediane.c\
			ft_stackndup.c\
			ft_stackalloc.c\
			ft_stackdel.c\
			ft_quick_sort.c\
			ft_check_stack.c\
			ft_find_mediane.c\
			ft_new_cmd.c\
			ft_optimize_lst_cmd.c\
			ft_little_swap.c\
			ft_sort_three.c\
			ft_sort_five.c\
			ft_print_stacks.c\
			ft_free_stacks.c

MAINS =		main_pushswap.c\
			main_checker.c\

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

all: $(NAME1)

$(NAME1):
	@echo "──────▄▀▄─────▄▀▄  Mgrebill's"
	@echo "─────▄█░░▀▀▀▀▀░░█▄  Push_Swap"
	@echo "─▄▄──█░░░░░░░░░░░█──▄▄─"
	@echo "█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█"
	@echo "***********************"
	@echo "Compilation in progress"
	@echo "***********************"
	@mkdir obj 2> /dev/null || true
	@gcc $(CFLAGS) -I $(INCLUDES) -c $(addprefix $(SRCSDIR)/, $(SRCS))
	@gcc $(CFLAGS) -I $(INCLUDES) -c $(addprefix $(SRCSDIR)/, $(MAINS))
	@mv $(OBJ) $(OBJDIR)
	@mv $(MAINS:.c=.o) $(OBJDIR)
	@make -C libft/
	@mv libft/libft.a .
	@gcc $(CFLAGS) -o $(NAME1) $(addprefix $(OBJDIR)/, $(OBJ)) obj/main_pushswap.o libft.a
	@gcc $(CFLAGS) -o $(NAME2) $(addprefix $(OBJDIR)/, $(OBJ)) obj/main_checker.o libft.a
	@echo "   Compilation done !    "
	@echo "Push_swap ready for use !"

clean:
	@rm -rf $(OBJDIR)
	@make clean -C libft/
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting objetcs... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "                          "

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@rm -f libft.a
	@rm -f push_swap.log
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting Push_swap...  Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "                             "

re: fclean all
