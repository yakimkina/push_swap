/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_fraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 16:22:12 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:51:02 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	char	*n_while(char **tmp, int j, int l, int k)
{
	int			len;
	char		*str;
	int			cloud;

	cloud = 0;
	len = l;
	while (j--)
	{
		str = ft_strnew(k);
		str = (char *)ft_memset(str, 48, k);
		while (k--)
			if (l--)
			{
				str[k] = (((*tmp)[l] - 48) * 5 + cloud) % 10 + 48;
				cloud = (((*tmp)[l] - 48) * 5 + cloud) / 10;
			}
			else
				str[k] = cloud + 48;
		free(*tmp);
		if (j)
			(*tmp) = str;
		l = ++len;
		k = len + 1;
	}
	return (str);
}

static	char	*n_power(char **tmp, int j)
{
	int			l;
	int			k;

	l = ft_strlen(*tmp);
	k = l + 1;
	return (n_while(tmp, j, l, k));
}

static	void	equality(char **tmp, char **str)
{
	int			i;
	int			i1;

	i = ft_strlen((const char*)(*tmp));
	i1 = ft_strlen((const char*)(*str));
	if (i > i1)
	{
		while (i1 < i)
		{
			(*str)[i1] = '0';
			i1++;
		}
	}
}

void			fraction(t_double *list)
{
	char		*tmp;
	int			i;
	int			j;

	i = 0;
	list->frac = (char *)ft_strnew(ft_strlen((const char*)(list->second_frac_2))
			+ 1);
	list->frac[0] = '0';
	tmp = (char *)malloc(2);
	tmp[0] = '1';
	tmp[1] = '\0';
	j = 1;
	while (list->second_frac_2[i] != '\0')
	{
		if (list->second_frac_2[i] == '1')
		{
			tmp = n_power(&tmp, j);
			equality(&tmp, &(list->frac));
			list->frac = summ(list->frac, tmp);
			j = 1;
		}
		else
			j++;
		i++;
	}
}
