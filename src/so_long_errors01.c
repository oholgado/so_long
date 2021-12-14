/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errors01.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oholgado <oholgado@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:55:18 by oholgado          #+#    #+#             */
/*   Updated: 2021/12/03 10:33:37 by oholgado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!to_find[0])
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		while (to_find[j] && (str[i + j] == to_find[j])
			&& str[i + j] && ((i + j) < n))
			j++;
		if (!to_find[j])
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
