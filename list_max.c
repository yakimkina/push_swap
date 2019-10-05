/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 20:50:46 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 20:50:47 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			stack_max(t_stack stack)
{
	int		i;
	int		max;

	i = 1;
	max = stack.data[0];
	while (i < stack.size)
	{
		if (stack.data[i] > max)
			max = stack.data[i];
		i++;
	}
	return (max);
}

int			stack_min(t_stack stack)
{
	int		i;
	int		min;

	i = 1;
	min = stack.data[0];
	while (i < stack.size)
	{
		if (stack.data[i] < min)
			min = stack.data[i];
		i++;
	}
	return (min);
}

void		del_max(t_max **begin)
{
	t_max	*tmp;

	if (*begin)
	{
		tmp = (*begin);
		*begin = (*begin)->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void		add_max(t_max **begin, int max)
{
	t_max	*tmp;

	if (!(*begin) || (*begin)->max != max)
	{
		tmp = (t_max *)ft_memalloc(sizeof(t_max) * 1);
		tmp->max = max;
		if (!(*begin))
			tmp->next = NULL;
		else
			tmp->next = *begin;
		*begin = tmp;
	}
}
