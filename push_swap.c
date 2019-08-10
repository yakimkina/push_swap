/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:51:55 by enikole           #+#    #+#             */
/*   Updated: 2019/08/10 17:28:55 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char		is_sort(t_stack stack)
{
	int				i;

	i = 0;
	while (i < (stack.la - 1))
	{
		if (stack.a[i] < stack.a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

/* static	void		sort(t_stack *stack)
{
	if (stack->la)
	{
		if (!stack->b || ((stack->a)[0] > (stack->b)[0]))
		{
			push(&stack->b, &stack->a, &stack->lb, &stack->la);
			write(1, "pb\n", 3);
			sort(stack);
		}
		else if ((stack->a)[0] < (stack->b)[0])
		{
			rotate(&stack->a, stack->la);
			write(1, "ra\n", 3);
			push(&stack->a, &stack->b, &stack->la, &stack->lb);
			write(1, "pa\n", 3);
			while (stack->b && (stack->a)[stack->la - 1] < (stack->b)[0])
			{
				push(&stack->a, &stack->b, &stack->la, &stack->lb);
				write(1, "pa\n", 3);
			}
			rev_rotate(&stack->a, stack->la);
			write(1, "rra\n", 4);
			sort(stack);
		}
	}
	else
	{
		while (stack->lb)
		{
			push(&stack->a, &stack->b, &stack->la, &stack->lb);
			write(1, "pa\n", 3);
		}
	}
} */

/* static	int			*intcpy(int *dst, int *src, int len)
{
	while (len--)
		dst[len] = src[len];
	return (dst);
} */

static	int			bubble_sort(int *stack, int len) //rewrite this to quickselect
{
	int				i;
	int				j;
	int				tmp;
	int				*mas;

	mas = (int *)malloc(sizeof(int) * len);
	mas = intcpy(mas, stack, len);
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1))
		{
			if (mas[j] > mas[j + 1])
			{
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	tmp = mas[(len / 2)];
	return (tmp);
}

/* static	void		sort(t_stack *stack)
{
	int				*mas;
	int				i;
	int				j;
	int				del;

	mas = bubble_sort(stack->a, stack->la);
	//i = 0;
	//printf("sort mas:\n");
	//while (i < stack->la)
	//	printf("%d ", mas[i++]);
	//printf("\n");
	i = 0;
	while (stack->la)
	{
		j = 0;
		while (mas[i] != stack->a[j])
			j++;
		//printf("j = %d, stack->la = %d\n", j, stack->la);
		if ((del = (stack->la - j)) < j)
		{
			while (del--)
			{
				rev_rotate(&stack->a, stack->la);
				write(1, "rra\n", 4);
				//printf("del = %d\n", del);
			}
			push(&stack->b, &stack->a, &stack->lb, &stack->la);
			write(1, "pb\n", 3);
		}
		else
		{
			while (j--)
			{
				rotate(&stack->a, stack->la);
				write(1, "ra\n", 3);
			}
			push(&stack->b, &stack->a, &stack->lb, &stack->la);
			write(1, "pb\n", 3);
		}
		i++;
	}
	while (stack->lb)
	{
		push(&stack->a, &stack->b, &stack->la, &stack->lb);
		write(1, "pa\n", 3);
	}
	free(mas);
} */

/* static	int			quickselect(int *mas, int len, int k)
{
	t_stack			new;
	int				pivot;
	int				i;

	pivot = mas[0];
	i = 0;
	new.la = 0;
	new.lb = 0;
	while (i < len)
		(mas[i++] >= pivot) ? (new.lb++) : (new.la++);
	new.a = (int *)malloc(sizeof(int) * new.la);
	new.b = (int *)malloc(sizeof(int) * new.lb);
	i = 0;
	while (i < len)
	{
		if ()
	}
} */

static	void		three_sort_stack_a(int	*stack, int len)
{
	if (stack[0] < stack[1] && stack[1] > stack[2])
	{
		rev_rotate(&stack, len);
		write(1, "rra\n", 4);
		if (stack[0] < stack[2])
		{
			swap(stack, len);
			write(1, "sa\n", 3);
		}
	}
	else if (stack[0] > stack[1])
	{
		if (stack[1] < stack[2] && stack[0] < stack[2])
		{
			swap(stack, len);
			write(1, "sa\n", 3);
		}
		else if (stack[1] < stack[2])
	}
}

static	void		quicksort_stack_b(t_stack *stack)
{}

static	void		quicksort_stack_a(t_stack *stack)
{
	int				i;
	int				med;

	med = bubble_sort(stack->a, stack->la);
	i = ((stack->la / 2) % 2 == 0) ? (stack->la / 2) : (stack->la / 2 + 1);
	while (stack->la != i)
	{
		if ((stack->a)[0] < med)
		{
			push(&stack->b, &stack->a, &stack->lb, &stack->la);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(&stack->a, stack->la);
			write(1, "ra\n", 3);
		}
	}
	if (stack->la > 3)
		quicksort_stack_a(stack);
	else
	{
		three_sort_stack_a(stack->a, stack->la);
		quicksort_stack_b(stack);
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
			//while (i < stack.la)
				//printf(" %d", stack.a[i++]);
			//printf("\nEND_OF_STACK\n");
			stack.b = NULL;
			stack.lb = 0;
			if (is_sort(stack))
				quicksort(&stack);
		}
		free(stack.a); //specify!!
	}
	return (0);
}
