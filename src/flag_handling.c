/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:21:12 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/01 16:49:35 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*padding(int size, char padding_char, int arg_length)
{
	char *padding_str;

	if (size > arg_length)
	{
		padding_str = ft_strnew(size - arg_length);
		ft_memset(padding_str, padding_char, size - arg_length);
		return (padding_str);
	}
	return (ft_strnew(0));
}

char	*do_width(intmax_t arg, char *ret, t_optional *options)
{
	if (options->flags & WIDTH_FLAG && options->width > ft_strlen(ret))
	{
		if (options->flags & ZERO_FLAG && !(options->flags & MINUS_FLAG) && \
			!(options->flags & PRECISION_FLAG))
		{
			if ((arg < 0 || options->flags & PLUS_FLAG) && \
				ft_strlen(ret) < options->width)
				ret[0] = '0';
			ret = ft_strjoin_fbr(padding(options->width, '0', ft_strlen(ret)), ret);
			if (arg < 0)
				ret[0] = '-';
			if (options->flags & PLUS_FLAG && arg > 0)
				ret[0] = '+';
		}
		if (options->flags & MINUS_FLAG)
			ret = ft_strjoin_fbl(ret, padding(options->width, ' ', ft_strlen(ret)));
		else
			ret = ft_strjoin_fbr(padding(options->width, ' ', ft_strlen(ret)), ret);
	}
	return (ret);
}

char	*apply_flags(t_optional *options, char *ret, intmax_t arg)
{
	if (options->flags & PRECISION_FLAG)
	{
		if (options->precision == 0 && arg == 0)
			ret = ft_strnew(0);
		if (arg < 0)
			ret[0] = '0';
		ret = ft_strjoin_fbr(padding(options->precision, '0', ft_strlen(ret)), ret);
		if (arg < 0)
			ret = ft_strjoin_fr("-", ret);
	}
	if (options->flags & PLUS_FLAG && arg >= 0)
	{
		if (options->flags & SPACE_FLAG)
			ret[0] = '+';
		else
			ret = ft_strjoin_fr("+", ret);
	}
	ret = do_width(arg, ret, options);
	if (options->flags & SPACE_FLAG && arg > 0)
		ret = ft_strjoin_fr(" ", ret);
	return (ret);
}

char	*do_width_u(uintmax_t arg, char *ret, t_optional *options)
{
	if (options->flags & WIDTH_FLAG && options->width > ft_strlen(ret))
	{
		if (options->flags & ZERO_FLAG && !(options->flags & MINUS_FLAG) && \
			!(options->flags & PRECISION_FLAG))
		{
			if ((options->flags & PLUS_FLAG) && ft_strlen(ret) < options->width)
				ret[0] = '0';
			ret = ft_strjoin_fbr(padding(options->width, '0', ft_strlen(ret)), ret);
			if (options->flags & PLUS_FLAG && arg > 0)
				ret[0] = '+';
		}
		if (options->flags & MINUS_FLAG)
			ret = ft_strjoin_fbl(ret, padding(options->width, ' ', ft_strlen(ret)));
		else
			ret = ft_strjoin_fbr(padding(options->width, ' ', ft_strlen(ret)), ret);
	}
	return (ret);
}

char	*apply_flags_u(t_optional *options, char *ret, uintmax_t arg)
{
	if (options->flags & SPACE_FLAG && ret[0] != '-' && \
		!(options->flags & WIDTH_FLAG))
		ret = ft_strjoin_fr(" ", ret);
	if (options->flags & PRECISION_FLAG)
	{
		if (options->precision == 0 && arg == 0)
			ret = ft_strnew(0);
		ret = ft_strjoin_fbr(padding(options->precision, '0', ft_strlen(ret)), ret);
	}
	ret = do_width_u(arg, ret, options);
	return (ret);
}
