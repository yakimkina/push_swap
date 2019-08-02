/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:04:48 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:52:36 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		print_and_free(char **buf, char **str, char t)
{
	if (t == 'X')
		ft_putstr(ft_strupcase(*buf));
	else
		ft_putstr(*buf);
	free(*buf);
	free(*str);
}

void		hminus(char **buf, char *s, int fl, int w)
{
	int		l;

	l = ft_strlen(s);
	while (w-- > l)
		(*buf)[w] = ' ';
	while (l--)
		(*buf)[l + fl] = s[l];
	if (fl == 1)
		(*buf)[0] = '0';
	if (fl == 2)
	{
		(*buf)[0] = '0';
		(*buf)[1] = 'x';
	}
}

void		minus(char **buf, char *s, int n, int w)
{
	while (w-- > n)
		(*buf)[w] = ' ';
	while (n--)
		(*buf)[n] = s[n];
}

void		zero(char **buf, char *s, int n, int w)
{
	while (n-- && w--)
		(*buf)[w] = s[n];
	while (w--)
		(*buf)[w] = '0';
}

void		zero_num(char **buf, char *s, int n, int w)
{
	while (n-- && w--)
	{
		if (s[n] == '-')
			(*buf)[w] = '0';
		else
			(*buf)[w] = s[n];
	}
	while (w--)
		(*buf)[w] = '0';
}
