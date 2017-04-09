/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:13:22 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 15:17:45 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_u(va_list va, t_optional *options)
{
	uintmax_t	arg;
	char		*ret;

	arg = va_arg(va, uintmax_t);
	arg = cast_length_u(arg, options);
	ret = ft_itoa_u(arg);
	if (options->flags & SPACE_FLAG)
		options->flags ^= SPACE_FLAG;
	ret = apply_flags_u(options, ret, arg);
	return (ret);
}
