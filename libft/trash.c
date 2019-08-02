/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:22:09 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:53:56 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		di_minus(char **buf, int fl, t_form *per)
{
	char	*tmp;

	tmp = (char *)ft_memalloc(per->prec + fl + 1);
	tmp = (char *)ft_memcpy(tmp, &((*buf)[per->width - per->prec - fl]),
			per->prec + fl);
	minus(buf, tmp, per->prec + fl, per->width);
	free(tmp);
}

int			di_case_else(char **buf, char *str, t_form *per, int l)
{
	int		fl;
	char	zn;
	int		s;

	fl = 0;
	zn = (str[0] == '-') ? (1) : (0);
	if (!zn && (per->plus || per->space))
		fl = 1;
	(*buf) = (char *)ft_memalloc(l + fl + 1);
	s = l + fl;
	while (l--)
		(*buf)[l + fl] = str[l];
	if (fl)
		(*buf)[0] = (per->plus) ? ('+') : (' ');
	return (s);
}

int			fun_zero(char **buf, t_form *per)
{
	if (per->width)
	{
		(*buf) = (char *)ft_memalloc(per->width + 1);
		(*buf) = (char *)ft_memset((*buf), 32, per->width);
		return (per->width);
	}
	return (0);
}

int			s_prec(char **str, t_form *per, char *fl)
{
	int		l;
	char	*buf;

	*fl = 0;
	if (!(*str))
	{
		(*str) = (char *)ft_memalloc(7);
		(*str) = (char *)ft_memcpy((*str), "(null)", 7);
		*fl = 1;
	}
	l = ft_strlen((*str));
	if (per->prec == -1)
		return (0);
	else if (per->prec > 0 && per->prec < l)
	{
		buf = (char *)ft_memalloc(per->prec + 1);
		buf = (char *)ft_memcpy(buf, (*str), per->prec);
		buf[per->prec] = '\0';
		(*str) = (char *)ft_memalloc(per->prec + 1);
		(*str) = (char *)ft_memcpy((*str), buf, per->prec);
		free(buf);
		l = per->prec;
	}
	return (l);
}

void		p_without_flags(char **buf, char *str, t_form *per, int l)
{
	if (per->prec)
		l = per->prec;
	if ((per->width - l - 4) == -1)
		write(1, " 0", 2);
	else
	{
		write(1, "  ", 2);
		(*buf)[per->width - l - 4] = '0';
	}
	(*buf)[per->width - l - 3] = 'x';
	if (!per->prec)
		w_cpy(buf, str, per->width - 2, l);
}
