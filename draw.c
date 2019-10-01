/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:57:09 by enikole           #+#    #+#             */
/*   Updated: 2019/09/30 16:57:11 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		draw_a(t_mlx *mlx, int step)
{
	int 	x;
	int 	y;

	y = HEIGHT - (step + 1) * mlx->h0;
	while (y < HEIGHT - step * mlx->h0)
	{
		x = 0;
		while (x < mlx->w0 * mlx->a->data[mlx->a->size - step - 1])
		{
			mlx->img->data[x + y * (mlx->img->size_line / 4)] = 255;
			x++;
		}
		y++;
	}
}

void		draw_b(t_mlx *mlx, int step)
{
	int 	x;
	int 	y;

	y = HEIGHT - (step + 1) * mlx->h0;
	while (y < HEIGHT - step * mlx->h0)
	{
		x = WIDTH / 2;
		while (x < WIDTH / 2 + mlx->w0 * mlx->b->data[mlx->b->size - step - 1] - 1)
		{
			mlx->img->data[x + y * mlx->img->size_line / 4] = 255;
			x++;
		}
		y++;
	}
}

void		draw(t_mlx *mlx)
{
	int 	step;

	ft_bzero(mlx->img->data, WIDTH * HEIGHT * 4);
	step = -1;
	while (++step < mlx->a->size)
	{
		draw_a(mlx, step);
		if (mlx->b->size)
			draw_b(mlx, step);
	}
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img->id, 0, 0);
}
