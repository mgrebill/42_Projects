# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 11:40:43 by mgrebill          #+#    #+#              #
#    Updated: 2017/10/14 16:47:13 by mgrebill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libft.a

HEADER =			includes/

SRCS_LIBFT =		ft_memset.c\
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
					ft_strsub_del_str.c\
					ft_strjoin.c\
					ft_strtrim.c\
					ft_strsplit.c\
					ft_itoa.c\
					ft_uitoa.c\
					ft_putchar.c\
					ft_putstr.c\
					ft_putendl.c\
					ft_putnbr.c\
					ft_putunbr.c\
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
					ft_uitoa_base.c\
					ft_atoi_base.c\
					ft_putnbr_base.c\
					ft_putunbr_base.c\
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
					ft_strjoin_del_one.c\
					ft_strjoin_del_two.c\
					ft_strjoin_del_both.c\
					ft_wchartostr.c\
					ft_wstrtostr.c\
					ft_chartostr.c

SRCS_GNL =			get_next_line.c

SRCS_PRINTF =		ft_printf.c\
					ft_dprintf.c\
					ft_replace.c\
					ft_split_format.c\
					ft_split_identifier.c\
					ft_str.c\
					ft_char.c\
					ft_int.c\
					ft_octal.c\
					ft_percent.c\
					ft_udecimal.c\
					ft_hexa.c\
					ft_hexxa.c\
					ft_lint.c\
					ft_loctal.c\
					ft_ludecimal.c\
					ft_pointer.c\
					ft_bin.c\
					ft_wchar.c\
					ft_wstr.c\
					ft_kolor.c\
					ft_flags_sint_conv.c\
					ft_flags_uint_conv.c\
					ft_flags_char_conv.c\
					ft_flags_ptr_conv.c\
					ft_flags_kolor_conv.c\
					ft_sharp.c\
					ft_mfw_sint_conv.c\
					ft_mfw_uint_conv.c\
					ft_mfw_char_conv.c\
					ft_mfw_ptr_conv.c\
					ft_precision_sint_conv.c\
					ft_precision_uint_conv.c\
					ft_precision_char_conv.c\
					ft_precision_ptr_conv.c

SRCSDIR_LIBFT =		srcs_libft

SRCSDIR_GNL =		srcs_gnl

SRCSDIR_PRINTF =	srcs_printf

OBJ =				$(SRCS_LIBFT:.c=.o)\
					$(SRCS_GNL:.c=.o)\
					$(SRCS_PRINTF:.c=.o)

OBJDIR =			obj

FLAGS =				-Wall -Wextra -Wpadded -Werror -O3

all: $(NAME)

$(NAME):
	@mkdir obj 2> /dev/null || true
	@gcc $(FLAGS) -I $(HEADER) -c $(addprefix $(SRCSDIR_LIBFT)/, $(SRCS_LIBFT))
	@gcc $(FLAGS) -I $(HEADER) -c $(addprefix $(SRCSDIR_GNL)/, $(SRCS_GNL))
	@gcc $(FLAGS) -I $(HEADER) -c $(addprefix $(SRCSDIR_PRINTF)/, $(SRCS_PRINTF))
	@mv $(OBJ) $(OBJDIR)
	@ar rc $(NAME) $(addprefix $(OBJDIR)/, $(OBJ))

clean:
	@rm -rf $(OBJDIR)
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting objects... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"

fclean: clean
	@rm -f $(NAME)
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"
	@echo "Deleting library... Done !"
	@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~"

re: fclean all
