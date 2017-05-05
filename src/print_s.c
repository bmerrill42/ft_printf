/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:12:13 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/05 16:34:28 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_s(va_list va, t_optional *options)
{
	char	*ret;
	char	*tmp;

	tmp = va_arg(va, char*);
	if (tmp)
		ret = ft_strdup(tmp);
	else
		ret = ft_strdup("(null)");
	if (options->flags & PRECISION_FLAG)
		ret[options->precision] = '\0';
	ret = do_width_u(1, ret, options);
	return (ret);
}
