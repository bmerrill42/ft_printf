/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:10:29 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/11 14:08:13 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_p(va_list va, t_optional *options)
{
	uintmax_t			arg;
	char				*ret;
	t_optional			*opt;
	char 				*tmp;

	opt = options;
	opt += 1;
	arg = (uintmax_t)va_arg(va, void*);
	ret = ft_itoa_base(arg, 16);
	ret = ft_strjoin("0x", ret);
	ret = ft_tolower_str(ret);
	return (ret);
}
