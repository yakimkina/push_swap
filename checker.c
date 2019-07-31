/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:51:51 by enikole           #+#    #+#             */
/*   Updated: 2019/07/30 19:20:39 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					main(int ac, char **av)
{
	int				*stack;
	int				len;
	int				i;
	long	int		curr;

	if (ac > 1)
	{
		len = ac - 1;
		stack = (int *)malloc(sizeof(int) * len);
		i = 0;
		while (--ac)
		{
			if ((curr = ft_atoi(av[i + 1])) > MAX_INT || curr == -1)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			//check duplicates
		}
	}
	return (0);
}