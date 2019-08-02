/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:53:55 by enikole           #+#    #+#             */
/*   Updated: 2019/06/29 18:40:07 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static	int						ft_len(ssize_t nb, int base)
{
	int							k;

	k = 1;
	while ((nb /= base) != 0)
		k++;
	return (k);
}

static	char					*ft_go(char *str, int k,
		ssize_t value, int base)
{
	int		sym;
	int		fl;

	fl = (value < 0) ? (-1) : (1);
	while (k--)
	{
		if (fl == -1 && k == 0 && base == 10)
		{
			str[k] = '-';
			break ;
		}
		sym = value % base * fl;
		if (sym >= 10 && sym <= 15)
			str[k] = 'a' + sym % 10;
		else
			str[k] = sym + 48;
		value /= base;
	}
	return (str);
}

char							*ft_ib(ssize_t value,
		int base)
{
	int							fl;
	int							k;
	char						*str;

	fl = (value < 0) ? (-1) : (1);
	k = ft_len(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && fl == -1)
		k++;
	if ((str = (char*)malloc(sizeof(char) * (k + 1))) != NULL)
		str[k] = '\0';
	return (ft_go(str, k, value, base));
}
