/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appends.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:54:54 by bmerrill          #+#    #+#             */
/*   Updated: 2017/05/03 16:27:38 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char	*ft_strjoin_fl(char *left, char *right)
{
	char *tmp;

	if (*left || *right == ' ')
	{
		tmp = ft_strjoin(left, right);
		if (*left)
			ft_strdel(&left);
		left = tmp;
	}
	return (left);
}

char	*ft_strjoin_fr(char *left, char *right)
{
	char *tmp;

	if (*right || *left == ' ')
	{
		tmp = ft_strjoin(left, right);
		if (*right)
			ft_strdel(&right);
		right = tmp;
	}
	return (right);
}

char	*ft_strjoin_fbr(char *left, char *right)
{
	char *tmp;

	if (*right || *left == ' ')
	{
		tmp = ft_strjoin(left, right);
		if (*right)
			ft_strdel(&right);
		if (*left)
			ft_strdel(&left);
		right = tmp;
	}
	return (right);
}

char	*ft_strjoin_fbl(char *left, char *right)
{
	char *tmp;

	if (*left || *left == ' ')
	{
		tmp = ft_strjoin(left, right);
		if (*right)
			ft_strdel(&right);
		if (*left)
			ft_strdel(&left);
		left = tmp;
	}
	return (left);
}
