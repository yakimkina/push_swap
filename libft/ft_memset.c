/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 18:17:46 by enikole           #+#    #+#             */
/*   Updated: 2019/04/07 15:19:00 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void					*ft_memset(void *b, int c, size_t len)
{
	unsigned	char	*dest;

	dest = (unsigned char*)b;
	while (len--)
	{
		*dest = (unsigned char)c;
		dest++;
	}
	return ((void*)b);
}
