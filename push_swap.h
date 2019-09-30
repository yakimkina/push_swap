/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:16:34 by enikole           #+#    #+#             */
/*   Updated: 2019/09/11 21:31:24 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/includes/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "mlx/mlx.h"
#include "stdio.h" //DELETE THIS
# define HEIGHT 1000
# define WIDTH 2000

typedef struct		s_stack
{
	int				*data;
	int				size;
}					t_stack;

typedef struct      s_max
{
    int             max;
    struct s_max    *next;
}                   t_max;

typedef struct      s_image
{
	void			*id;
	int 			*data;
	int 			size_line;
	int 			bpp;
	int 			endian;
}                   t_image;

typedef struct      s_mlx
{
    void            *id;
    void            *win;
    t_image         *img;
    t_stack			*a;
    t_stack			*b;
    int				w0;
    int 			h0;
}                   t_mlx;

char				reading_args(int *ac, char ***av, t_stack *a);
void				check(t_stack a, t_stack b);
char				check_int(char *str);
char				check_dupl(t_stack a);
char				instructions(char *line, t_stack *a, t_stack *b);
char				swap(t_stack *stack, char *s);
char				push(t_stack *dst, t_stack *src, char *s);
char				rotate(t_stack *stack, char *s);
char				rev_rotate(t_stack *stack, char *s);
void				split_a(t_stack *a, t_stack *b, int max, t_max **begin);

int                 visualisation(int *ac, char ***av, t_stack *a);
void				draw(t_mlx mlx);

#endif
