/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:54:36 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 15:17:37 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_o(va_list va, t_optional *options)
{
	unsigned int	arg;
	char			*ret;

	arg = va_arg(va, unsigned int);
	arg = cast_length_u(arg, options);
	ret = ft_itoa_base(arg, 8);
	if (options->flags & HASH_FLAG)
		ret = ft_strjoin("0", ret);
	ret = apply_flags_u(options, ret, arg);
	if (options->flags & HASH_FLAG && options->width == 0)
		ret = ft_strjoin("0", ret);
	return (ret);
}

char	*print_ou(va_list va, t_optional *options)
{
	unsigned long long	arg;
	char				*ret;

	arg = va_arg(va, int);
	ret = ft_itoa_base(arg, 8);
	ret = apply_flags_u(options, ret, arg);
	return (ret);
}
