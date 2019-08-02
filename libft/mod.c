/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 14:38:39 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:53:51 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			mod_di(va_list *ptr, t_form *per)
{
	if (per->mod[0] == 'h' && per->type != 'D')
	{
		if (per->mod[1] == 'h')
			return (fun_di(ft_ib((char)va_arg(*ptr, int), 10), per));
		return (fun_di(ft_ib((short)va_arg(*ptr, int), 10), per));
	}
	else if (per->mod[0] == 'l')
	{
		if (per->mod[1] == 'l')
			return (fun_di(ft_ib(va_arg(*ptr, long long), 10), per));
		return (fun_di(ft_ib(va_arg(*ptr, long), 10), per));
	}
	else if (per->mod[0] == 'z')
		return (fun_di(ft_ib(va_arg(*ptr, ssize_t), 10), per));
	else if (per->mod[0] == 'j')
		return (fun_di(ft_ib(va_arg(*ptr, intmax_t), 10), per));
	else if (per->type == 'D')
		return (fun_di(ft_ib(va_arg(*ptr, long), 10), per));
	else
		return (fun_di(ft_ib(va_arg(*ptr, int), 10), per));
}

int			mod_u(va_list *ptr, t_form *per)
{
	if (per->mod[0] == 'h' && per->type != 'U')
	{
		if (per->mod[1] == 'h')
			return (fun_u(ft_uib((unsigned char)va_arg(*ptr, int), 10), per));
		return (fun_u(ft_uib((unsigned short)va_arg(*ptr, int), 10), per));
	}
	else if (per->mod[0] == 'l')
	{
		if (per->mod[1] == 'l')
			return (fun_u(ft_uib(va_arg(*ptr, unsigned long long), 10), per));
		return (fun_u(ft_uib(va_arg(*ptr, unsigned long), 10), per));
	}
	else if (per->mod[0] == 'z')
		return (fun_u(ft_uib(va_arg(*ptr, size_t), 10), per));
	else if (per->mod[0] == 'j')
		return (fun_u(ft_uib(va_arg(*ptr, uintmax_t), 10), per));
	else if (per->type == 'U')
		return (fun_u(ft_uib(va_arg(*ptr, unsigned long), 10), per));
	else
		return (fun_u(ft_uib(va_arg(*ptr, unsigned int), 10), per));
}

int			mod_o(va_list *ptr, t_form *per)
{
	if (per->mod[0] == 'h' && per->type != 'O')
	{
		if (per->mod[1] == 'h')
			return (fun_o(ft_uib((unsigned char)va_arg(*ptr, int), 8), per));
		return (fun_o(ft_uib((unsigned short)va_arg(*ptr, int), 8), per));
	}
	else if (per->mod[0] == 'l')
	{
		if (per->mod[1] == 'l')
			return (fun_o(ft_uib(va_arg(*ptr, unsigned long long), 8), per));
		return (fun_o(ft_uib(va_arg(*ptr, unsigned long), 8), per));
	}
	else if (per->mod[0] == 'z')
		return (fun_o(ft_uib(va_arg(*ptr, size_t), 8), per));
	else if (per->mod[0] == 'j')
		return (fun_o(ft_uib(va_arg(*ptr, uintmax_t), 8), per));
	else if (per->type == 'O')
		return (fun_o(ft_uib(va_arg(*ptr, unsigned long), 8), per));
	else
		return (fun_o(ft_uib(va_arg(*ptr, unsigned int), 8), per));
}

int			mod_x(va_list *ptr, t_form *per)
{
	if (per->mod[0] == 'h')
	{
		if (per->mod[1] == 'h')
			return (fun_x(ft_uib((unsigned char)va_arg(*ptr, int), 16), per));
		return (fun_x(ft_uib((unsigned short)va_arg(*ptr, int), 16), per));
	}
	else if (per->mod[0] == 'l')
	{
		if (per->mod[1] == 'l')
			return (fun_x(ft_uib(va_arg(*ptr, unsigned long long), 16), per));
		return (fun_x(ft_uib(va_arg(*ptr, unsigned long), 16), per));
	}
	else if (per->mod[0] == 'z')
		return (fun_x(ft_uib(va_arg(*ptr, size_t), 16), per));
	else if (per->mod[0] == 'j')
		return (fun_x(ft_uib(va_arg(*ptr, uintmax_t), 16), per));
	return (fun_x(ft_uib(va_arg(*ptr, unsigned int), 16), per));
}
