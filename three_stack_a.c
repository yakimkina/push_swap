/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_stack_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 21:23:14 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 21:46:25 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	case_else(t_stack *a, t_stack *b)
{
	char		fl;

	fl = 0;
	push(b, a, "pb\n");
	swap(a, "sa\n");
	rotate(a, "ra\n");
	if (a->data[0] > b->data[0])
		fl = push(a, b, "pa\n");
	rotate(a, "ra\n");
	if (!fl)
		push(a, b, "pa\n");
}

void			three_sort_stack_a(t_stack *a, t_stack *b)
{
	if (a->data[0] < a->data[1] && a->data[0] < a->data[2])
	{
		rotate(a, "ra\n");
		if (a->data[0] > a->data[1])
			swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
		if (a->data[0] > a->data[1])
			swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else
		case_else(a, b);
	rotate(a, "ra\n");
}

static	void	case_2(t_stack *a, t_stack *b, int i)
{
	if (a->data[0] > a->data[a->size - 2] && a->data[a->size - 2] <
			a->data[a->size - 1])
	{
		if (a->data[0] < a->data[a->size - 1])
		{
			rev_rotate(a, "rra\n");
			swap(a, "sa\n");
			rotate(a, "ra\n");
		}
		rotate(a, "ra\n");
	}
	else
	{
		rev_rotate(a, "rra\n");
		if (a->data[1] < a->data[0])
			swap(a, "sa\n");
		rev_rotate(a, "rra\n");
		three_sort_stack_a(a, b);
	}
}

static	void	case_3(t_stack *a, t_stack *b, int i)
{
	if (a->data[a->size - 3] < a->data[a->size - 2] &&
		a->data[a->size - 3] < a->data[a->size - 1])
	{
		if (a->data[a->size - 2] > a->data[a->size - 1])
		{
			rev_rotate(a, "rra\n");
			rev_rotate(a, "rra\n");
			swap(a, "sa\n");
			rotate(a, "ra\n");
			rotate(a, "ra\n");
		}
	}
	else
	{
		while (i--)
			rev_rotate(a, "rra\n");
		three_sort_stack_a(a, b);
	}
}

void			three_rot_a(t_stack *a, t_stack *b, int i)
{
	if (i == 3)
		case_3(a, b, i);
	else if (i == 2)
		case_2(a, b, i);
	else
	{
		if (a->data[a->size - 1] < a->data[0] && a->data[1] >
				a->data[a->size - 1])
		{
			if (a->data[0] > a->data[1])
				swap(a, "sa\n");
			rotate(a, "ra\n");
			rotate(a, "ra\n");
		}
		else
		{
			if (a->data[0] > a->data[1])
				swap(a, "sa\n");
			rev_rotate(a, "rra\n");
			three_sort_stack_a(a, b);
		}
	}
}
