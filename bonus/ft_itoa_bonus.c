/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:53:16 by oholgado          #+#    #+#             */
/*   Updated: 2021/11/17 18:59:17 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <unistd.h>
#include <stdlib.h>

static char	*ft_fill_char(char *buff, size_t len, long n, size_t neg)
{
	buff[len + neg] = '\0';
	while (len)
	{
		len--;
		buff[len + neg] = n % 10 + '0';
		n /= 10;
	}
	if (neg == 1)
		buff[0] = '-';
	return (buff);
}

static size_t	len_int(long n, size_t len)
{
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char		*buff;
	size_t		len;
	size_t		neg;
	long		nb;

	neg = 0;
	len = 0;
	nb = (long)n;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	len = len_int(nb, len);
	buff = malloc((len + 1 + neg) * sizeof(char));
	if (!buff)
		return (0);
	buff = ft_fill_char(buff, len, nb, neg);
	return (buff);
}
