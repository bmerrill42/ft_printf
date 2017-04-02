/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmerrill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:18:43 by bmerrill          #+#    #+#             */
/*   Updated: 2016/11/17 10:25:46 by bmerrill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*assign_char(long n, char *str)
{
	int	c;

	c = n % 10 + '0';
	if (n == 0)
	{
		return (NULL);
	}
	assign_char(n / 10, str);
	while (*str != '\0')
		str++;
	*str = c;
	return (str);
}

static int	digits(long i)
{
	int	r;

	r = 0;
	while (i > 0)
	{
		i /= 10;
		r++;
	}
	return (r);
}

static char	*iszero(void)
{
	char	*zero;

	zero = ft_strnew(1);
	*zero = '0';
	return (zero);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		negative;
	long	copy;

	copy = (long)n;
	negative = 0;
	if (n == 0)
		return (iszero());
	if (copy < 0)
	{
		copy = -copy;
		negative++;
	}
	if (!(str = ft_strnew(digits(copy) + negative)))
		return (NULL);
	if (negative > 0)
		*str++ = '-';
	assign_char(copy, str);
	if (negative != 0)
		--str;
	return (str);
}
