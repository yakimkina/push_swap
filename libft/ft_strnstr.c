/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 12:35:44 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:57:49 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while ((haystack[i] != '\0') && (i < len))
	{
		if (haystack[i] == needle[k])
		{
			j = 0;
			while (haystack[i + j] == needle[k + j] && (i + j) < len &&
					haystack[i + j] != '\0')
				j++;
			if (needle[k + j] == '\0')
				return ((char*)&haystack[i]);
		}
		k = 0;
		i++;
	}
	return (NULL);
}
