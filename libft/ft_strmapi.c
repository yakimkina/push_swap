/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:02:40 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:57:24 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char					*ft_strmapi(char const *s,
		char (*f)(unsigned int, char))
{
	char				*str;
	unsigned	int		i;
	size_t				len;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if ((size_t)(-1) == len)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (len + 1))) != NULL)
	{
		while (s[i] != '\0')
		{
			str[i] = f(i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
