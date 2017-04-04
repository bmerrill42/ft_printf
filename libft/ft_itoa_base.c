/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 09:08:01 by exam              #+#    #+#             */
/*   Updated: 2017/04/04 10:06:07 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int get_conv_size(int value, int base)
{
	int i;

	i = 0;
	/*DON'T FORGET ZERO*/
	if (value == 0)
		i++;
	while(value)
	{
		value /= base;
		i++;
	}
	return(i);
}

char	*ft_itoa_base(int value, int base)
{
	int size;
	char *ret;
	char neg;
	char *conv = "0123456789ABCDEF";

	if (value == -2147483648)
		return("-2147483648");
	neg = 0;
	if (value < 0)
	{
		neg = 1;
		value = -value;
	}
/* 	get the size */
	size = get_conv_size(value, base);
/* 	malloc */
	ret = (char*)malloc(sizeof(char) * (size + neg) + 1);
/* 	convert to base */
	if (neg)
		ret[0] = '-';
	else
		size--;
	while(size >= 0)
	{
		ret[size--] = conv[value % base];
		value /= base;
	}
	return(ret);
}

int main(void)
{
	char *test = ft_itoa_base(0, 2);
}
