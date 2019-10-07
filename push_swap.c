/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:51:55 by enikole           #+#    #+#             */
/*   Updated: 2019/09/13 19:07:30 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				is_not_sort(t_stack stack)
{
	int				i;

	i = 0;
	while (i < (stack.size - 1))
	{
		if (stack.data[i] < stack.data[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

static	void		first_split(t_stack *a, t_stack *b)
{
	int				i;
	int				med;

	med = bubble_sort(a->data, a->size);
	i = (a->size % 2 == 0) ? (a->size / 2) : (a->size / 2 + 1);
	while (a->size != i)
	{
		if ((a->data)[0] < med)
			push(b, a, "pb\n");
		else
			rotate(a, "ra\n");
	}
}

static	void		quicksort(t_stack *a, t_stack *b)
{
	t_max			*begin;

	first_split(a, b);
	begin = NULL;
	while (is_not_sort(*a) || b->data)
	{
		split_b(a, b, &begin);
		split_a(a, b, begin->max, &begin);
	}
}

int					main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	int				fl;

	if (ac > 1 && av[1][0] != '\0')
	{
		fl = reading_args(&ac, &av, &a);
		if (ac || check_duplicates(a))
			write(2, "Error\n", 6);
		else
		{
			b.data = NULL;
			b.size = 0;
			if (is_not_sort(a))
				(a.size < 6) ? (five_sort_stack(&a, &b)) : quicksort(&a, &b);
		}
		free(a.data);
		if (!fl)
			free_av(av);
	}
	return (0);
}
