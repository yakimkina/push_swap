/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:16:34 by enikole           #+#    #+#             */
/*   Updated: 2019/09/06 14:29:43 by enikole          ###   ########.fr       */
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
	int				*data;
	int				size;
}					t_stack;

char				rec_str(int *ac, char ***av, t_stack *a);
char				check_int(char *str);
char				check_dupl(t_stack a);
char				swap(t_stack *stack, char s);
char				push(t_stack *dst, t_stack *src, char *s);
char				rotate(t_stack *stack, char s);
char				rev_rotate(t_stack *stack, char s);
void				split_a(t_stack *a, t_stack *b, int max);


#endif
