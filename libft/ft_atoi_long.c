/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:57:56 by enikole           #+#    #+#             */
/*   Updated: 2019/08/02 15:34:31 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

long	int			ft_atoi_long(const char *str)
{
	int				i;
	long	int		nb;

	i = 1;
	nb = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i = -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		if (nb > MAX_INT || nb < MIN_INT)
			break ;
		nb = nb * 10 + (*str - 48);
		str++;
	}
	return (i * nb);
}
