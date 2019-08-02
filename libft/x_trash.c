/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_trash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:28:47 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:54:09 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		flags_num(int i, int *fl, int *fl1, int *fl2)
{
	(*fl2) = 0;
	(*fl1) = 0;
	(*fl) = i;
}

void		flags_dot(int i, int *fl, int *fl1, int *fl2)
{
	(*fl2) = 0;
	if (!(*fl))
	{
		(*fl1) = 0;
		(*fl) = i;
	}
}

int			x_case_else(char **buf, char *str, t_form *per, int l)
{
	int		fl;
	int		s;

	fl = (per->hash) ? (2) : (0);
	s = l + fl;
	(*buf) = (char *)ft_memalloc(s + 1);
	(*buf) = (char *)ft_memcpy((*buf), str, l);
	if (per->hash && per->type == 'x')
		write(1, "0x", 2);
	else if (per->hash)
		write(1, "0X", 2);
	return (s);
}

int			count_l(t_form *per, int *l)
{
	if (per->prec == -1 && !per->width)
		(*l) = 0;
	else if (!per->prec && !per->width)
		(*l) = 1;
	else
		(*l) = (per->prec < per->width) ? (per->width) : (per->prec);
	return (*l);
}

void		x_zero(char **buf, char *str, t_form *per, int l)
{
	(*buf) = (char *)ft_memalloc(l + 1);
	if (per->prec >= per->width)
		(*buf) = (char *)ft_memset((*buf), 48, l);
	else if (per->prec == -1)
		(*buf) = (char *)ft_memset((*buf), 32, l);
	else
	{
		if (per->prec > 0 && per->prec <= MAX_INT)
			(*buf) = (char *)ft_memset((*buf), 48, l);
		fun_width((int)(per->width - per->prec), buf);
		if ((per->prec <= 1 || per->prec > MAX_INT) && per->minus)
			minus(buf, str, 1, per->width);
		else if (per->minus)
			di_minus(buf, 0, per);
		else if (!per->prec && per->zero)
			(*buf) = (char *)ft_memset((*buf), 48, l);
		else if (!per->prec)
			(*buf)[l - 1] = '0';
	}
}
