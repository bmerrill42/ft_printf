/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 18:55:47 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/03 19:12:30 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		apply_space(char **draft, intmax_t ref)
{
	int		i;
	char	prefix_char;
	char	*temp;

	prefix_char = ' ';
	i = 0;
	while (!ft_isdigit((*draft)[i]) && (*draft)[i] != '\0')
		i++;
	if ((i > 0 && (*draft)[i - 1] == ' ') || ref < 0)
		return ;
	else
	{
		temp = *draft;
		*draft = ft_strnew(ft_strlen(*draft + 1));
		**draft = prefix_char;
		ft_strcpy(&(*draft)[1], temp);
		ft_memdel((void **)&temp);
	}
	return ;
}
