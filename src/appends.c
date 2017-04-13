/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appends.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <bmerrill@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 13:54:54 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/12 18:27:49 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

char *ft_strjoin_fl(char *left, char *right)
{
    char *tmp;
    if (*left)
    {
        tmp = ft_strjoin(left, right);
        ft_strdel(&left);
        left = tmp;
    }
    return (left);
}

char *ft_strjoin_fr(char *left, char *right)
{
    char *tmp;
    if (*right)
    {
        tmp = ft_strjoin(left, right);
        ft_strdel(&right);
        right = tmp;
    }
    return (right);
}
