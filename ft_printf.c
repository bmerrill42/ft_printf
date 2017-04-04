/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:03:46 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/04 15:42:47 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char *print_d(va_list va, t_optional *options)
{
    int arg;
    char *ret;
    int flags;
    flags = ~(options->flags);
    arg = va_arg(va, int);
    ret = ft_itoa_base(arg, 10);
    return (ret);
}

char *print_c(va_list va, t_optional *options)
{
    char *arg;
    int flags;

    arg = (char*)malloc(2);
    flags = ~(options->flags);
    arg[0] = va_arg(va, int);
    arg[1] = '\0';
    return (arg);
}

t_fmt g_fmt_spec[128] = {
//    ['s'] = {'s', print_s},
//    ['S'] = {'S', print_S},
//    ['p'] = {'p', print_p},
    ['d'] = {'d', print_d},
//    ['D'] = {'D', print_D},
    ['i'] = {'i', print_d},
//    ['o'] = {'o', print_o},
//    ['O'] = {'O', print_O},
//    ['u'] = {'u', print_u},
//    ['U'] = {'U', print_U},
//    ['x'] = {'x', print_x},
//    ['X'] = {'X', print_X},
    ['c'] = {'c', print_c},
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

void get_precision(char **str_p, t_optional *options, va_list va)
{
    char atoi_str[12];
    int index;

    index = 0;
    ft_bzero(atoi_str, 12);
    (*str_p)++;
    if (*(*str_p) == '*')
    {
        options->precision = va_arg(va, int);
        options->flags |= PRECISION_FLAG;
        (*str_p)++;
        return ;
    }
    while(ft_isdigit(*(*str_p)))
        atoi_str[index++] = *((*str_p)++);
    options->precision = ft_atoi(atoi_str);
    options->flags |= PRECISION_FLAG;
}

void get_width(char **str_p, t_optional *options, va_list va)
{
    char atoi_str[12];
    int index;

    index = 0;
    ft_bzero(atoi_str, 12);
    if (*(*str_p) == '*')
    {
        options->width = va_arg(va, int);
        options->flags |= WIDTH_FLAG;
        (*str_p)++;
        return ;
    }
    while(ft_isdigit(*(*str_p)))
        atoi_str[index++] = *((*str_p)++);
    options->width = ft_atoi(atoi_str);
    options->flags |= WIDTH_FLAG;
}

void get_length_flags(char **str_p, t_optional *options)
{
    while (LENGTH_SIG(*(*str_p)))
    {
        if (*(*str_p) == 'h' && *(*str_p + 1) == 'h')
        {
            options->flags |= HH_FLAG;
            *str_p += 2;
        }
        if (*(*str_p) == 'h' && *(*str_p + 1) != 'h')
        {
            options->flags |= H_FLAG;
            (*str_p)++;
        }
        if (*(*str_p) == 'l' && *(*str_p + 1) == 'l')
        {
            options->flags |= LL_FLAG;
            *str_p += 2;
        }
        if (*(*str_p) == 'l' && *(*str_p + 1) != 'l')
        {
            options->flags |= L_FLAG;
            (*str_p)++;
        }
        if (*(*str_p) == 'j')
        {
            options->flags |= J_FLAG;
            (*str_p)++;
        }
        if (*(*str_p) == 'z')
        {
            options->flags |= Z_FLAG;
            (*str_p)++;
        }
    }
}

int ft_printf(char *fmt, ...)
{
    va_list va;
    char *c = fmt;
    int printed = 0;
    t_optional optional;
    char *str_f;
    ft_bzero(&optional, sizeof(t_optional));
    va_start(va, fmt);
    while (*c)
    {
        if (*c == '%')
        {
            ++c;

            while(FLAG_SIG(*c))
                get_flags(*c++, &optional);
            if (ft_isdigit(*c) || *c == '*')
                get_width(&c, &optional, va);
            if (*c == '.')
                get_precision(&c, &optional, va);
            if (LENGTH_SIG(*c))
                get_length_flags(&c, &optional);
            str_f = g_fmt_spec[(int) *c++].fn(va, &optional);
            ft_putstr(str_f);
            printed += ft_strlen(str_f);
        }
        else
        {
            ++printed;
            ft_putchar(*c++);
        }
    }
    return printed;
}
