/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 19:27:48 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:53:51 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void					*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned	char	*d;
	unsigned	char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d == s)
		return ((void*)src);
	if (d < s)
	{
		while (len--)
		{
			*d = *s;
			d++;
			s++;
		}
	}
	else
		ft_memcpy((void*)d, (const void*)s, len);
	return ((void*)dst);
}
