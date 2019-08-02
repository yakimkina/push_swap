/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 13:44:44 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:52:42 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			p_zero(char **buf, t_form *per)
{
	if (per->width)
	{
		(*buf) = (char *)ft_memalloc(per->width + 1);
		(*buf) = (char *)ft_memset((*buf), 32, per->width);
		if (per->minus)
		{
			(*buf)[0] = '0';
			(*buf)[1] = 'x';
		}
		else
		{
			(*buf)[per->width - 2] = '0';
			(*buf)[per->width - 1] = 'x';
		}
		return (per->width);
	}
	else
	{
		write(1, "0x", 2);
		return (0);
	}
}

int			o_case_else(char **buf, char *str, t_form *per, int l)
{
	int		fl;
	int		s;

	fl = (per->hash) ? (1) : (0);
	s = (str[0] - 48) ? (l + fl) : (l);
	(*buf) = (char *)ft_memalloc(l + 1);
	(*buf) = (char *)ft_memcpy((*buf), str, l);
	if (per->hash && (str[0] - 48))
		write(1, "0", 1);
	return (s);
}

int			u_case_else(char **buf, char *str, int l)
{
	(*buf) = (char *)ft_memalloc(l + 1);
	(*buf) = (char *)ft_memcpy((*buf), str, l);
	return (l);
}

int			fun_width(int w, char **buf)
{
	int		i;

	i = w;
	while (i--)
		(*buf)[i] = ' ';
	return (w);
}

void		width_num(int w, char **buf, char *str)
{
	if (str[0] == '-')
		(*buf)[--w] = '-';
	while (w--)
		(*buf)[w] = ' ';
}
