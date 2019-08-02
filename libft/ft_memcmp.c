/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:20:32 by enikole           #+#    #+#             */
/*   Updated: 2019/04/11 14:40:34 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned	char	*str1;
	unsigned	char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (n--)
	{
		if (*str1 != *str2)
			return ((int)(*str1 - *str2));
		str1++;
		str2++;
	}
	return (0);
}
