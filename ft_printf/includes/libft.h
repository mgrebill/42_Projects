/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:34:01 by mgrebill          #+#    #+#             */
/*   Updated: 2017/07/29 18:58:59 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <wchar.h>
# define BLACK	"\x1B[30m"
# define RED	"\x1B[31m"
# define GREEN	"\x1B[32m"
# define YELLO	"\x1B[33m"
# define BLU	"\x1B[34m"
# define PURPL	"\x1B[35m"
# define CYAN	"\x1B[36m"
# define WHITE	"\x1B[37m"
# define BRED	"\x1B[48;5;1m"
# define BRESET	"\x1B[48;5;0m"
# define BBROWN	"\x1B[48;5;234m"
# define BBLACK	"\x1B[48;5;0m"
# define BGREY	"\x1B[48;5;242m"
# define BBGRY	"\x1B[48;5;238m"
# define CLEAR	"\033[H\033[J"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *big, const char *lil);
char				*ft_strnstr(const char *big, const char *lil, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
intmax_t			ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsub_del_str(char *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(intmax_t n);
char				*ft_uitoa(uintmax_t n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(intmax_t n);
void				ft_putunbr(uintmax_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(intmax_t n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_itoa_base(intmax_t n, int base);
char				*ft_uitoa_base(uintmax_t n, int base);
intmax_t			ft_atoi_base(char const *s, int base);
void				ft_putnbr_base(intmax_t n, int base);
void				ft_putunbr_base(uintmax_t n, int base);
void				ft_putchar_error(char c);
void				ft_putstr_error(char const *s);
void				ft_putendl_error(char const *s);
void				ft_putnbr_error(intmax_t n);
void				ft_swap_int(int *a, int *b);
void				ft_sort_int_table(int *tab);
void				ft_print_int_table(int *tab);
void				ft_swap_str(char *s1, char *s2);
void				ft_sort_str_table(char **tab);
void				ft_print_str_table(char **tab);
char				*ft_strjoin_del_one(char const *s1, char const *s2);
char				*ft_strjoin_del_two(char const *s1, char const *s2);
char				*ft_strjoin_del_both(char const *s1, char const *s2);
char				*ft_wchartostr(wchar_t wc);
char				*ft_wstrtostr(wchar_t *ws);
char				*ft_chartostr(char c);
#endif
