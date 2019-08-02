/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 00:20:01 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:53:22 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void	only_wid(char **buf, char *str, t_form *per, int l)
{
	int			i;
	int			fl;

	fl = (str[0] == '-') ? (1) : (0);
	per->prec = l - fl;
	i = per->width;
	while (l-- && i--)
		(*buf)[i] = str[l];
}

static	int		check(char **buf, char *str, t_form *per)
{
	int			i;
	int			flag;
	int			zn;

	flag = 0;
	zn = (str[0] == '-') ? (-1) : (1);
	if (zn > 0 && (per->plus || per->space))
	{
		i = 0;
		while ((*buf)[i] == ' ')
			i++;
		i--;
		if (per->plus)
			(*buf)[i] = '+';
		flag = 1;
	}
	else if (zn < 0)
		flag = 1;
	return (flag);
}

static	int		di_per(char **buf, char **str, t_form *per, int l)
{
	int			s;
	char		zn;

	s = 0;
	zn = ((*str)[0] == '-') ? (1) : (0);
	(*buf) = (char *)ft_memalloc(per->prec + 1);
	if (zn && ++s && write(1, "-", 1))
		(*str)[0] = '0';
	else if (per->plus && ++s)
		write(1, "+", 1);
	else if (per->space && ++s)
		write(1, " ", 1);
	zero(buf, (*str), l, per->prec);
	return (s);
}

static	int		di_wid(char **buf, char *str, t_form *per, int l)
{
	int			fl;
	int			prec;
	char		zn;

	prec = per->prec;
	zn = (str[0] == '-') ? (1) : (0);
	(*buf) = (char *)ft_memalloc(per->width + 1);
	if (per->prec > 0 && per->prec <= MAX_INT && per->prec > (l - zn))
		zero_num(buf, str, l, per->width);
	else
		only_wid(buf, str, per, l);
	width_num((int)(per->width - per->prec), buf, str);
	fl = check(buf, str, per);
	if (per->minus)
		di_minus(buf, fl, per);
	else if (!prec && per->zero)
	{
		zn = (*buf)[per->width - per->prec - fl];
		zero_num(buf, str, l, per->width);
		if (fl)
			(*buf)[0] = zn;
	}
	return (per->width);
}

int				fun_di(char *str, t_form *per)
{
	int			zn;
	int			s;
	int			l;
	char		*buf;

	l = ft_strlen(str);
	zn = (str[0] == '-') ? (1) : (0);
	if (!(str[0] - 48) && l == (1 + zn) && per->prec == -1)
	{
		if (!(s = fun_zero(&buf, per)))
			return (0);
	}
	else if (per->prec && per->prec >= per->width && per->prec <= MAX_INT
			&& per->prec > (l - zn) && (s = per->prec))
		s += di_per(&buf, &str, per, l);
	else if (per->width && per->width <= MAX_INT && per->width > l)
		s = di_wid(&buf, str, per, l);
	else
		s = di_case_else(&buf, str, per, l);
	ft_putstr(buf);
	free(buf);
	free(str);
	return (s);
}
