/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:16:34 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 22:10:50 by enikole          ###   ########.fr       */
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

# define HEIGHT 1000
# define WIDTH 2000

typedef struct		s_stack
{
	int				*data;
	int				size;
}					t_stack;

typedef struct		s_max
{
	int				max;
	struct s_max	*next;
}					t_max;

typedef struct		s_image
{
	void			*id;
	int				*data;
	int				size_line;
	int				bpp;
	int				endian;
}					t_image;

typedef struct		s_mlx
{
	float			c0;
	void			*id;
	void			*win;
	t_image			*img;
	t_stack			*a;
	t_stack			*b;
	int				w0;
	int				h0;
}					t_mlx;

char				push(t_stack *dst, t_stack *src, char *s);
char				swap(t_stack *stack, char *s);
char				rotate(t_stack *stack, char *s);
char				rev_rotate(t_stack *stack, char *s);

int					visualisation(int *ac, char ***av, t_stack *a);
int					reading_args_v(int *ac, char ***av, t_stack *a);
void				rewrite_a(t_stack *a);
void				draw(t_mlx *mlx);

char				reading_args(int *ac, char ***av, t_stack *a);
char				check_int(char *str);
char				check_duplicates(t_stack a);
void				check(t_stack a, t_stack b);
char				instruction(char *line, t_stack *a, t_stack *b);
void				free_av(char **av);

char				is_not_sort(t_stack stack);
void				five_sort_stack(t_stack *a, t_stack *b);
void				three_sort_stack(t_stack *a);
int					bubble_sort(int *stack, int len);
void				split_b(t_stack *a, t_stack *b, t_max **begin);
void				add_max(t_max **begin, int max);
void				del_max(t_max **begin);
int					stack_max(t_stack stack);
int					stack_min(t_stack stack);
void				split_a(t_stack *a, t_stack *b, int max, t_max **begin);
void				three_rot_a(t_stack *a, t_stack *b, int i);
void				three_sort_stack_a(t_stack *a, t_stack *b);
char				check_rot(t_stack *a, t_stack *b, int num, int med);
int					count_num(t_stack a, int max, int border);

#endif
