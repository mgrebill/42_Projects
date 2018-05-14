/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrebill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:19:24 by mgrebill          #+#    #+#             */
/*   Updated: 2017/09/08 12:42:08 by mgrebill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <locale.h>

typedef struct			s_flags
{
	bool				minus;
	bool				zero;
	bool				plus;
	bool				blank;
	bool				sharp;
	bool				quote;
}						t_flags;

typedef struct			s_modifiers
{
	bool				hh;
	bool				h;
	bool				l;
	bool				ll;
	bool				z;
	bool				j;
}						t_modifiers;

typedef struct			s_id
{
	t_flags				flags;
	size_t				mfw;
	bool				dot;
	size_t				precision;
	t_modifiers			modifiers;
	char				type;
}						t_id;

typedef struct			s_lst_pf
{
	size_t				size;
	char				*str;
	struct s_lst_pf		*next;
}						t_lst_pf;

typedef struct			s_ft
{
	char				c;
	char				*(*ft)(t_id *id, va_list *ap);
	char				*(*flags)(t_id *id, char *str);
}						t_ft;

int						ft_printf(const char *format, ...);
t_lst_pf				*ft_split_format(const char *format);
t_id					ft_split_identifier(char *str);
char					*ft_str(t_id *id, va_list *ap);
char					*ft_char(t_id *id, va_list *ap);
char					*ft_int(t_id *id, va_list *ap);
char					*ft_octal(t_id *id, va_list *ap);
char					*ft_percent(t_id *id, va_list *ap);
char					*ft_udecimal(t_id *id, va_list *ap);
char					*ft_hexa(t_id *id, va_list *ap);
char					*ft_hexxa(t_id *id, va_list *ap);
char					*ft_lint(t_id *id, va_list *ap);
char					*ft_loctal(t_id *id, va_list *ap);
char					*ft_ludecimal(t_id *id, va_list *ap);
char					*ft_pointer(t_id *id, va_list *ap);
char					*ft_bin(t_id *id, va_list *ap);
char					*ft_wchar(t_id *id, va_list *ap);
char					*ft_wstr(t_id *id, va_list *ap);
char					*ft_kolor(t_id *id, va_list *ap);
char					*ft_flags_sint_conv(t_id *id, char *str);
char					*ft_flags_uint_conv(t_id *id, char *str);
char					*ft_flags_char_conv(t_id *id, char *str);
char					*ft_flags_ptr_conv(t_id *id, char *str);
char					*ft_flags_kolor_conv(t_id *id, char *str);
char					*ft_sharp(t_id id);
char					*ft_mfw_sint_conv(t_id id, char *str);
char					*ft_mfw_uint_conv(t_id id, char *str);
char					*ft_mfw_char_conv(t_id id, char *str);
char					*ft_mfw_ptr_conv(t_id id, char *str);
char					*ft_precision_sint_conv(t_id id, char *str);
char					*ft_precision_uint_conv(t_id id, char *str);
char					*ft_precision_char_conv(t_id id, char *str);
char					*ft_precision_ptr_conv(t_id id, char *str);
#endif
