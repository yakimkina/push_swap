/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_summ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:15:47 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:51:31 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void			d_copy(char **str, t_double *list, t_form *per,
		t_double_cast d1)
{
	int			i;
	int			j;

	i = 0;
	if (d1.parts.sign == 1)
		(*str)[i++] = '-';
	else if (per->plus)
		(*str)[i++] = '+';
	else if (per->space)
		(*str)[i++] = ' ';
	j = 0;
	while (list->integer[j] != '\0')
		(*str)[i++] = list->integer[j++];
	if (per->prec != -1 || per->hash != 0)
		(*str)[i] = '.';
	i++;
	j = 0;
	while (list->frac[j] != '\0')
	{
		(*str)[i] = list->frac[j];
		i++;
		j++;
	}
}

static	void	init_summ(char *str1, char *str2, t_index *ind)
{
	ind->i1 = ft_strlen((const char*)(str1)) - 1;
	ind->i2 = ft_strlen((const char*)(str2)) - 1;
	ind->i = ind->i1 + ind->i2 + 1;
	ind->cloud = 0;
}

static	void	summ_mod(char **ans, t_index *ind, char *str1, char *str2)
{
	while (ind->i1 >= 0)
	{
		(*ans)[(ind->i)--] = ((str1[ind->i1] - 48) + ind->cloud) % 10 + 48;
		ind->cloud = ((str1[(ind->i1)--] - 48) + ind->cloud) / 10;
	}
	while (ind->i2 >= 0)
	{
		(*ans)[(ind->i)--] = ((str2[ind->i2] - 48) + ind->cloud) % 10 + 48;
		ind->cloud = ((str2[(ind->i2)--] - 48) + ind->cloud) / 10;
	}
}

char			*summ(char *str1, char *str2)
{
	t_index		ind;
	char		*ans;
	char		*tmp;

	init_summ(str1, str2, &ind);
	tmp = ft_strnew(ind.i + 1);
	ans = ft_strnew(ind.i + 1);
	while (ind.i1 >= 0 && ind.i2 >= 0)
	{
		ans[ind.i--] = ((str1[ind.i1] - 48) + (str2[ind.i2] - 48) + ind.cloud)
			% 10 + 48;
		ind.cloud = ((str1[ind.i1--] - 48) + (str2[ind.i2--] - 48) + ind.cloud)
			/ 10;
	}
	if (ind.i1 >= 0 || ind.i2 >= 0)
		summ_mod(&ans, &ind, str1, str2);
	if (ind.cloud != 0)
		ans[ind.i--] = ind.cloud + 48;
	tmp = (char *)ft_memcpy(tmp, &ans[ind.i + 1], ft_strlen(&ans[ind.i + 1]));
	free(ans);
	return (tmp);
}
