/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:21:52 by enikole           #+#    #+#             */
/*   Updated: 2019/08/24 00:51:07 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				rec_str(int *ac, char ***av, t_stack *a)
{
	int				i;
	char			fl;
	long	int		curr;

	fl = 0;
	if (ac == 2)
	{
		*ac = ft_wordcount(**av, ' ') + 1;
		*av = ft_strsplit(av[1], ' ');
		fl = 1;
	}
	a->size = *ac - 1;
	a->data = (int *)malloc(sizeof(int) * a->size);
	i = 0;
	while (--(*ac))
	{
		if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <=
						MAX_INT && curr >= MIN_INT))
				(a->data)[i++] = curr;
			else
				break ;
	}
	return (fl);
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
			wirte(1, s, 4);
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
		tmp = (int *)malloc(sizeof(int) * (++(dst->size)));
		i = (dst->size);
		while (i-- > 1)
			tmp[i] = (dst->data)[i - 1];
		tmp[0] = (src->data)[0];
		free((dst->data));
		dst->data = tmp;
		tmp = (--(src->size)) ? ((int *)malloc(sizeof(int) * (src->size))) : (NULL);
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
