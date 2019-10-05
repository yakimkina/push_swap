/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 13:44:40 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 20:04:48 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int			key_press(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	return (1);
}

static	int			esc(void *param)
{
	exit(0);
}

static	int			reading_str_v(t_mlx *mlx)
{
	char			*line;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		instruction(line, mlx->a, mlx->b);
		draw(mlx);
	}
	free(line);
	return (1);
}

static	void		image(t_mlx *mlx, t_stack *a)
{
	mlx->a = a;
	mlx->b->data = NULL;
	mlx->b->size = 0;
	if (!(mlx->img = (t_image *)ft_memalloc(sizeof(t_image))))
		exit(0);
	if (!(mlx->img->id = mlx_new_image(mlx->id, WIDTH, HEIGHT)))
		exit(0);
	if (!(mlx->img->data = (int *)mlx_get_data_addr(mlx->img->id,
					&mlx->img->bpp, &mlx->img->size_line, &mlx->img->endian)))
		exit(0);
	mlx->w0 = WIDTH / (2 * a->size);
	mlx->h0 = HEIGHT / a->size;
	mlx->c0 = 255 / (float)(a->size);
}

int					visualisation(int *ac, char ***av, t_stack *a)
{
	int				fl;
	t_mlx			mlx;

	if (!(mlx.id = mlx_init()))
		exit(0);
	if (!(mlx.win = mlx_new_window(mlx.id, WIDTH, HEIGHT, "push_swap")))
		exit(0);
	fl = reading_args_v(ac, av, a);
	if (*ac || check_duplicates(*a))
		mlx_string_put(mlx.id, mlx.win, WIDTH / 2, HEIGHT / 2, 255, "Error");
	else
	{
		image(&mlx, a);
		rewrite_a(a);
		draw(&mlx);
	}
	mlx_hook(mlx.win, 2, 1L << 0, key_press, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, esc, &mlx);
	mlx_loop_hook(mlx.id, reading_str_v, &mlx);
	mlx_loop(mlx.id);
	return (fl);
}
