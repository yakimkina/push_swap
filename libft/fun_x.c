/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 22:49:20 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:53:37 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void	x_flag_zero(char **buf, char *str, t_form *per, int l)
{
	int			fl;

	fl = (per->hash) ? (2) : (0);
	if (!per->prec && per->zero)
	{
		zero(buf, str, l, per->width);
		if (fl && ((*buf)[0] = '0'))
			(*buf)[1] = 'x';
	}
	else
	{
		if (per->prec <= l)
			w_cpy(buf, str, per->width, l);
		else
		{
			if (per->prec > l)
				l = per->prec;
		}
		if (fl)
		{
			(*buf)[per->width - l - 2] = '0';
			(*buf)[per->width - l - 1] = 'x';
		}
	}
}

int				perec(t_form *per)
{
	int			s;
	char		p;
	char		*buf;

	p = '%';
	s = 1;
	if (per->width && per->width <= MAX_INT)
	{
		buf = (char *)ft_memalloc(per->width + 1);
		s = fun_width((int)(per->width), &buf);
		if (per->minus)
			minus(&buf, &p, 1, per->width);
		else if (per->zero)
			zero(&buf, &p, 1, per->width);
		else
			buf[per->width - 1] = p;
	}
	else if ((buf = (char *)ft_memalloc(2)))
		buf[0] = p;
	ft_putstr(buf);
	free(buf);
	return (s);
}

static	int		x_per(char **buf, char *str, t_form *per, int l)
{
	int			s;

	s = 0;
	(*buf) = (char *)ft_memalloc(per->prec + 1);
	zero(buf, str, l, per->prec);
	if (per->hash && per->type == 'x' && (s += 2))
		write(1, "0x", 2);
	else if (per->hash && per->type == 'X' && (s += 2))
		write(1, "0X", 2);
	return (s);
}

static	int		x_wid(char **buf, char *str, t_form *per, int l)
{
	int			fl;
	char		*tmp;

	(*buf) = (char *)ft_memalloc(per->width + 1);
	fl = (per->hash) ? (2) : (0);
	if (per->prec > 0 && per->prec <= MAX_INT && per->prec > l)
		zero(buf, str, l, per->width);
	fun_width((int)(per->width - per->prec), buf);
	if ((per->prec <= l || per->prec > MAX_INT) && per->minus)
		hminus(buf, str, fl, per->width);
	else if (per->minus)
	{
		tmp = (char *)ft_memalloc(per->prec + fl + 1);
		tmp = (char *)ft_memcpy(tmp, &((*buf)[per->width - per->prec]),
				per->prec);
		hminus(buf, tmp, fl, per->width);
		free(tmp);
	}
	else
		x_flag_zero(buf, str, per, l);
	return (per->width);
}

int				fun_x(char *str, t_form *per)
{
	int			l;
	int			s;
	int			fl;
	char		*buf;

	fl = (per->hash) ? (2) : (0);
	l = ft_strlen(str);
	if (!(str[0] - 48) && l == 1 && (per->hash || per->prec == -1))
	{
		s = count_l(per, &l);
		x_zero(&buf, str, per, l);
	}
	else if (per->prec > 0 && ((per->prec + fl) >= per->width)
			&& per->prec <= MAX_INT && per->prec > l && (s = per->prec))
		s += x_per(&buf, str, per, l);
	else if (per->width && per->width <= MAX_INT && (per->width > (l + fl)))
		s = x_wid(&buf, str, per, l);
	else
		s = x_case_else(&buf, str, per, l);
	print_and_free(&buf, &str, per->type);
	return (s);
}
