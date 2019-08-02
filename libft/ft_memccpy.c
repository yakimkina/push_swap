/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:09:09 by enikole           #+#    #+#             */
/*   Updated: 2019/04/11 14:16:29 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned	char	*s;
	unsigned	char	*d;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n--)
	{
		*d = *s;
		if (*s == (unsigned char)c)
			return ((void*)(++d));
		s++;
		d++;
	}
	return (NULL);
}
