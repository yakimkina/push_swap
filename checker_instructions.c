/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:21:52 by enikole           #+#    #+#             */
/*   Updated: 2019/08/06 17:01:24 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char			rotate(int **stack, int len)
{
	int			i;
	int			tmp;

	if (len > 1)
	{
		i = -1;
		tmp = (*stack)[0];
		while (++i < (len - 1))
			(*stack)[i] = (*stack)[i + 1];
		(*stack)[i] = tmp;
	}
	return (1);
}

char			rev_rotate(int **stack, int len)
{
	int			tmp;

	if (len > 1)
	{
		tmp = (*stack)[--len];
		while (len--)
			(*stack)[len + 1] = (*stack)[len];
		(*stack)[0] = tmp;
	}
	return (1);
}

char			r_inst(char *line, t_stack *stack)
{
	if (line[1] == 'a' && line[2] == 0)
		return (rotate(&stack->a, stack->la));
	else if (line[1] == 'b' && line[2] == 0)
		return (rotate(&stack->b, stack->lb));
	else if (line[1] == 'r')
	{
		if (line[2] == 'a' && line[3] == 0)
			return (rev_rotate(&stack->a, stack->la));
		else if (line[2] == 'b' && line[3] == 0)
			return (rev_rotate(&stack->b, stack->lb));
		else if (line[2] == 'r' && line[3] == 0)
			return (rev_rotate(&stack->a, stack->la) &&
					rev_rotate(&stack->b, stack->lb));
		else if (line[2] == 0)
			return (rotate(&stack->a, stack->la) &&
					rotate(&stack->b, stack->lb));
	}
	return (0);
}

char			swap(int *stack, int len)
{
	int			tmp;

	if (len > 1)
	{
		tmp = stack[0];
		stack[0] = stack[1];
		stack[1] = tmp;
	}
	return (1);
}

char			push(int **dst, int **src, int *len_dst, int *len_src)
{
	int			*tmp;
	int			i;
	int			j;

	if (len_src > 0)
	{
		tmp = (int *)malloc(sizeof(int) * (++(*len_dst)));
		i = (*len_dst);
		while (i-- > 1)
			tmp[i] = (*dst)[i - 1];
		tmp[0] = (*src)[0];
		free((*dst));
		*dst = tmp;
		if (--(*len_src))
			tmp = (int *)malloc(sizeof(int) * (*len_src));
		else
			tmp = NULL;
		j = (*len_src);
		while (j--)
			tmp[j] = (*src)[j + 1];
		free((*src));
		*src = tmp;
	}
	return (1);
}
