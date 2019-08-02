/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 12:57:14 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:57:08 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((size_t)(-1) == (len1 + len2))
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (len1 + len2 + 1))) != NULL)
	{
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		str[len1 + len2] = '\0';
	}
	return (str);
}
