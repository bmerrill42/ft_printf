/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:39:32 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 15:15:00 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_c(va_list va, t_optional *options)
{
	int		arg;
	char	*ret;

	ret = NULL;
	if (options->flags & HASH_FLAG)
		return (ret);
	arg = va_arg(va, int);
	if (arg == 0)
		options->flags |= C_NULL_FLAG;
	ret = ft_strnew(1);
	*ret = arg;
	ret = do_width(1, ret, options);
	return (ret);
}
