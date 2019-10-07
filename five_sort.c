/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:25:18 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 20:25:24 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				count_num(t_stack a, int max, int border)
{
	int			i;

	i = 0;
	if (max != border)
	{
		while (a.data[i] > max && a.data[i] <= border)
			i++;
	}
	else
	{
		while (a.data[i] <= max)
			i++;
	}
	return (i);
}

char			check_rot(t_stack *a, t_stack *b, int num, int med)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	while (i != num)
	{
		if (a->data[i] >= med)
			i++;
		else
			break ;
	}
	if (i == num)
	{
		tmp = (t_stack *)ft_memalloc(sizeof(t_stack));
		tmp->data = &(a->data[i]);
		tmp->size = a->size - num;
		if (is_not_sort(*tmp) || b->data)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}

int				bubble_sort(int *stack, int len)
{
	int			i;
	int			j;
	int			tmp;
	int			*mas;

	mas = (int *)ft_memalloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
		mas[i] = stack[i];
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < (len - 1))
			if (mas[j] > mas[j + 1])
			{
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
	}
	tmp = mas[(len / 2)];
	free(mas);
	return (tmp);
}

static	void	choice_2_or_3(t_stack *a)
{
	if (a->size == 2 && a->data[0] > a->data[1])
		swap(a, "sa\n");
	else if (a->size == 3)
		three_sort_stack(a);
}

void			five_sort_stack(t_stack *a, t_stack *b)
{
	int			med;
	int			i;

	if (a->size < 4)
		choice_2_or_3(a);
	else
	{
		med = bubble_sort(a->data, a->size);
		i = (a->size % 2 == 0) ? (a->size / 2) : (a->size / 2 + 1);
		while (a->size != i)
		{
			if (a->data[0] < med)
				push(b, a, "pb\n");
			else
				rotate(a, "ra\n");
		}
		choice_2_or_3(a);
		if (b->size == 2 && b->data[0] < b->data[1])
			swap(b, "sb\n");
		while (b->size)
			push(a, b, "pa\n");
	}
}
