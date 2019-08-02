/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_beauty.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:32:36 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:48:04 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void	case_1(t_double *list, int len, int i)
{
	char		*str;
	char		*tmp;

	str = ft_strnew(i);
	tmp = ft_strnew(len);
	tmp = ft_memset(tmp, '0', len);
	tmp[i] = '1';
	list->frac = summ(list->frac, tmp);
	free(tmp);
	if (list->frac[0] == '1')
		list->integer = summ(list->integer, "1");
	str = ft_strncpy(str, &(list->frac[1]), i);
	free(list->frac);
	list->frac = str;
}

static	void	case_2(t_double *list, int i)
{
	char		*str;
	int			k;

	str = ft_strnew(i);
	k = 0;
	while (k != i)
	{
		str[k] = list->frac[k + 1];
		k++;
	}
	free(list->frac);
	list->frac = str;
}

static	void	case_3(t_double *list, int i)
{
	char		*str;
	int			k;

	str = ft_strnew(i);
	str = ft_memset(str, '0', i);
	k = 0;
	while (list->frac[k + 1] != '\0')
	{
		str[k] = list->frac[k + 1];
		k++;
	}
	free(list->frac);
	list->frac = str;
}

static	void	case_4(t_double *list, int len)
{
	char		*str;

	str = ft_strnew(0);
	if (list->frac[1] == '5')
	{
		len--;
		while (len != 1)
		{
			if (list->frac[len] != '0')
			{
				list->integer = summ(list->integer, "1");
				break ;
			}
			len--;
		}
	}
	else if (list->frac[1] > '5')
		list->integer = summ(list->integer, "1");
	free(list->frac);
	list->frac = str;
}

char			*beuty_double(t_form *per, t_double *list, t_double_cast d1)
{
	int			len;
	int			i;
	char		*str;
	int			k;

	i = (per->prec) ? (per->prec) : (6);
	len = ft_strlen((const char*)(list->frac));
	if ((i < len && i != -1) && ((((list->frac[i] - '0') % 2 == 0) &&
				(list->frac[i + 1] >= '6')) || (((list->frac[i] - '0') % 2 == 1)
					&& (list->frac[i + 1] >= '5'))))
		case_1(list, len, i);
	else if (i < len && i != -1)
		case_2(list, i);
	else if (i != -1)
		case_3(list, i);
	else
		case_4(list, len);
	k = ft_strlen((const char*)(list->integer)) + 1 + i;
	if (d1.parts.sign == 1 || per->plus != 0 || per->space != 0)
		k++;
	if (per->hash != 0 && i == -1)
		k++;
	str = ft_strnew(k);
	d_copy(&str, list, per, d1);
	return (str);
}
