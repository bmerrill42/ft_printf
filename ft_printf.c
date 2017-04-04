/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:03:46 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/03 17:21:08 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#define print_anything(va,flags,fn,type, ret)   \
    flags = ~flags;                             \
    type arg;                                   \
    arg = va_arg(va,type);                      \
    fn(arg);                                    \
    return(ret)
#define FLAG_SIG(x) \
    x == '-' || x == '+' || x == ' ' || x == '#' || x == '0'

enum flag {MINUS_FLAG = 0x0001, PLUS_FLAG = 0x0002, SPACE_FLAG = 0x0004, HASH_FLAG = 0x0008, ZERO_FLAG = 0x0010, HH_FLAG = 0x0020, H_FLAG = 0x0040, L_FLAG = 0x0080, LL_FLAG = 0x0100, J_FLAG = 0x0200, Z_FLAG = 0x0400, WIDTH_FLAG = 0x0800, PRECISION_FLAG = 0x1000};

typedef struct s_optional {
    unsigned short flags;
    unsigned int width;
    unsigned int precision;
} t_optional;

typedef struct s_fmt{
    char c;
    int (*fn)(va_list, t_optional*);

} t_fmt;



t_fmt fmt_spec[128] = {
//    ['s'] = {'s', print_s},
//    ['S'] = {'S', print_S},
//    ['p'] = {'p', print_p},
//    ['d'] = {'d', print_d},
//    ['D'] = {'D', print_D},
//    ['i'] = {'i', print_i},
//    ['o'] = {'o', print_o},
//    ['O'] = {'O', print_O},
//    ['u'] = {'u', print_u},
//    ['U'] = {'U', print_U},
//    ['x'] = {'x', print_x},
//    ['X'] = {'X', print_X},
//    ['c'] = {'c', print_c},
//    ['C'] = {'C', print_C},
};


void get_flags(char x, t_optional *options)
{
  if (x == '-')
    options->flags |= MINUS_FLAG;
  if (x == '+')
      options->flags |= PLUS_FLAG;
  if (x == ' ')
      options->flags |= SPACE_FLAG;
  if (x == '#')
      options->flags |= HASH_FLAG;
  if (x == '0')
      options->flags |= ZERO_FLAG;
}

void get_precision(char **str_p, t_optional *options)
{
    char atoi_str[12];
    int index;

    index = 0;
    ft_bzero(atoi_str, 12);
    (*str_p)++;
    while(ft_isdigit(*(*str_p)))
        atoi_str[index++] = *((*str_p)++);
    options->precision = ft_atoi(atoi_str);
    options->flags |= PRECISION_FLAG;
}

void get_width(char **str_p, t_optional *options)
{
    char atoi_str[12];
    int index;

    index = 0;
    ft_bzero(atoi_str, 12);
    while(ft_isdigit(*(*str_p)))
        atoi_str[index++] = *((*str_p)++);
    options->width = ft_atoi(atoi_str);
    options->flags |= WIDTH_FLAG;
}

int ft_printf(char *fmt, ...)
{
    va_list va;
    char *c = fmt;
    int printed = 0;
    t_optional optional;

    ft_bzero(&optional, sizeof(t_optional));
    va_start(va, fmt);
    while (*c) {
        if (*c == '%') {
            ++c;
	    while(FLAG_SIG(*c))
            get_flags(*c++, &optional);
        if (ft_isdigit(*c))
            get_width(&c, &optional);
        if (*c == '.')
            get_precision(&c, &optional);
        printed += fmt_spec[(int) *c++].fn(va, &optional);
        } else {
            ++printed;
            ft_putchar(*c++);
        }
    }

    return printed;
}

int main(void)
{
    ft_printf("%+0 #456.615d %s\n", 42, "YES");
}
/* Local Variables: */
/* compile-command: "gcc -Wall -Werror -Wextra -g -L libft/ -lft ft_printf.c" */
/* End: */
