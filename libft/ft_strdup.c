/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:29:38 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:56:39 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char				*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s;

	len = ft_strlen(s1);
	if ((s = (char*)malloc(sizeof(char) * (len + 1))) != NULL)
		return ((char*)ft_memcpy((void*)s, (const void*)s1, len + 1));
	return (NULL);
}
