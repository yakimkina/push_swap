/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:34:49 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 20:34:51 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			three_sort_stack(t_stack *a)
{
	if ((a->data)[0] < (a->data)[1] && (a->data)[1] > (a->data)[2])
	{
		rev_rotate(a, "rra\n");
		if ((a->data)[1] < (a->data)[0])
			swap(a, "sa\n");
	}
	else if ((a->data)[0] > (a->data)[1])
	{
		if ((a->data)[0] < (a->data)[2])
			swap(a, "sa\n");
		else if ((a->data)[1] < (a->data)[2])
			rotate(a, "ra\n");
		else
		{
			swap(a, "sa\n");
			rev_rotate(a, "rra\n");
		}
	}
}

static	void	case_4(t_stack *a, t_stack *b, int med)
{
	int			i;

	i = 0;
	while (!b->size)
	{
		if (a->data[0] > med)
			push(b, a, "pb\n");
		else
			i += rotate(a, "ra\n");
	}
	(i) ? three_rot_a(a, b, i) : (three_sort_stack_a(a, b));
	push(a, b, "pa\n");
	rotate(a, "ra\n");
}

void			five_sort_stack_a(t_stack *a, t_stack *b, int num, int med)
{
	if (num == 4)
		case_4(a, b, med);
	else if (num == 3)
		three_sort_stack_a(a, b);
	else if (num == 2)
	{
		if (a->data[0] > a->data[1])
			swap(a, "sa\n");
		rotate(a, "ra\n");
		rotate(a, "ra\n");
	}
	else if (num == 1)
		rotate(a, "ra\n");
}

static	void	smart_split(t_stack *a, t_stack *b, int num, int med)
{
	int			i;

	i = 0;
	if (num < 6 && a->size < 6)
		five_sort_stack(a, b);
	else if (num < 5)
		five_sort_stack_a(a, b, num, med);
	else
	{
		while (num--)
		{
			if ((a->data)[0] < med)
				push(b, a, "pb\n");
			else if (check_rot(a, b, num + 1, med))
				i += rotate(a, "ra\n");
			else
				break ;
		}
		if (is_not_sort(*a) || b->data)
			while (i--)
				rev_rotate(a, "rra\n");
	}
}

void			split_a(t_stack *a, t_stack *b, int max, t_max **begin)
{
	int			border;
	int			med;
	int			num;

	if (a->data[0] <= max)
	{
		while ((a->data)[0] <= max)
		{
			if (a->data[1] > max && a->data[0] < stack_min(*b))
				rotate(a, "ra\n");
			else
				push(b, a, "pb\n");
		}
	}
	else
	{
		del_max(begin);
		border = ((*begin)) ? ((*begin)->max) : (stack_max(*a));
		num = count_num(*a, max, border);
		med = bubble_sort(a->data, num);
		smart_split(a, b, num, med);
	}
}
