/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_csp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:10:15 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:51:46 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void				w_cpy(char **buf, char *str, int w, int n)
{
	int				i;

	i = n;
	while (n--)
		(*buf)[w - (i - n)] = str[n];
}

int					fun_c(int sym, t_form *per)
{
	int				n;
	int				s;
	char			*buf;

	s = 1;
	if (per->width && per->width <= MAX_INT)
	{
		buf = (char *)ft_memalloc(per->width + 1);
		s = fun_width(per->width, &buf);
		if (per->minus)
			minus(&buf, (char *)((unsigned char *)((&sym))), 1, per->width);
		else if (per->zero)
			zero(&buf, (char *)((unsigned char *)((&sym))), 1, per->width);
		else
			buf[per->width - 1] = (unsigned char)sym;
	}
	else if ((buf = (char *)ft_memalloc(2)))
		buf[0] = (unsigned char)sym;
	n = 0;
	while (n < s)
		write(1, &buf[n++], 1);
	free(buf);
	return (s);
}

int					fun_s(char *str, t_form *per)
{
	char			fl;
	int				l;
	int				s;
	char			*buf;

	l = s_prec(&str, per, &fl);
	if (per->width && per->width <= MAX_INT && per->width > l)
	{
		buf = (char *)ft_memalloc(per->width + 1);
		s = fun_width(per->width, &buf);
		if (per->minus)
			minus(&buf, str, l, per->width);
		else if (per->zero)
			zero(&buf, str, l, per->width);
		else
			w_cpy(&buf, str, per->width, l);
	}
	else
		s = u_case_else(&buf, str, l);
	ft_putstr(buf);
	free(buf);
	if (fl)
		free(str);
	return (s);
}

static	int			p_wid(char **buf, char *str, t_form *per, int l)
{
	char			*tmp;

	(*buf) = (char *)ft_memalloc(per->width - 1);
	if (per->prec > 0 && per->prec <= MAX_INT && per->prec > l)
		zero(buf, str, l, per->width - 2);
	else
		per->prec = 0;
	fun_width((int)(per->width - per->prec - 2), buf);
	if (!per->prec && per->minus && write(1, "0x", 2))
		minus(buf, str, l, per->width - 2);
	else if (per->minus && write(1, "0x", 2))
	{
		tmp = (char *)ft_memalloc(per->prec + 1);
		tmp = (char *)ft_memcpy(tmp, &((*buf)[per->width - per->prec - 2]),
					per->prec);
		minus(buf, tmp, per->prec, per->width - 2);
		free(tmp);
	}
	else if (!per->prec && per->zero && write(1, "0x", 2))
		zero(buf, str, l, per->width - 2);
	else
		p_without_flags(buf, str, per, l);
	return (per->width);
}

int					fun_p(char *str, t_form *per)
{
	int				l;
	int				s;
	char			*buf;

	l = ft_strlen(str);
	buf = NULL;
	if (!(str[0] - 48) && per->prec == -1)
	{
		if (!(s = p_zero(&buf, per)))
			return (2);
	}
	else if (per->prec && per->prec >= (per->width - 2) && per->prec <= MAX_INT
			&& per->prec > l && write(1, "0x", 2) && (s = per->prec + 2))
	{
		buf = (char *)ft_memalloc(per->prec + 1);
		zero(&buf, str, l, per->prec);
	}
	else if (per->width && per->width <= MAX_INT && (per->width - 2) > l)
		s = p_wid(&buf, str, per, l);
	else if (write(1, "0x", 2))
		s = u_case_else(&buf, str, l) + 2;
	print_and_free(&buf, &str, per->type);
	return (s);
}
