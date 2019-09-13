/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:02:00 by enikole           #+#    #+#             */
/*   Updated: 2019/09/11 21:55:05 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_stack(t_stack a, t_stack b)
{
	int		i;

	i = 0;
	printf("\n");
	while (i < a.size)
	{
		printf("a[%i] = %d", i, a.data[i]);
		if (i < b.size)
			printf("        b[%i] = %d\n", i, b.data[i]);
		else
			printf("\n");
		i++;
	}
	//printf("STACK B\n");
	/*i = 0;
	while (i < b.size)
	{
		printf("b[%i] = %d\n", i, b.data[i]);
		i++;
	} */
}