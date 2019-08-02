/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:36:39 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:56:20 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	return (ft_memmove((void*)dst, (const void*)src, ft_strlen(src) + 1));
}
