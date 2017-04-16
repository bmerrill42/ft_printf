/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:49:19 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/16 13:16:58 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <inttypes.h>
#include <wchar.h>
#include <stdarg.h>
#include "../libft/libft.h"
#define FLAG_SIG(x)                                             \
    x == '-' || x == '+' || x == ' ' || x == '#' || x == '0'
#define LENGTH_SIG(x)                               \
    x == 'h' || x == 'l' || x == 'j' || x == 'z'

enum flag {MINUS_FLAG = 0x0001, PLUS_FLAG = 0x0002, SPACE_FLAG = 0x0004, HASH_FLAG = 0x0008, ZERO_FLAG = 0x0010, HH_FLAG = 0x0020, H_FLAG = 0x0040, L_FLAG = 0x0080, LL_FLAG = 0x0100, J_FLAG = 0x0200, Z_FLAG = 0x0400, WIDTH_FLAG = 0x0800, PRECISION_FLAG = 0x1000, C_NULL_FLAG = 0x2000};

typedef unsigned short t_flags;

typedef struct s_optional {
    t_flags flags;
    unsigned int width;
    unsigned int precision;
} t_optional;

typedef struct s_fmt{
    char c;
    char *(*fn)(va_list, t_optional*);

} t_fmt;
char		*ft_strjoin_fbl(char *left, char *right);
char 		*ft_strjoin_fbr(char *left, char *right);
char		*ft_strjoin_fl(char *left, char *right);
char		*ft_strjoin_fr(char *left, char *right);
int			ft_printf(char *fmt, ...);
char		*print_c(va_list va, t_optional *options);
char		*print_d(va_list va, t_optional *options);
char		*print_du(va_list va, t_optional *options);
char		*print_mod(va_list va, t_optional *options);
char		*print_o(va_list va, t_optional *options);
char		*print_p(va_list va, t_optional *options);
char		*print_s(va_list va, t_optional *options);
char		*print_u(va_list va, t_optional *options);
char		*print_x(va_list va, t_optional *options);
char		*print_xu(va_list va, t_optional *options);
char		*print_ou(va_list va, t_optional *options);
char		*padding(int size, char padding_char, int arg_length);
char		*do_width(intmax_t arg, char *ret, t_optional *options);
char		*do_width_u(uintmax_t arg, char *ret, t_optional *options);
char		*apply_flags_u(t_optional *options, char *ret, uintmax_t arg);
void		get_flags(char x, t_optional *options);
void		get_precision(char **str_p, t_optional *options, va_list va);
void		get_width(char **str_p, t_optional *options, va_list va);
void		get_length_flags(char **str_p, t_optional *options);
uintmax_t	cast_length_u(uintmax_t arg, t_optional *options);
intmax_t	cast_length(intmax_t arg, t_optional *options);
char		*apply_flags(t_optional *options, char *ret, intmax_t arg);
#endif
