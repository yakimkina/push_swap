/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:21:52 by enikole           #+#    #+#             */
/*   Updated: 2019/08/05 00:55:55 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		r_inst(char *line, t_stack *stack)
{
	if (line[1] == 'a' && line[2] == 0)
	else if (line[1] == 'b' && line[2] == 0)
	else if (line[1] == 'r')
	{
		if (line[2] == 'a' && line[3] == 0)
		else if (line[2] == 'b' && line[3] == 0)
		else if (line[2] == 'r' && line[3] == 0)
		else if (line[2] == 0)
	}
	return (0);
}

char		swap(int *stack, int len)
{
	int		tmp;

	//if (stack[0] = )
	tmp = stack[0];
	stack[0] = stack[1];
	stack[1] = tmp;
	return (1);
}