# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/02 18:06:08 by nlaubres          #+#    #+#              #
#    Updated: 2016/11/30 14:53:48 by nlaubres         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

OBJS	=	  ft_atoi.o \
			  ft_bubblesort_chararray.o \
			  ft_bzero.o \
			  ft_isalnum.o \
			  ft_isalpha.o \
			  ft_isascii.o \
			  ft_isdigit.o \
			  ft_isprint.o \
			  ft_itoa.o \
			  ft_lstadd.o \
			  ft_lstdel.o \
			  ft_lstdelone.o \
			  ft_lstiter.o \
			  ft_lstnew.o \
			  ft_memalloc.o \
			  ft_memccpy.o \
			  ft_memcpy.o \
			  ft_memchr.o \
			  ft_memcmp.o \
			  ft_memdel.o \
			  ft_memmove.o \
			  ft_memset.o \
			  ft_putchar_fd.o \
			  ft_putchar.o \
			  ft_putendl_fd.o \
			  ft_putendl.o \
			  ft_putnbr.o \
			  ft_putnbr_fd.o \
			  ft_putstr.o \
			  ft_putstr_fd.o \
			  ft_strcat.o \
			  ft_strchr.o \
			  ft_strclr.o \
			  ft_strcmp.o \
			  ft_strcpy.o \
			  ft_strdup.o \
			  ft_strequ.o \
			  ft_striter.o \
			  ft_striteri.o \
			  ft_strjoin.o \
			  ft_strlcat.o \
			  ft_strlen.o \
			  ft_strmap.o \
			  ft_strmapi.o \
			  ft_strncat.o \
			  ft_strncmp.o \
			  ft_strncpy.o \
			  ft_strnequ.o \
			  ft_strnew.o \
			  ft_strnstr.o \
			  ft_strrchr.o \
			  ft_strsplit.o \
			  ft_strstr.o \
			  ft_strsub.o \
			  ft_strtrim.o \
			  ft_tolower.o \
			  ft_toupper.o \
			  ft_lstmap.o \
			  ft_printmsg.o \
			  ft_printstrarray.o \
			  ft_strreverse.o \
			  ft_strdel.o \
			  ft_binarysearch.o \
			  ft_brealloc.o \
			  ft_count_until.o \
			  ft_strdup_until.o \
			  ft_free_tab_tab.o \
			  ft_print_str_table.o

SRCS	=	$(OBJS:.o=.c)

PATH	=	.

.PHONY: all fclean re clean

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra $(SRCS) -c -I $(PATH)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f libft.a

re: fclean all
