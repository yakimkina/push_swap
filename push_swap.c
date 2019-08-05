/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:51:55 by enikole           #+#    #+#             */
/*   Updated: 2019/08/05 16:28:48 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
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
			if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <=
						MAX_INT && curr >= MIN_INT))
				stack[i++] = curr;
			else
				break ;
		}
		if (ac || check_dupl(stack, len))
			write(2, "Error\n", 6);
		else
		{
			//printf("stack :");
			//i = 0;
			//while (len--)
			//printf(" %d", stack[i++]);
			//printf("\nEND_OF_STACK\n");
			quicksort();
		}
		free(stack); //specify!!
	}
	return (0);
}
