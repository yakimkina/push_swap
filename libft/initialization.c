/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 00:19:45 by enikole           #+#    #+#             */
/*   Updated: 2019/08/01 13:53:45 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static	void	zero_init(int *i, int *fl, int *fl1, int *fl2)
{
	(*i) = -1;
	(*fl) = 0;
	(*fl1) = 1;
	(*fl2) = 1;
}

static	int		ft_strnchr(char c, char *s1)
{
	int			i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int		mod_init(t_form *per, char *s)
{
	int			i;
	int			fl;
	int			fl1;

	i = 0;
	fl = 0;
	fl1 = 1;
	while (ft_strnchr(s[i], "-+ #0123456789.hlLjz") && s[i] != '%' && s[i])
	{
		if (s[i] == 'h' || s[i] == 'l' || s[i] == 'j' || s[i] == 'z' ||
				s[i] == 'L')
		{
			(per->mod)[0] = s[i];
			if (++i && ((s[i] == 'h' && s[i - 1] != 'l') || (s[i] == 'l' &&
							s[i - 1] != 'h')) && (s[i - 1] != 'z' ||
							s[i - 1] != 'j' || s[i - 1] != 'L'))
				(per->mod)[1] = s[i++];
			i--;
		}
		else if (fl1 && ((fl = i) == i))
			fl1 = 0;
		i++;
	}
	return (fl);
}

static	int		flag_init(t_form *per, char *s, int *fl)
{
	int			fl1;
	int			fl2;
	int			i;

	zero_init(&i, fl, &fl1, &fl2);
	while (ft_strnchr(s[++i], "-+ #0123456789.hlLjz") && s[i] != '%' && s[i])
	{
		if (fl1 && s[i] == '.')
			flags_dot(i, fl, &fl1, &fl2);
		else if (fl1 && (s[i] > '0' && s[i] <= '9'))
			flags_dot(i, fl, &fl1, &fl2);
		else if (s[i] == '-')
			(per->minus)++;
		else if (s[i] == '+')
			(per->plus)++;
		else if (s[i] == ' ')
			(per->space)++;
		else if (s[i] == '#')
			(per->hash)++;
		else if (s[i] == '0' && fl2)
			(per->zero)++;
		else if (fl1 && (((*fl) = i) == i))
			fl1 = 0;
	}
	return ((*fl));
}

int				init(t_form *per, char *s)
{
	int			i;
	int			fl;

	i = flag_init(per, s, &fl);
	i += mod_init(per, &s[i]);
	while (s[i] && s[i] != '.' && s[i] <= '0' && s[i] > '9')
		i++;
	if (s[i] > '0' && s[i] <= '9')
		per->width = ft_atoi(&s[i]);
	while (s[i] && s[i] != '.' && s[i] != '%' && ft_strnchr(s[i],
				"-+ #0123456789.hlLjz"))
		i++;
	if (s[i] == '.' && ++i)
	{
		while (s[i] <= '0' && s[i] > '9')
			i++;
		per->prec = ft_atoi(&s[i]);
		if (!per->prec)
			per->prec = -1;
		while (s[i] && s[i] != '%' && ft_strnchr(s[i], "-+ #0123456789.hlLjz"))
			i++;
	}
	if (ft_strnchr(s[i], "cspdDioOuUxXf%"))
		per->type = s[i];
	return (i);
}
