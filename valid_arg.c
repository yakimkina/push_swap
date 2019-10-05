/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 10:08:11 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 22:13:20 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				reading_args(int *ac, char ***av, t_stack *a)
{
	int				i;
	int				fl;
	long	int		curr;

	fl = 1;
	if (*ac == 2)
	{
		*ac = ft_wordcount((*av)[1], ' ') + 1;
		*av = ft_strsplit((*av)[1], ' ');
		fl = 0;
	}
	a->size = *ac - 1;
	a->data = (int *)ft_memalloc(sizeof(int) * a->size);
	i = 0;
	while (--(*ac))
	{
		if (check_int((*av)[i + fl]) && ((curr = ft_atoi_long((*av)[i + fl]))
										<= MAX_INT && curr >= MIN_INT))
			(a->data)[i++] = curr;
		else
			break ;
	}
	return (fl);
}

void				check(t_stack a, t_stack b)
{
	int				i;
	char			fl;

	i = 0;
	fl = 1;
	i = 0;
	while (i < (a.size - 1))
	{
		if ((a.data)[i] < (a.data)[i + 1])
			i++;
		else
		{
			fl = 0;
			break ;
		}
	}
	fl = (b.data == NULL && b.size == 0) ? (fl) : (0);
	if (fl)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

char				check_duplicates(t_stack a)
{
	int				i;
	int				j;

	i = a.size;
	while (--i)
	{
		j = i;
		while (j--)
		{
			if (a.data[i] == a.data[j])
				return (1);
		}
	}
	return (0);
}

char				check_int(char *str)
{
	char			fl;

	fl = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str)
	{
		if (fl && (*str == '-' || *str == '+'))
		{
			fl = 0;
			str++;
		}
		else if ((*str >= '0' && *str <= '9'))
		{
			str++;
			if (!(*str))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
