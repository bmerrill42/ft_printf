/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:18:43 by bmerrill          #+#    #+#             */
/*   Updated: 2017/04/05 17:44:59 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	*assign_char(long n, char *str) */
/* { */
/* 	int	c; */

/* 	c = n % 10 + '0'; */
/* 	if (n == 0) */
/* 	{ */
/* 		return (NULL); */
/* 	} */
/* 	assign_char(n / 10, str); */
/* 	while (*str != '\0') */
/* 		str++; */
/* 	*str = c; */
/* 	return (str); */
/* } */

/* static int	digits(long i) */
/* { */
/* 	int	r; */

/* 	r = 0; */
/* 	while (i > 0) */
/* 	{ */
/* 		i /= 10; */
/* 		r++; */
/* 	} */
/* 	return (r); */
/* } */

/* static char	*iszero(void) */
/* { */
/* 	char	*zero; */

/* 	zero = ft_strnew(1); */
/* 	*zero = '0'; */
/* 	return (zero); */
/* } */

/* char		*ft_itoa(unsigned long long n) */
/* { */
/* 	char	*str; */
/* 	int		negative; */
/* 	unsigned long long	copy; */

/* 	copy = n; */
/* 	negative = 0; */
/* 	if (n == 0) */
/* 		return (iszero()); */
/* 	if (copy < 0) */
/* 	{ */
/* 		copy = -copy; */
/* 		negative++; */
/* 	} */
/* 	if (!(str = ft_strnew(digits(copy) + negative))) */
/* 		return (NULL); */
/* 	if (negative > 0) */
/* 		*str++ = '-'; */
/* 	assign_char(copy, str); */
/* 	if (negative != 0) */
/* 		--str; */
/* 	return (str); */
/* } */

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
	if (n < 0)
	{
		neg = 1;
		n = -n;
	}
	size = get_conv_size(n, 10);
	ret = (char*)malloc(sizeof(char) * (size  + neg + 1));
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
