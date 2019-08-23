/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 23:44:40 by enikole           #+#    #+#             */
/*   Updated: 2019/08/23 23:52:55 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_wordcount(char *str, char c)
{
	int		words;

	if (!str)
		return (0);
	words = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (!(*str))
			break ;
		words++;
		while (*str != c)
			str++;
	}
	return (words);
}
