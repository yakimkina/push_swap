/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:51:55 by enikole           #+#    #+#             */
/*   Updated: 2019/08/06 17:34:01 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void		sort(t_stack *stack)
{
	if (stack->la)
	{
		if (!stack->b || ((stack->a)[0] > (stack->b)[0]))
		{
			push(&stack->b, &stack->a, &stack->lb, &stack->la);
			write(1, "pb\n", 3);
		}
		else if ((stack->a)[0] < (stack->b)[0])
		{
			rotate(&stack->a, stack->la);
			write(1, "ra\n", 3);
			push(&stack->a, &stack->b, &stack->la, &stack->lb);
			write(1, "pa\n", 3);
			rev_rotate(&stack->a, stack->la);
			write(1, "rra\n", 4);
			sort(stack);
		}
	}
}

int					main(int ac, char **av)
{
	t_stack			stack;
	int				i;
	long	int		curr;

	if (ac > 1)
	{
		stack.la = ac - 1;
		stack.a = (int *)malloc(sizeof(int) * stack.la);
		i = 0;
		while (--ac)
		{
			if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <=
						MAX_INT && curr >= MIN_INT))
				(stack.a)[i++] = curr;
			else
				break ;
		}
		if (ac || check_dupl(stack.a, stack.la))
			write(2, "Error\n", 6);
		else
		{
			//printf("stack :");
			//i = 0;
			//while (len--)
			//printf(" %d", stack[i++]);
			//printf("\nEND_OF_STACK\n");
			stack.b = NULL;
			stack.lb = 0;
			sort(&stack);
		}
		free(stack.a); //specify!!
	}
	return (0);
}
