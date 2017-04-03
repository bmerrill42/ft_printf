/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/11 01:04:19 by bmerrill          #+#    #+#             */
/*   Updated: 2017/03/30 14:32:13 by bmerrill         ###   ########.fr       */
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
  x == '-' || x == '+' || x == ' ' || x == '#' || x == 0

int print_d(va_list va, unsigned char flags)
{
    flags = ~flags;
    int arg = va_arg(va, int);
    ft_putnbr(arg);
    return(2);
}

int print_c(va_list va, unsigned char flags)
{
    print_anything(va, flags, ft_putchar, int, 1);
}

int print_s(va_list va, unsigned char flags)
{
    print_anything(va,flags,ft_putstr,char*, ft_strlen(arg));
}


enum flag {MINUS_FLAG = 1, PLUS_FLAG = 2, SPACE_FLAG = 4, HASH_FLAG = 8, ZERO_FLAG = 16};

typedef struct s_fmt{
    char c;
    int (*fn)(va_list, unsigned char);

} t_fmt;

t_fmt fmt_spec[128] = {
    ['s'] = {'s', print_sm},
//    ['S'] = {'S', print_S},
//    ['p'] = {'p', print_p},
    ['d'] = {'d', print_d},
//    ['D'] = {'D', print_D},
//    ['i'] = {'i', print_i},
//    ['o'] = {'o', print_o},
//    ['O'] = {'O', print_O},
//    ['u'] = {'u', print_u},
//    ['U'] = {'U', print_U},
//    ['x'] = {'x', print_x},
//    ['X'] = {'X', print_X},
    ['c'] = {'c', print_c},
//    ['C'] = {'C', print_C},
};

int get_flags(char x, unsigned char flags)
{
  if ()
    ;
  return (flags);
}

int my_printf(char *fmt, ...)
{
    va_list va;
    char *c = fmt;
    int printed = 0;
    int flags = 0;
    va_start(va, fmt);

    while (*c) {
        if (*c == '%') {
            ++c;
	    while(FLAG_SIG(*c))
	      flags = get_flags(*c++);
            printed += fmt_spec[(int) *c++].fn(va, flags);
        } else {
            ++printed;
            ft_putchar(*c++);
        }
    }

    return printed;
}

int main(void)
{
    my_printf("%d %s\n", 42, "YES");
}
/* Local Variables: */
/* compile-command: "gcc -Wall -Werror -Wextra -g -L libft/ -lft ft_printf.c" */
/* End: */
