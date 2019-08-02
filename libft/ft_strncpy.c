/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:01:34 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:57:35 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (i + j < len)
	{
		if (src[i] == '\0')
		{
			dst[i + j] = '\0';
			j++;
		}
		else
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
