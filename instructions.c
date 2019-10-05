/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:21:52 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 19:53:05 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				free_av(char **av)
{
	int				i;

	i = 0;
	while (av[i])
		free(av[i++]);
}

char				rotate(t_stack *stack, char *s)
{
	int				i;
	int				tmp;

	if (stack->size > 1)
	{
		i = -1;
		tmp = (stack->data)[0];
		while (++i < (stack->size - 1))
			(stack->data)[i] = (stack->data)[i + 1];
		(stack->data)[i] = tmp;
		if (s)
			write(1, s, 3);
	}
	return (1);
}

char				rev_rotate(t_stack *stack, char *s)
{
	int				i;
	int				tmp;

	if (stack->size > 1)
	{
		i = stack->size;
		tmp = (stack->data)[--i];
		while (i--)
			(stack->data)[i + 1] = (stack->data)[i];
		(stack->data)[0] = tmp;
		if (s)
			write(1, s, 4);
	}
	return (1);
}

char				swap(t_stack *stack, char *s)
{
	int				tmp;

	if (stack->size > 1)
	{
		tmp = (stack->data)[0];
		(stack->data)[0] = (stack->data)[1];
		(stack->data)[1] = tmp;
		if (s)
			write(1, s, 3);
	}
	return (1);
}

char				push(t_stack *dst, t_stack *src, char *s)
{
	int				*tmp;
	int				i;
	int				j;

	if (src->size > 0)
	{
		tmp = (int *)ft_memalloc(sizeof(int) * (++(dst->size)));
		i = (dst->size);
		while (i-- > 1)
			tmp[i] = (dst->data)[i - 1];
		tmp[0] = (src->data)[0];
		free((dst->data));
		dst->data = tmp;
		tmp = (--(src->size)) ? ((int *)ft_memalloc(sizeof(int) * (src->size)))
			: (NULL);
		j = (src->size);
		while (j--)
			tmp[j] = (src->data)[j + 1];
		free((src->data));
		src->data = tmp;
		if (s)
			write(1, s, 3);
	}
	return (1);
}
