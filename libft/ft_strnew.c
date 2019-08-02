/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:52:56 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:57:46 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	if ((size_t)(-1) == size)
		return (NULL);
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) != NULL)
	{
		str[size] = '\0';
		ft_bzero(str, size);
	}
	return (str);
}
