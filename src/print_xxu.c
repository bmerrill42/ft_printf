/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xxu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:52:12 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 15:17:47 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_x(va_list va, t_optional *options)
{
	uintmax_t	arg;
	char		*ret;

	arg = va_arg(va, uintmax_t);
	arg = cast_length_u(arg, options);
	ret = ft_itoa_base(arg, 16);
	ret = ft_tolower_str(ret);
	if ((options->flags & (HASH_FLAG) && arg > 0))
	{
		if (!((options->flags & (WIDTH_FLAG | ZERO_FLAG)) == \
				(WIDTH_FLAG | ZERO_FLAG)) || (options->flags & MINUS_FLAG))
			ret = ft_strjoin("0x", ret);
	}
	ret = apply_flags_u(options, ret, arg);
	if ((options->flags & (ZERO_FLAG | HASH_FLAG | WIDTH_FLAG)) == \
		(ZERO_FLAG | HASH_FLAG | WIDTH_FLAG) && !(options->flags & MINUS_FLAG))
	{
		ret[0] = '0';
		ret[1] = 'x';
	}
	return (ret);
}

char	*print_xu(va_list va, t_optional *options)
{
	uintmax_t	arg;
	char		*ret;

	arg = va_arg(va, uintmax_t);
	arg = cast_length_u(arg, options);
	ret = ft_itoa_base(arg, 16);
	if ((options->flags & (HASH_FLAG) && arg > 0))
	{
		if (!((options->flags & (WIDTH_FLAG | ZERO_FLAG)) == \
				(WIDTH_FLAG | ZERO_FLAG)) || (options->flags & MINUS_FLAG))
			ret = ft_strjoin("0X", ret);
	}
	ret = apply_flags_u(options, ret, arg);
	if ((options->flags & (ZERO_FLAG | HASH_FLAG | WIDTH_FLAG)) == \
		(ZERO_FLAG | HASH_FLAG | WIDTH_FLAG) && !(options->flags & MINUS_FLAG))
	{
		ret[0] = '0';
		ret[1] = 'X';
	}
	return (ret);
}
