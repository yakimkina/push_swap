/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 12:54:25 by enikole           #+#    #+#             */
/*   Updated: 2019/04/11 14:21:32 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned	char	*str;

	str = (unsigned char*)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void*)str);
		str++;
	}
	return (NULL);
}
