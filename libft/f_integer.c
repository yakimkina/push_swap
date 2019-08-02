/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_integer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:08:34 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:51:08 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	char	*p_power(size_t p)
{
	char		*str;

	if (p == 0)
		return ("1");
	str = ft_strnew(p);
	str[0] = '2';
	p--;
	while (p != 0)
	{
		str = summ(str, str);
		p--;
	}
	return (str);
}

static	char	*count(char *str)
{
	ssize_t		i;
	char		*num;
	size_t		pow;

	i = ft_strlen((const char*)(str));
	num = ft_strnew(i);
	num[0] = '0';
	i--;
	pow = 0;
	while ((str[i] == '0' || str[i] == '1') && i >= 0)
	{
		if (str[i] == '1')
			num = summ(p_power(pow), num);
		pow++;
		i--;
	}
	return (num);
}

static	void	paste(char **str1, char *str2)
{
	size_t		i;

	i = 0;
	while (str2[i] != '\0')
	{
		(*str1)[i] = str2[i];
		i++;
	}
}

void			integer(t_double *list)
{
	if (list->first_2[0] == 'p')
	{
		list->integer = ft_strnew(ft_strlen((const char*)(list->first_2)) +
				ft_strlen((const char*)(list->second_int_2)));
		paste(&(list->integer), count(list->first_2));
	}
	else
	{
		list->integer = ft_strnew(ft_strlen((const char*)(list->second_int_2)));
		list->integer[0] = '0';
	}
	list->integer = summ(list->integer, count(list->second_int_2));
}
