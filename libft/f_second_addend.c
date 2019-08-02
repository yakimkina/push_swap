/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_second_addend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:10:12 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:51:14 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void		neg_case_else(t_double *list, long int power)
{
	long	int		i;
	long	int		j;

	j = list->length + 1;
	i = power;
	while (i >= 0)
	{
		if (j >= 0)
			list->second_frac_2[i] = list->mantisa[j];
		else
			list->second_frac_2[i] = '0';
		i--;
		j--;
	}
}

static	void		init_list(t_double *list, long int power, long int i)
{
	if (i > 0)
	{
		list->second_frac_2 = ft_strnew(power);
		list->second_int_2 = ft_strnew(i);
	}
	else
	{
		list->second_frac_2 = ft_strnew(power);
		list->second_int_2 = ft_strnew(1);
		list->second_int_2[0] = '0';
	}
}

static	void		neg_pow(t_double *list, long int power)
{
	long	int		i;
	long	int		j;

	i = (long int)list->length - power + 1;
	init_list(list, power, i);
	j = -1;
	while (++j != i && i >= 0)
		list->second_int_2[j] = list->mantisa[j];
	j = 0;
	if (i >= 0)
	{
		while (list->mantisa[i] != '\0')
			list->second_frac_2[j++] = list->mantisa[i++];
	}
	else
		neg_case_else(list, power);
	while (list->second_frac_2[--j] == '0')
		list->second_frac_2[j] = '\0';
}

static	void		poz_pow(t_double *list, size_t power)
{
	size_t			i;
	size_t			j;

	j = power + list->length;
	list->second_int_2 = ft_strnew(j);
	i = 0;
	while (list->mantisa[i] != '\0')
	{
		list->second_int_2[i] = list->mantisa[i];
		i++;
	}
	while (i != j + 1)
	{
		list->second_int_2[i] = '0';
		i++;
	}
}

void				second_addend(t_double *list, t_double_cast d1)
{
	long int		power;

	if (d1.parts.mantisa == 0)
	{
		list->second_int_2 = ft_strnew(1);
		list->second_frac_2 = ft_strnew(1);
		list->second_int_2[0] = '0';
		list->second_frac_2[0] = '0';
		return ;
	}
	power = (long int)d1.parts.exponent - 1075;
	if (power < 0)
		neg_pow(list, power * (-1));
	else if (power >= 0)
		poz_pow(list, power);
}
