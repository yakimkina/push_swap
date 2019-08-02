/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:15:34 by bnigellu          #+#    #+#             */
/*   Updated: 2019/08/01 13:51:58 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void		free_struct(t_double *list)
{
	free(list->frac);
	free(list->mantisa);
	free(list->first_2);
	free(list->second_int_2);
	free(list->second_frac_2);
	free(list->integer);
}

static	int			f_wid(char *str, t_form *per)
{
	int				i;
	int				len;
	int				sum;

	len = ft_strlen((const char*)(str));
	sum = (per->width > len) ? (per->width) : (len);
	if ((per->width > len) && (i = per->width - len) && per->minus)
	{
		ft_putstr(str);
		while (i--)
			write(1, " ", 1);
		return (sum);
	}
	else if ((per->width > len) && (i = per->width - len) && per->zero)
	{
		if ((str[0] == '+' || str[0] == '-' || str[0] == ' ') && str++)
			write(1, &str[-1], 1);
		while (i--)
			write(1, "0", 1);
	}
	else if (per->width > len && (i = per->width - len))
		while (i--)
			write(1, " ", 1);
	ft_putstr(str);
	return (sum);
}

static	void		first_addend(t_double *list, t_double_cast d1)
{
	ssize_t			power;
	size_t			i;

	power = d1.parts.exponent - 1023;
	if (power < 0)
	{
		power = power * (-1);
		list->first_2 = ft_strnew(power + 2);
		list->first_2[0] = 'n';
	}
	else
	{
		list->first_2 = ft_strnew(power + 2);
		list->first_2[0] = 'p';
	}
	list->first_2[1] = '1';
	i = 2;
	while (power != 0)
	{
		list->first_2[i] = '0';
		i++;
		power--;
	}
}

int					fun_f(double num, t_form *per)
{
	t_double_cast	d1;
	t_double		list;
	char			*str;
	int				sum;

	d1.d = num;
	list.mantisa = ft_ib((unsigned long long)d1.parts.mantisa, 2);
	list.length = ft_strlen((const char*)(list.mantisa)) - 1;
	first_addend(&list, d1);
	second_addend(&list, d1);
	integer(&list);
	fraction(&list);
	str = beuty_double(per, &list, d1);
	free_struct(&list);
	sum = f_wid(str, per);
	free(str);
	return (sum);
}
