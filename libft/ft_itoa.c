/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:40:20 by enikole           #+#    #+#             */
/*   Updated: 2019/04/11 20:48:16 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char		*ft_itoa(int n)
{
	int		fl;
	int		k;
	int		nb;
	char	*str;

	fl = 1;
	k = 1;
	nb = n;
	while ((nb /= 10) != 0)
		k++;
	if (n < 0 && k++)
		fl = -1;
	str = (char*)malloc(sizeof(char) * (k + 1));
	if (str != NULL)
	{
		str[k] = '\0';
		str[--k] = fl * (n % 10) + 48;
		while (k-- && (n /= 10) != 0)
			str[k] = fl * (n % 10) + 48;
		if (fl == -1)
			str[k] = '-';
	}
	return (str);
}
