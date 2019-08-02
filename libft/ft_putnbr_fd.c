/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 14:38:14 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:54:08 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	int		fl;

	fl = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		fl = -1;
	}
	if ((n / 10) != 0)
		ft_putnbr_fd((n / 10) * fl, fd);
	ft_putchar_fd((n % 10) * fl + 48, fd);
}
