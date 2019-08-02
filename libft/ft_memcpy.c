/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 16:29:13 by enikole           #+#    #+#             */
/*   Updated: 2019/04/12 19:16:53 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*d;
	unsigned	char	*s;

	d = (unsigned char*)dst + n;
	s = (unsigned char*)src + n;
	if (!dst && !src)
		return (NULL);
	while (n--)
	{
		d--;
		s--;
		*d = *s;
	}
	return ((void*)dst);
}
