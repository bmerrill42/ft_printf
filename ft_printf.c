/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:03:46 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/08 23:34:37 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"
#include <inttypes.h>
#include <wchar.h>

long long cast_length( long long arg, t_optional *options)
{
    if (options->flags & HH_FLAG)
        return((char)arg);
    if (options->flags & H_FLAG)
        return((short)arg);
    if (options->flags & LL_FLAG)
        return(arg);
    if (options->flags & L_FLAG)
        return((long)arg);
    if (options->flags & J_FLAG)
        return((intmax_t)arg);
    if (options->flags & Z_FLAG)
        return((size_t)arg);
    else
        return((int)arg);
}

unsigned long long cast_length_u(unsigned long long arg, t_optional *options)
{
    if (options->flags & HH_FLAG)
        return((unsigned char)arg);
    if (options->flags & H_FLAG)
        return((unsigned short)arg);
    if (options->flags & LL_FLAG)
        return(arg);
    if (options->flags & L_FLAG)
        return((unsigned long)arg);
    if (options->flags & J_FLAG)
        return((uintmax_t)arg);
    if (options->flags & Z_FLAG)
        return((size_t)arg);
    else
        return((unsigned int)arg);
}

char		*ft_tolower_str(char *str)
{
	char	*temp;

	temp = str;
	while (*temp != '\0')
        {
            if (*temp >= 65 && *temp <= 90)
                *temp += 32;
            temp++;
        }
	return (str);
}
char *padding(int size, char padding_char, int arg_length)
{
    char *padding_str;

    if (size > arg_length)
        {
            padding_str = ft_strnew(size - arg_length);
            ft_memset(padding_str, padding_char, size - arg_length);
            return(padding_str);
        }
    return("");
}

char *do_width(long long arg, char *ret, t_optional* options) {
    if (options->flags & WIDTH_FLAG && options->width > ft_strlen(ret))
        {
            if (options->flags & ZERO_FLAG && !(options->flags & MINUS_FLAG) && !(options->flags & PRECISION_FLAG))
                {
                    if ((arg < 0 || options->flags & PLUS_FLAG) && ft_strlen(ret) < options->width)
                        ret[0] = '0';
                    ret = ft_strjoin(padding(options->width, '0', ft_strlen(ret)), ret);
                    if (arg < 0)
                        ret[0] = '-';
                    if (options->flags & PLUS_FLAG && arg > 0)
                        ret[0] = '+';
                }
            if (options->flags & MINUS_FLAG)
                ret = ft_strjoin(ret, padding(options->width, ' ', ft_strlen(ret)));
            else
                ret = ft_strjoin(padding(options->width, ' ', ft_strlen(ret)), ret);
        }
    return (ret);
}

char *apply_flags(t_optional *options, char *ret, long long arg)
{
    if (options->flags & SPACE_FLAG && (ret[0] != '-') && !(options->flags & WIDTH_FLAG))
        ret = ft_strjoin(" ", ret);
    if (options->flags & PRECISION_FLAG)
        {
            if (options->precision == 0 && arg == 0)
                ret = "";
            if (arg < 0)
                ret[0] = '0';
            ret = ft_strjoin(padding(options->precision, '0', ft_strlen(ret)), ret);
            if (arg < 0)
                ret = ft_strjoin("-", ret);
        }
    if (options->flags & PLUS_FLAG && arg >= 0)
        {
            if (options->flags & SPACE_FLAG)
                ret[0] = '+';
            else
                ret = ft_strjoin("+", ret);
        }
    ret = do_width(arg, ret, options);
    return (ret);
}
char *do_width_u(unsigned long long arg, char *ret, t_optional* options)
{
    if (options->flags & WIDTH_FLAG && options->width > ft_strlen(ret))
        {
            if (options->flags & ZERO_FLAG && !(options->flags & MINUS_FLAG) && !(options->flags & PRECISION_FLAG))
                {
                    if ((options->flags & PLUS_FLAG) && ft_strlen(ret) < options->width)
                        ret[0] = '0';
                    ret = ft_strjoin(padding(options->width, '0', ft_strlen(ret)), ret);
                    if (options->flags & PLUS_FLAG && arg > 0)
                        ret[0] = '+';
                }
            if (options->flags & MINUS_FLAG)
                ret = ft_strjoin(ret, padding(options->width, ' ', ft_strlen(ret)));
            else
                ret = ft_strjoin(padding(options->width, ' ', ft_strlen(ret)), ret);
        }
    return (ret);
}

char *apply_flags_u(t_optional *options, char *ret, unsigned long long arg)
{
    if (options->flags & SPACE_FLAG && ret[0] != '-' && !(options->flags & WIDTH_FLAG))
        ret = ft_strjoin(" ", ret);
    if (options->flags & PRECISION_FLAG)
        {
            if (options->precision == 0 && arg == 0)
                ret = "";
            ret = ft_strjoin(padding(options->precision, '0', ft_strlen(ret)), ret);
        }
    ret = do_width_u(arg, ret, options);
    return (ret);
}

char *print_o(va_list va, t_optional *options)
{
    unsigned long long arg;
    char *ret;

    arg = va_arg(va, unsigned long long);
    arg = cast_length(arg, options);
    ret = ft_itoa_base(arg, 8);
    if (options->flags & HASH_FLAG)
        ret = ft_strjoin("0", ret);
    ret = apply_flags_u(options, ret, arg);
    if (options->flags & HASH_FLAG && options->width == 0)
        ret = ft_strjoin("0", ret);
    return (ret);
}

