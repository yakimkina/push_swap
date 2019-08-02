/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 17:04:33 by bnigellu          #+#    #+#             */
/*   Updated: 2019/08/01 13:51:39 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int				percent(va_list *ptr, t_form *per)
{
	if (per->type == '%')
		return (perec(per));
	else if (per->type == 'c')
		return (fun_c(va_arg(*ptr, int), per));
	else if (per->type == 's')
		return (fun_s(va_arg(*ptr, char *), per));
	else if (per->type == 'p')
		return (fun_p(ft_ib(va_arg(*ptr, long int), 16), per));
	else if (per->type == 'd' || per->type == 'i' || per->type == 'D')
		return (mod_di(ptr, per));
	else if (per->type == 'o' || per->type == 'O')
		return (mod_o(ptr, per));
	else if (per->type == 'u' || per->type == 'U')
		return (mod_u(ptr, per));
	else if (per->type == 'x' || per->type == 'X')
		return (mod_x(ptr, per));
	else if ((per->type) == 'f')
	{
		if (per->mod[0] == 'L')
			return (fun_f((double)va_arg(*ptr, long double), per));
		return (fun_f(va_arg(*ptr, double), per));
	}
	return (-1);
}

int				ft_printf(const char *format, ...)
{
	int			tmp;
	int			i;
	int			sum;
	t_form		per;
	va_list		ptr;

	sum = 0;
	i = -1;
	va_start(ptr, format);
	while (format[++i])
	{
		if (format[i] == '%' && ++i)
		{
			ft_bzero((void *)(&per), sizeof(per));
			i += init(&per, &((char *)format)[i]);
			if ((tmp = percent(&ptr, &per)) == -1)
				(format[i] && ++sum) ? (write(1, &format[i], 1)) : (i--);
			else
				sum += tmp;
		}
		else if (++sum)
			write(1, &format[i], 1);
	}
	va_end(ptr);
	return (sum);
}
