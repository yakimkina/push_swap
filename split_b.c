/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:34:54 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 20:34:56 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate_up(t_stack *a, t_stack *b, int i)
{
	while (i > 0)
	{
		if ((b->data)[0] == stack_min(*b))
		{
			push(a, b, "pa\n");
			i--;
			if (i && b->data[0] != stack_min(*b))
			{
				rotate(a, NULL);
				rotate(b, "rr\n");
				i--;
			}
			else
				rotate(a, "ra\n");
		}
		if (i)
			rotate(b, "rb\n");
		i--;
	}
}

static	int		smart_rotate(t_stack *a, t_stack *b, int i)
{
	int			j;

	if (i <= b->size / 2)
		rotate_up(a, b, i);
	else
	{
		j = b->size - i;
		while (j > 0)
		{
			if ((b->data)[0] == stack_min(*b))
			{
				push(a, b, "pa\n");
				rotate(a, "ra\n");
			}
			rev_rotate(b, "rrb\n");
			j--;
		}
	}
	push(a, b, "pa\n");
	return (1);
}

static	int		twelve_split(t_stack *a, t_stack *b)
{
	int			i;
	int			max;
	int			res_max;

	res_max = 0;
	while (b->size)
	{
		if ((b->data)[0] == stack_min(*b))
		{
			push(a, b, "pa\n");
			rotate(a, "ra\n");
		}
		else
		{
			i = 0;
			max = stack_max(*b);
			while ((b->data)[i] != max)
				i++;
			res_max += smart_rotate(a, b, i);
		}
	}
	return (res_max);
}

static	void	b_one_iter(t_stack *a, t_stack *b, int med, int i)
{
	while (b->size != i && b->size)
	{
		if (b->data[0] >= med)
			push(a, b, "pa\n");
		else
		{
			if (b->data[0] == stack_min(*b))
			{
				push(a, b, "pa\n");
				if (b->size != i && b->size && b->data[0] < med &&
					b->data[0] != stack_min(*b))
				{
					rotate(a, NULL);
					rotate(b, "rr\n");
				}
				else
					rotate(a, "ra\n");
				i--;
			}
			else
				rotate(b, "rb\n");
		}
	}
}

void			split_b(t_stack *a, t_stack *b, t_max **begin)
{
	int			med;
	int			max;
	int			i;
	int			k;

	if (b->size)
	{
		if (b->size <= 12)
		{
			max = stack_max(*b);
			add_max(begin, max);
		}
		while (b->size > 12)
		{
			max = stack_max(*b);
			add_max(begin, max);
			med = bubble_sort(b->data, b->size);
			i = (b->size / 2);
			b_one_iter(a, b, med, i);
		}
		k = twelve_split(a, b);
		while (k--)
			rotate(a, "ra\n");
	}
}
