/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 16:57:09 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 20:10:32 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int		set_colors(unsigned char o, unsigned char r, unsigned char g,
		unsigned char b)
{
	int			i;
	int			tmp;
	int			res;
	int			j;

	i = 0;
	res = 0;
	tmp = 0;
	j = 0;
	while (i < 32)
	{
		tmp = (i >= 0 && i <= 7) ? b : tmp;
		tmp = (i >= 8 && i <= 15) ? g : tmp;
		tmp = (i >= 16 && i <= 23) ? r : tmp;
		tmp = (i >= 24 && i <= 31) ? o : tmp;
		j = 0;
		while (j < 8)
		{
			if (tmp & (1 << j))
				res |= 1 << i;
			i++;
			j++;
		}
	}
	return (res);
}

static	void	draw_a(t_mlx *mlx, int step)
{
	int			x;
	int			y;

	y = HEIGHT - (step + 1) * mlx->h0;
	while (y < HEIGHT - step * mlx->h0)
	{
		x = 0;
		while (x < mlx->w0 * mlx->a->data[mlx->a->size - step - 1])
		{
			mlx->img->data[x + y * (mlx->img->size_line / 4)] =
				set_colors(0, 100, 255 - mlx->c0 * mlx->a->data[mlx->a->size -
						step - 1], 255);
			x++;
		}
		y++;
	}
}

static	void	draw_b(t_mlx *mlx, int step)
{
	int			x;
	int			y;

	y = HEIGHT - (step + 1) * mlx->h0;
	while (y < HEIGHT - step * mlx->h0)
	{
		x = WIDTH / 2;
		while (x < ((WIDTH / 2) + mlx->w0 * mlx->b->data[mlx->b->size - step -
					1]))
		{
			mlx->img->data[x + y * mlx->img->size_line / 4] =
				set_colors(0, 100, 255 - mlx->c0 * mlx->b->data[mlx->b->size -
						step - 1], 255);
			x++;
		}
		y++;
	}
}

void			draw(t_mlx *mlx)
{
	int			step;

	ft_memset(mlx->img->data, 0, WIDTH * HEIGHT * 4);
	step = -1;
	while (++step < mlx->a->size)
	{
		draw_a(mlx, step);
		if (mlx->b->size > step)
			draw_b(mlx, step);
	}
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img->id, 0, 0);
}
