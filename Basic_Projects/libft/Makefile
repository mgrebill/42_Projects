# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:40:43 by mgrebill          #+#    #+#              #
#    Updated: 2016/11/21 17:56:22 by mgrebill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = libft.h

SRCS =	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_itoa.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_itoa_base.c\
		ft_atoi_base.c\
		ft_putnbr_base.c\
		ft_putchar_error.c\
		ft_putstr_error.c\
		ft_putendl_error.c\
		ft_putnbr_error.c\
		ft_swap_int.c\
		ft_sort_int_table.c\
		ft_print_int_table.c\
		ft_swap_str.c\
		ft_sort_str_table.c\
		ft_print_str_table.c\

OBJ = $(SRCS:.c=.o)

OBJDIR = obj

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@echo "──────▄▀▄─────▄▀▄  Mgrebill's"
	@echo "─────▄█░░▀▀▀▀▀░░█▄      Libft"
	@echo "─▄▄──█░░░░░░░░░░░█──▄▄─"
	@echo "█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█"
	@echo "***********************"
	@echo "Compilation in progress"
	@echo "***********************"
	@mkdir obj
	@gcc $(FLAGS) -I $(HEADER) -c $(SRCS)
	@mv $(OBJ) $(OBJDIR)
	@ar rc $(NAME) $(addprefix $(OBJDIR)/, $(OBJ))
	@echo "  Compilation done !   "
	@echo " Libft ready for use ! "

clean:
	@rm -rf $(OBJDIR)
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting objetcs... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"

fclean: clean
	@rm -f $(NAME)
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting library... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"

re: fclean all
