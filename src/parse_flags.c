/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:27:47 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/03 17:41:27 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#define CHECK(a, b, c) while(1){if(a){options->flags |= b;c;}break;}

void	get_flags(char x, t_optional *options)
{
	if (x == '-')
		options->flags |= MINUS_FLAG;
	if (x == '+')
		options->flags |= PLUS_FLAG;
	if (x == ' ')
		options->flags |= SPACE_FLAG;
	if (x == '#')
		options->flags |= HASH_FLAG;
	if (x == '0')
		options->flags |= ZERO_FLAG;
}

void	get_precision(char **str_p, t_optional *options, va_list va)
{
	char	atoi_str[12];
	int		index;
	int		star;

	star = 0;
	index = 0;
	ft_bzero(atoi_str, 12);
	(*str_p)++;
	if (*(*str_p) == '*')
	{
		star = va_arg(va, int);
		options->precision = star;
		options->flags |= PRECISION_FLAG;
		(*str_p)++;
		return ;
	}
	while (ft_isdigit(*(*str_p)))
		atoi_str[index++] = *((*str_p)++);
	options->precision = ft_atoi(atoi_str);
	options->flags |= PRECISION_FLAG;
}

void	get_width(char **str_p, t_optional *options, va_list va)
{
	char	atoi_str[12];
	int		index;
	int		star;

	index = 0;
	ft_bzero(atoi_str, 12);
	if (*(*str_p) == '*')
	{
		star = va_arg(va, int);
		options->width = star;
		options->flags |= WIDTH_FLAG;
		(*str_p)++;
		return ;
	}
	while (ft_isdigit(*(*str_p)))
		atoi_str[index++] = *((*str_p)++);
	options->width = ft_atoi(atoi_str);
	options->flags |= WIDTH_FLAG;
}

void	get_length_flags(char **str_p, t_optional *options)
{
	while (LENGTH_SIG(*(*str_p)))
	{
		CHECK(*(*str_p) == 'h' && *(*str_p + 1) == 'h', HH_FLAG, *str_p += 2);
		CHECK(*(*str_p) == 'h' && *(*str_p + 1) != 'h', H_FLAG, (*str_p)++);
		if (*(*str_p) == 'l' && *(*str_p + 1) == 'l')
		{
			options->flags |= LL_FLAG;
			*str_p += 2;
		}
		if (*(*str_p) == 'l' && *(*str_p + 1) != 'l')
		{
			options->flags |= L_FLAG;
			(*str_p)++;
		}
		if (*(*str_p) == 'j')
		{
			options->flags |= J_FLAG;
			(*str_p)++;
		}
		if (*(*str_p) == 'z')
		{
			options->flags |= Z_FLAG;
			(*str_p)++;
		}
	}
}
