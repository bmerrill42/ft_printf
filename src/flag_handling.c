/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 14:21:12 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/12 12:47:57 by bmerrill         ###   ########.fr       */
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
	return ("");
}

char	*do_width(long long arg, char *ret, t_optional *options)
{
	char *tmp;

	if (options->flags & WIDTH_FLAG && options->width > ft_strlen(ret))
	{
		if (options->flags & ZERO_FLAG && !(options->flags & MINUS_FLAG) && \
			!(options->flags & PRECISION_FLAG))
		{
			if ((arg < 0 || options->flags & PLUS_FLAG) && \
				ft_strlen(ret) < options->width)
				ret[0] = '0';
			tmp = ret;
			ret = ft_strjoin(padding(options->width, '0', ft_strlen(ret)), ret);
			free(tmp);
			if (arg < 0)
				ret[0] = '-';
			if (options->flags & PLUS_FLAG && arg > 0)
				ret[0] = '+';
		}
		if (options->flags & MINUS_FLAG)
		{
			tmp = ret;
			ret = ft_strjoin(ret, padding(options->width, ' ', ft_strlen(ret)));
			free(tmp);
		}
		else
		{
			tmp = ret;
			ret = ft_strjoin(padding(options->width, ' ', ft_strlen(ret)), ret);
			free(tmp);
		}
	}
	return (ret);
}

char	*apply_flags(t_optional *options, char *ret, long long arg)
{
	char *tmp;

	if (options->flags & SPACE_FLAG && (ret[0] != '-') && \
		!(options->flags & WIDTH_FLAG))
		ret = ft_strjoin(" ", ret);
	if (options->flags & PRECISION_FLAG)
	{
		if (options->precision == 0 && arg == 0)
			ret = "";
		if (arg < 0)
			ret[0] = '0';
		tmp = ret;
		ret = ft_strjoin(padding(options->precision, '0', ft_strlen(ret)), ret);
		free(tmp);
		if (arg < 0)
			ret = ft_strjoin("-", ret);
	}
	if (options->flags & PLUS_FLAG && arg >= 0)
	{
		if (options->flags & SPACE_FLAG)
			ret[0] = '+';
		else
		{
			tmp = ret;
			ret = ft_strjoin("+", ret);
			free(tmp);
		}
	}
	ret = do_width(arg, ret, options);
	return (ret);
}

char	*do_width_u(unsigned long long arg, char *ret, t_optional *options)
{
	if (options->flags & WIDTH_FLAG && options->width > ft_strlen(ret))
	{
		if (options->flags & ZERO_FLAG && !(options->flags & MINUS_FLAG) && \
			!(options->flags & PRECISION_FLAG))
		{
			if ((options->flags & PLUS_FLAG) && ft_strlen(ret) < options->width)
				ret[0] = '0';
			ret = ft_strjoin(padding(options->width, '0', ft_strlen(ret)), ret);
			if (options->flags & PLUS_FLAG && arg > 0)
				ret[0] = '+';
		}
		if (options->flags & MINUS_FLAG)
			ret = ft_strjoin(ret, padding(options->width, ' ', ft_strlen(ret)));
		else
			ret = ft_strjoin(padding(options->width, ' ', ft_strlen(ret)), ret);
	}
	return (ret);
}

char	*apply_flags_u(t_optional *options, char *ret, unsigned long long arg)
{
	if (options->flags & SPACE_FLAG && ret[0] != '-' && \
		!(options->flags & WIDTH_FLAG))
		ret = ft_strjoin(" ", ret);
	if (options->flags & PRECISION_FLAG)
	{
		if (options->precision == 0 && arg == 0)
			ret = "";
		ret = ft_strjoin(padding(options->precision, '0', ft_strlen(ret)), ret);
	}
	ret = do_width_u(arg, ret, options);
	return (ret);
}
