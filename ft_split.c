/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosakura <mosakura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 13:53:51 by mosakura          #+#    #+#             */
/*   Updated: 2025/11/23 15:00:26 by mosakura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**freeall(char **res, size_t j)
{
	if (res)
	{
		while (0 < j)
			free(res[j--]);
		free(res);
	}
	return (NULL);
}

static char	*getstr(const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	getstart(char const *s, char c, size_t previ)
{
	while (s[previ] && s[previ] == c)
		previ++;
	return (previ);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	res = (char **)malloc((count + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res[count] = NULL;
	i = 0;
	j = 0;
	while (count != 0)
	{
		i = getstart(s, c, i);
		res[j] = getstr(s + i, c);
		if (!res[j])
			return (freeall(res, j));
		i += ft_strlen(res[j]);
		j++;
		count--;
	}
	return (res);
}
