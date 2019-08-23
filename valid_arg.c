/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:08:11 by enikole           #+#    #+#             */
/*   Updated: 2019/08/24 00:17:25 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				check_dupl(t_stack a)
{
	int				i;
	int				j;

	i = a.size;
	while (--i)
	{
		j = i;
		while (j--)
		{
			if (a.data[i] == a.data[j])
				return (1);
		}
	}
	return (0);
}

char				check_int(char *str)
{
	char			fl;

	fl = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str)
	{
		if (fl && (*str == '-' || *str == '+'))
		{
			fl = 0;
			str++;
		}
		else if ((*str >= '0' && *str <= '9'))
		{
			str++;
			if (!(*str))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}