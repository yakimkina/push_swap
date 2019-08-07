/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:08:11 by enikole           #+#    #+#             */
/*   Updated: 2019/08/07 10:08:35 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				check_dupl(int *stack, int len)
{
	int				i;
	int				j;

	i = len;
	while (--i)
	{
		j = i;
		while (j--)
		{
			if (stack[i] == stack[j])
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