/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 13:27:47 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/12 19:30:54 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

	index = 0;
	ft_bzero(atoi_str, 12);
	(*str_p)++;
	if (*(*str_p) == '*')
	{
		options->precision = va_arg(va, int);
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

	index = 0;
	ft_bzero(atoi_str, 12);
	if (*(*str_p) == '*')
	{
		options->width = va_arg(va, int);
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
		if (*(*str_p) == 'h' && *(*str_p + 1) == 'h')
		{
			options->flags |= HH_FLAG;
			*str_p += 2;
		}
		if (*(*str_p) == 'h' && *(*str_p + 1) != 'h')
		{
			options->flags |= H_FLAG;
			(*str_p)++;
		}
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
