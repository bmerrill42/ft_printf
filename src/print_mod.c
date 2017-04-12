/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:52:56 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/12 16:15:23 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_mod(va_list va, t_optional *options)
{
	char	*ret;

	va = NULL;
	va++;
	ret = ft_strnew(1);
	*ret = '%';
	if (options->flags & SPACE_FLAG)
		options->flags ^= SPACE_FLAG;
	if (options->flags & PRECISION_FLAG)
		options->flags ^= PRECISION_FLAG;
	ret = apply_flags(options, ret, 1);
	return (ret);
}
