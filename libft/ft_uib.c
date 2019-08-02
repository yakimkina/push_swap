/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_llu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 19:17:00 by enikole           #+#    #+#             */
/*   Updated: 2019/06/29 18:10:43 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static	int						ft_len(size_t nb, int base)
{
	int							k;

	k = 1;
	while ((nb /= base) != 0)
		k++;
	return (k);
}

static	char					*ft_go(char *str, int k,
		size_t value, int base)
{
	int		sym;

	while (k--)
	{
		sym = value % base;
		if (sym >= 10 && sym <= 15)
			str[k] = 'a' + sym % 10;
		else
			str[k] = sym + 48;
		value /= base;
	}
	return (str);
}

char							*ft_uib(size_t value,
		int base)
{
	int							k;
	char						*str;

	k = ft_len(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (k + 1))) != NULL)
		str[k] = '\0';
	return (ft_go(str, k, value, base));
}
