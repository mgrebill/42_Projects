/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlaubres <nlaubres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 08:47:06 by nlaubres          #+#    #+#             */
/*   Updated: 2016/11/29 20:33:51 by nlaubres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define BLACK	"\x1B[30m"
# define RED	"\x1B[31m"
# define GREEN 	"\x1B[32m"
# define YELLO 	"\x1B[33m"
# define BLU 	"\x1B[34m"
# define PURPL 	"\x1B[35m"
# define CYAN 	"\x1B[36m"
# define WHITE 	"\x1B[37m"
# define BRED	"\x1B[48;5;1m"
# define BRESET	"\x1B[48;5;0m"
# define BBROWN	"\x1B[48;5;234m"
# define BBLACK	"\x1B[48;5;0m"
# define BGREY	"\x1B[48;5;242m"
# define BBGRY	"\x1B[48;5;238m"
# define CLEAR	"\033[H\033[J"

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

int				ft_memcmp(const void *s1, const void *s2, size_t n);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_islower(int c);
int				ft_isupper(int c);
int				ft_binarysearch(int elem, int *tab, int start, int end);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_itoa(int n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
char			*ft_strtrim(char const *s);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strreverse(char *str);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *big, const char *little);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strnew(size_t size);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_strsplit(char const *s, char c);
void			ft_bubblesort_chararray(char **tab, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_list			*ft_lstnew(void const *content, size_t content_size);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_bzero(void *s, size_t n);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_brealloc(void *ptr, size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			*ft_memalloc(size_t size);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(const char *s, int fd);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			ft_memdel(void **ap);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int nb, int fd);
void			ft_printstrarray(char **array, size_t size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_strclr(char *s);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_printmsg(char *msg, char *color);
void			ft_lstadd(t_list **alst, t_list *new);
int				ft_count_until(char *s, char c);
char			*ft_strdup_until(char *s, char c);
void			ft_print_str_table(char **tab);
void			ft_free_tab_tab(char ***double_tab);
void			ft_print_str_table(char **tab);

#endif
