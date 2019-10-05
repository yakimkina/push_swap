/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:44:40 by enikole           #+#    #+#             */
/*   Updated: 2019/09/30 13:44:42 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int			*bubble_sort(int *stack, int len)
{
	int				i;
	int				j;
	int				tmp;
	int				*mas;

	if (!(mas = (int *)malloc(sizeof(int) * len)))
		exit (0);
	i = 0;
	while (i < len)
	{
		mas[i] = stack[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1))
		{
			if (mas[j] > mas[j + 1])
			{
				tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (mas);
}

static	void		rewrite_a(t_stack *a)
{
	int 			i;
	int				j;
	int 			*mas;

	mas = bubble_sort(a->data, a->size);
	i = 0;
	while (i < a->size)
	{
		j = 0;
		while (a->data[i] != mas[j])
			j++;
		a->data[i] = j + 1;
		i++;
	}
	free(mas);
}

static  int		    reading_args_v(int *ac, char ***av, t_stack *a)
{
    int				i;
    int				fl;
    long	int		curr;

    fl = 2;
    i = 0;
    //write(1, "hear", 4);
    if (*ac == 3)
    {
        i = 2;
        *ac = ft_wordcount((*av)[i], ' ');
        *av = ft_strsplit((*av)[i], ' ');
        fl = 0;
    }
    if (i == 0)
	{
    	a->size = *ac - 2;
    	*ac = *ac - 2;
	}
    else
    	a->size = *ac;
    a->data = (int *)malloc(sizeof(int) * a->size);
    i = 0;
    while (i < (*ac))
    {
        if (check_int((*av)[i + fl]) && ((curr = ft_atoi_long((*av)[i + fl])) <=
                                         MAX_INT && curr >= MIN_INT))
            (a->data)[i++] = curr;
        else
            break ;
    }
    *ac -= i;
    return (fl);
}

int					reading_str_v(t_mlx *mlx)
{
	char			fl;
	int				curr;
	char			*line;

	fl = 1;
	line = NULL;
	if ((curr = get_next_line(0, &line)) > 0)
	{
		fl = instruction(line, mlx->a, mlx->b);
		draw(mlx);
	}
	free(line);
	return (1);
}

int                 key_press(int keycode, void *param)
{
    if (keycode == 53)
        exit (0);
    return (1);
}

int                 esc(void *param)
{
    exit (0);
}

int                 visualisation(int *ac, char ***av, t_stack *a)
{
    int             fl;
    t_mlx           mlx;

    if (!(mlx.id = mlx_init()))
    	exit (0);
    if (!(mlx.win = mlx_new_window(mlx.id, WIDTH, HEIGHT, "push_swap")))
    	exit (0);
    fl = reading_args_v(ac, av, a);
    if (*ac || check_dupl(*a))
    	mlx_string_put(mlx.id, mlx.win, WIDTH / 2, HEIGHT / 2, 255, "Error");
    else
    {
        mlx.a = a;
    	mlx.b->data = NULL;
    	mlx.b->size = 0;
    	if (!(mlx.img = (t_image *)malloc(sizeof(t_image))))
    		exit (0);
        if (!(mlx.img->id = mlx_new_image(mlx.id, WIDTH, HEIGHT)))
        	exit (0);
		if (!(mlx.img->data = (int *)mlx_get_data_addr(mlx.img->id, &mlx.img->bpp, &mlx.img->size_line, &mlx.img->endian)))
			exit (0);
        rewrite_a(a);
        mlx.w0 = WIDTH / (2 * a->size);
        mlx.h0 = HEIGHT / a->size;
        mlx.c0 = 255 / (float)(a->size);
        draw(&mlx);
	}
    mlx_hook(mlx.win, 2, 1L << 0, key_press, &mlx);
    mlx_hook(mlx.win, 17, 1L << 17, esc, &mlx);
    mlx_loop_hook(mlx.id, reading_str_v, &mlx);
    mlx_loop(mlx.id);
    return (fl);
}
