/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:48:24 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:56:49 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_strequ(char const *s1, char const *s2)
{
	size_t	len;

	if (!s1 || !s2)
		return (1);
	len = ft_strlen(s1);
	if ((size_t)(-1) == len)
		return (1);
	return (ft_strnequ(s1, s2, len + 1));
}
