/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:50:23 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 15:14:23 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	cast_length(intmax_t arg, t_optional *options)
{
	if (options->flags & HH_FLAG)
		return ((char)arg);
	if (options->flags & H_FLAG)
		return ((short)arg);
	if (options->flags & LL_FLAG)
		return (arg);
	if (options->flags & L_FLAG)
		return ((long)arg);
	if (options->flags & J_FLAG)
		return ((intmax_t)arg);
	if (options->flags & Z_FLAG)
		return ((size_t)arg);
	else
		return ((int)arg);
}

uintmax_t	cast_length_u(uintmax_t arg, t_optional *options)
{
	if (options->flags & HH_FLAG)
		return ((unsigned char)arg);
	if (options->flags & H_FLAG)
		return ((unsigned short)arg);
	if (options->flags & LL_FLAG)
		return ((unsigned long long)arg);
	if (options->flags & L_FLAG)
		return ((unsigned long)arg);
	if (options->flags & J_FLAG)
		return ((uintmax_t)arg);
	if (options->flags & Z_FLAG)
		return ((size_t)arg);
	else
		return ((unsigned int)arg);
}
