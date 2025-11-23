/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 15:01:09 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 15:02:13 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	nbrlen(long n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*getnbrstr(long n, size_t nlen, int sign)
{
	char	*res;

	res = (char *)malloc(nlen + 1 + sign);
	if (!res)
		return (NULL);
	res[nlen + sign] = '\0';
	while (nlen > 0)
	{
		res[nlen - 1 + sign] = (n % 10) + '0';
		n /= 10;
		nlen--;
	}
	if (sign)
		res[0] = '-';
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nbr;
	int		sign;
	size_t	nlen;

	nbr = (long)n;
	sign = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	if (nbr < 0)
	{
		sign = 1;
		nbr *= -1;
	}
	nlen = nbrlen(nbr);
	res = getnbrstr(nbr, nlen, sign);
	return (res);
}
