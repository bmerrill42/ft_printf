/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:42:28 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 15:15:10 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_d(va_list va, t_optional *options)
{
	intmax_t	arg;
	char		*ret;

	arg = va_arg(va, intmax_t);
	arg = cast_length(arg, options);
	ret = ft_itoa(arg);
	ret = apply_flags(options, ret, arg);
	return (ret);
}
