/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:18:43 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/09 00:42:42 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int get_conv_size(long long value, int base)
{
	int i;

	i = 0;
	if (value == 0)
	{
		i++;
		return(i);
	}
	while(value)
	{
		value /= base;
		i++;
	}
	return(i);
}

char	*ft_itoa(long long n)
{
	int size;
	char *ret;
	int neg;
	char *conv = "0123456789";

	neg = 0;
	if (n == -9223372036854775808)
		return ("-9223372036854775808");
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	size = get_conv_size(n, 10);
	ret = ft_strnew(size + neg);
	if (neg)
		size++;
	while(size >= 0)
	{
		ret[--size] = conv[n % 10];
		n /= 10;
	}
	if (neg)
		ret[0] = '-';
	return(ret);
}