char *print_x(va_list va, t_optional *options)
{
    unsigned long long arg;
    char *ret;

    arg = va_arg(va, unsigned long long);
    arg = cast_length_u(arg, options);
    ret = ft_itoa_base(arg, 16);
    ret = ft_tolower_str(ret);
    if ((options->flags & (HASH_FLAG) && arg > 0))
        {
            if (!((options-> flags & (WIDTH_FLAG | ZERO_FLAG)) == (WIDTH_FLAG | ZERO_FLAG)) || (options->flags & MINUS_FLAG))
                ret = ft_strjoin("0x", ret);
        }
    ret = apply_flags_u(options, ret, arg);
    if ((options->flags & (ZERO_FLAG | HASH_FLAG | WIDTH_FLAG)) == (ZERO_FLAG | HASH_FLAG | WIDTH_FLAG) && !(options->flags & MINUS_FLAG))
        {
            ret[0] = '0';
            ret[1] = 'x';
        }
    return (ret);
}

char *print_X(va_list va, t_optional *options)
{
    unsigned long long arg;
    char *ret;

    arg = va_arg(va, unsigned long long);
    arg = cast_length_u(arg, options);
    ret = ft_itoa_base(arg, 16);
    if ((options->flags & (HASH_FLAG) && arg > 0))
        {
            if (!((options-> flags & (WIDTH_FLAG | ZERO_FLAG)) == (WIDTH_FLAG | ZERO_FLAG)) || (options->flags & MINUS_FLAG))
                ret = ft_strjoin("0X", ret);
        }
    ret = apply_flags_u(options, ret, arg);
    if ((options->flags & (ZERO_FLAG | HASH_FLAG | WIDTH_FLAG)) == (ZERO_FLAG | HASH_FLAG | WIDTH_FLAG) && !(options->flags & MINUS_FLAG))
        {
            ret[0] = '0';
            ret[1] = 'X';
        }
    return (ret);
}

char *print_O(va_list va, t_optional *options)
{
    unsigned long long arg;
    char *ret;

    arg = va_arg(va, int);
    ret = ft_itoa_base(arg, 8);
    ret = apply_flags_u(options, ret, arg);
    return (ret);
}

char *print_u(va_list va, t_optional *options)
{
    unsigned long arg;
    char *ret;

    arg = va_arg(va, unsigned long);
    arg = cast_length_u(arg, options);
    ret = ft_itoa_u(arg);
    if (options->flags & SPACE_FLAG)
        options->flags ^= SPACE_FLAG;
    ret = apply_flags_u(options, ret, arg);
    return (ret);
}

char *print_d(va_list va, t_optional *options)
{
    long long arg;
    char *ret;

    arg = va_arg(va,long long);
    arg = cast_length(arg, options);
    ret = ft_itoa(arg);
    ret = apply_flags(options, ret, arg);
    return (ret);
}

char *print_mod(va_list va, t_optional *options)
{
    char *ret;
    va = NULL;
    va++;
    ret = "%";
    if (options->flags & SPACE_FLAG)
        options->flags ^= SPACE_FLAG;
    if (options->flags & PRECISION_FLAG)
        options->flags ^= PRECISION_FLAG;
    ret = apply_flags(options, ret, 1);
    return (ret);
}

char *print_s(va_list va, t_optional *options)
{
    char *ret;
    ret = va_arg(va, char*);
    if (options->flags & PRECISION_FLAG)
        ret[options->precision] = '\0';
    ret = do_width_u(1, ret, options);
    return(ret);
}

char *print_c(va_list va, t_optional *options)
{
    int arg;
    int size;
    char *ret;

    size = 1;
    arg = va_arg(va, int);
    if (options->width > 0)
        size = options->width;
    ret = (char*)malloc(size);
    ft_memset(ret, ' ', size);
    if (!(options->flags & MINUS_FLAG))
        ret[size - 1] = arg;
    else
        ret[0] = arg;
    ret[size] = '\0';
    return (ret);
}

t_fmt g_fmt_spec[128] = {
    ['s'] = {'s', print_s},
    ['S'] = {'S', print_s},
    //    ['p'] = {'p', print_p},
    ['d'] = {'d', print_d},
    ['D'] = {'D', print_d},
    ['i'] = {'i', print_d},
    ['o'] = {'o', print_o},
    ['O'] = {'O', print_O},
    ['u'] = {'u', print_u},
    //    ['U'] = {'U', print_U},
    ['x'] = {'x', print_x},
    ['X'] = {'X', print_X},
    ['c'] = {'c', print_c},
    ['C'] = {'C', print_c},
    ['%'] = {'%', print_mod}
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

char *do_work(char *str_f, int *printed, va_list va, char *copy, t_optional optional)
{
    ++copy;
    while(FLAG_SIG(*copy))
        get_flags(*copy++, &optional);
    if (ft_isdigit(*copy) || *copy == '*')
        get_width(&copy, &optional, va);
    if (*copy == '.')
        get_precision(&copy, &optional, va);
    if (LENGTH_SIG(*copy))
        get_length_flags(&copy, &optional);
    str_f = g_fmt_spec[(int) *copy++].fn(va, &optional);
    if (!str_f)
        ft_putstr("(null)");
    else
        ft_putstr(str_f);
    *printed += ft_strlen(str_f);
    return (copy);
}

int ft_printf(char *fmt, ...)
{
    va_list va;
    char *copy = fmt;
    int printed = 0;
    t_optional optional;
    char *str_f;
    str_f = NULL;
    ft_bzero(&optional, sizeof(t_optional));
    va_start(va, fmt);
    while (*copy)
        {
            if (*copy == '%')
                copy = do_work(str_f, &printed, va, copy, optional);
            else
                {
                    ++printed;
                    ft_putchar(*copy++);
                }
        }
    return printed;
}
