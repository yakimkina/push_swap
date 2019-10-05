/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 19:45:36 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 19:59:35 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int			*bubble_sort_v(int *stack, int len)
{
	int				i;
	int				j;
	int				tmp;
	int				*mas;

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
	return (mas);
}

void				rewrite_a(t_stack *a)
{
	int				i;
	int				j;
	int				*mas;

	mas = bubble_sort_v(a->data, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (a->data[i] != mas[j])
			j++;
		a->data[i] = j + 1;
		i++;
	}
	free(mas);
}

int					reading_args_v(int *ac, char ***av, t_stack *a)
{
	int				i;
	int				fl;
	long	int		curr;

	fl = 2;
	if (*ac == 3)
	{
		*ac = ft_wordcount((*av)[2], ' ');
		*av = ft_strsplit((*av)[2], ' ');
		fl = 0;
	}
	a->size = (fl == 2) ? (*ac -= 2) : (*ac);
	a->data = (int *)ft_memalloc(sizeof(int) * a->size);
	i = 0;
	while (i < (*ac))
	{
		if (check_int((*av)[i + fl]) && ((curr = ft_atoi_long((*av)[i + fl]))
					<= MAX_INT && curr >= MIN_INT))
			(a->data)[i++] = curr;
		else
			break ;
	}
	*ac -= i;
	return (fl);
}
