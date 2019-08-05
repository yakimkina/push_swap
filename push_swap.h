/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:16:34 by enikole           #+#    #+#             */
/*   Updated: 2019/08/05 09:53:35 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

#include "stdio.h" //DELETE THIS

typedef struct		s_stack
{
	int				*a;
	int				*b;
	int				la;
	int				lb;
}					t_stack;

char		r_inst(char *line, t_stack *stack);
char		swap(int *stack, int len);
char		push(int **dst, int **src, int *len_dst, int *len_src);

#endif