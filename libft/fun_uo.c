/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_uo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:03:22 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:53:31 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	int		o_zero(char **buf, t_form *per)
{
	if (per->width)
	{
		(*buf) = (char *)ft_memalloc(per->width + 1);
		(*buf) = (char *)ft_memset((*buf), 32, per->width);
		if (per->hash && !(per->minus))
			(*buf)[per->width - 1] = '0';
		else if (per->hash && per->minus)
			(*buf)[0] = '0';
		return (per->width);
	}
	else
	{
		if (per->hash)
			write(1, "0", 1);
		return (0);
	}
}

static	int		u_wid(char **buf, char *str, t_form *per, int l)
{
	char		*tmp;

	(*buf) = (char *)ft_memalloc(per->width + 1);
	if (per->prec > 0 && per->prec <= MAX_INT && per->prec > l)
		zero(buf, str, l, per->width);
	fun_width((int)(per->width - per->prec), buf);
	if ((per->prec <= l || per->prec > MAX_INT) && per->minus)
		minus(buf, str, l, per->width);
	else if (per->minus)
	{
		tmp = (char *)ft_memalloc(per->prec + 1);
		tmp = (char *)ft_memcpy(tmp, &((*buf)[per->width - per->prec]),
				per->prec);
		minus(buf, tmp, per->prec, per->width);
		free(tmp);
	}
	else if (!per->prec && per->zero)
		zero(buf, str, l, per->width);
	else
	{
		if (per->prec <= l || per->prec >= MAX_INT)
			w_cpy(buf, str, per->width, l);
	}
	return (per->width);
}

int				fun_u(char *str, t_form *per)
{
	int			l;
	int			s;
	char		*buf;

	l = ft_strlen(str);
	if (!(str[0] - 48) && l == 1 && per->prec == -1)
	{
		if (!(s = fun_zero(&buf, per)))
			return (0);
	}
	else if (per->prec && per->prec >= per->width && per->prec <= MAX_INT &&
			per->prec > l && (s = per->prec))
	{
		buf = (char *)ft_memalloc(per->prec + 1);
		zero(&buf, str, l, per->prec);
	}
	else if (per->width && per->width <= MAX_INT && per->width > l)
		s = u_wid(&buf, str, per, l);
	else
		s = u_case_else(&buf, str, l);
	ft_putstr(buf);
	free(buf);
	free(str);
	return (s);
}

static	int		o_wid(char **buf, char *str, t_form *per, int l)
{
	(*buf) = (char *)ft_memalloc(per->width + 1);
	per->hash = (per->hash && !(!(str[0] - 48) && l == 1)) ? (1) : (0);
	if (per->prec > 0 && per->prec <= MAX_INT && per->prec > l)
		zero(buf, str, l, per->width);
	fun_width((int)(per->width - per->prec), buf);
	if ((per->prec <= l || per->prec > MAX_INT) && per->minus)
		hminus(buf, str, per->hash, per->width);
	else if (per->minus)
		di_minus(buf, 0, per);
	else if (!per->prec && per->zero)
		zero(buf, str, l, per->width);
	else
	{
		if (per->prec <= l || per->prec >= MAX_INT)
			w_cpy(buf, str, per->width, l);
		if (per->hash)
			(*buf)[per->width - l - 1] = '0';
	}
	return (per->width);
}

int				fun_o(char *str, t_form *per)
{
	int			l;
	int			s;
	int			fl;
	char		*buf;

	fl = (per->hash) ? (1) : (0);
	l = ft_strlen(str);
	if (!(str[0] - 48) && l == 1 && per->prec == -1)
	{
		if (!(s = o_zero(&buf, per)))
			return (fl);
	}
	else if (per->prec && per->prec >= per->width && per->prec <= MAX_INT
			&& per->prec > l && (s = per->prec))
	{
		buf = (char *)ft_memalloc(per->prec + 1);
		zero(&buf, str, l, per->prec);
	}
	else if (per->width && per->width <= MAX_INT && per->width > l)
		s = o_wid(&buf, str, per, l);
	else
		s = o_case_else(&buf, str, per, l);
	print_and_free(&buf, &str, per->type);
	return (s);
}
