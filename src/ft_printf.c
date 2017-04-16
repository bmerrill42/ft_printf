/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:48:59 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/16 13:53:11 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_fmt g_fmt_spec[128] = {
	['s'] = {'s', print_s},
	['S'] = {'S', print_s},
	['p'] = {'p', print_p},
	['d'] = {'d', print_d},
	['D'] = {'D', print_du},
	['i'] = {'i', print_d},
	['o'] = {'o', print_o},
	['O'] = {'O', print_ou},
	['u'] = {'u', print_u},
	['U'] = {'U', print_u},
	['x'] = {'x', print_x},
	['X'] = {'X', print_xu},
	['c'] = {'c', print_c},
	['C'] = {'C', print_c},
	['%'] = {'%', print_mod}
};

char	*do_work(int *printed, va_list va, char *copy, t_optional optional)
{
	char		*str_f;

	str_f = NULL;
	++copy;
	while (FLAG_SIG(*copy))
		get_flags(*copy++, &optional);
	if (ft_isdigit(*copy) || *copy == '*')
		get_width(&copy, &optional, va);
	if (*copy == '.')
		get_precision(&copy, &optional, va);
	if (LENGTH_SIG(*copy))
		get_length_flags(&copy, &optional);
	if (g_fmt_spec[(int)*copy].c)
		str_f = g_fmt_spec[(int)*copy++].fn(va, &optional);
	if (!str_f)
		str_f = ft_strdup("(null)");
	ft_putstr(str_f);
	if (optional.flags & C_NULL_FLAG)
		*printed += 1;
	*printed += ft_strlen(str_f);
	if (*str_f)
		ft_strdel(&str_f);
	return (copy);
}

int		ft_printf(char *fmt, ...)
{
	va_list		va;
	char		*copy;
	int			printed;
	t_optional	optional;

	copy = fmt;
	printed = 0;
	ft_bzero(&optional, sizeof(t_optional));
	va_start(va, fmt);
	while (*copy)
	{
		if (*copy == '%')
			copy = do_work(&printed, va, copy, optional);
		else
		{
			++printed;
			ft_putchar(*copy++);
		}
	}
	return (printed);
}
