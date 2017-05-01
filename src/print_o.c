/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:54:36 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/01 16:40:21 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_o(va_list va, t_optional *options)
{
	uintmax_t	arg;
	char			*ret;

	arg = va_arg(va, uintmax_t);
	arg = cast_length_u(arg, options);
	ret = ft_itoa_base(arg, 8);
	if (options->flags & HASH_FLAG && arg > 0)
		ret = ft_strjoin_fr("0", ret);
	ret = apply_flags_u(options, ret, arg);
	return (ret);
}

char	*print_ou(va_list va, t_optional *options)
{
	char *ret;

	options->flags |= L_FLAG;
	ret = print_o(va, options);
	return (ret);
}
