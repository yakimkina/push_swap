/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:53:55 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 17:04:23 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_len(int nb, int base)
{
	int			k;

	k = 1;
	while ((nb /= base) != 0)
		k++;
	return (k);
}

static	int		ft_flag(int value)
{
	if (value < 0)
		return (-1);
	return (1);
}

static	char	*ft_go(char *str, int k, int value, int base)
{
	int			sym;
	int			fl;

	fl = ft_flag(value);
	while (k--)
	{
		if (fl == -1 && k == 0 && base == 10)
		{
			str[k] = '-';
			break ;
		}
		sym = value % base * fl;
		if (sym >= 10 && sym <= 15)
			str[k] = 'A' + sym % 10;
		else
			str[k] = sym + 48;
		value /= base;
	}
	return (str);
}

char			*ft_itoa_base(int value, int base)
{
	int			fl;
	int			k;
	char		*str;

	fl = ft_flag(value);
	k = ft_len(value, base);
	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10 && fl == -1)
		k++;
	if ((str = (char*)malloc(sizeof(char) * (k + 1))) != NULL)
		str[k] = '\0';
	else
		return (NULL);
	return (ft_go(str, k, value, base));
}
