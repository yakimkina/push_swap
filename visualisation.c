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

	mas = (int *)malloc(sizeof(int) * len);
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
    char			**tmp;
    int				i;
    int				fl;
    long	int		curr;

    fl = 1;
    //write(1, "hear\n", 5);
    i = 0;
    if (*ac == 2 || *ac == 3)
    {
        i = (*ac == 2) ? (1) : (2);
        //write(1, "HEAR\n", 5);
        *ac = ft_wordcount((*av)[i], ' ') + 1;
        //write(1, "yes\n", 4);
        *av = ft_strsplit((*av)[i], ' ');
        tmp = *av;
        if (i == 1)
            *av = ++(*av);
        //write(1, "yes2\n", 5);
        fl = 0;
    }
    a->size = (i != 1) ? (*ac - 1) : (*ac - 2);
    a->data = (int *)malloc(sizeof(int) * a->size);
    i = (fl == 1) ? (2) : (0);
    /* while (++i < *ac)
    {
            write(1, &(i), 1);
            //printf("%s", (*av)[i++]);
    }
    i = 0; */
    while (--(*ac))
    {
        if (check_int((*av)[i]) && ((curr = ft_atoi_long((*av)[i])) <=
                                         MAX_INT && curr >= MIN_INT))
            (a->data)[i++] = curr;
        else
            break ;
    }
    if (!fl)
        *av = tmp;
    //write(1, "hear1\n", 6);
    return (fl);
}

int					reading_str_v(t_mlx mlx)
{
	char			fl;
	int				curr;
	char			*line;

	fl = 1;
	line = ft_strnew(3);
	if ((curr = get_next_line(0, &line)) > 0)
	{
		fl = instructions(line, mlx.a, mlx.b);
		draw(mlx);
	}
	free(line);
	//fl = fl + 48;
	//printf("curr = %d, fl = %c\n", curr, fl);
	//if (!fl)
	//	mlx_string_put(mlx.id, mlx.win, WIDTH - 950, HEIGTH / 2, 255, "Error");
	return (1);
}

int                 visualisation(int *ac, char ***av, t_stack *a)
{
    int             fl;
    t_mlx           mlx;
    t_image			im;

    mlx.id = mlx_init();
    mlx.win = mlx_new_window(mlx.id, WIDTH, HEIGHT, "push_swap");
    fl = reading_args_v(ac, av, a);
    if (ac || check_dupl(*a))
        mlx_string_put(mlx.id, mlx.win, WIDTH - 950, HEIGHT / 2, 255, "Error");
    else
    {
    	mlx.a = a;
    	mlx.b->data = NULL;
    	mlx.b->size = 0;
    	mlx.img = &im;
        mlx.img->id = mlx_new_image(mlx.id, WIDTH, HEIGHT);
		mlx.img->data = (int *)mlx_get_data_addr(mlx.img->id, &mlx.img->bpp, &mlx.img->size_line, &mlx.img->endian);
        rewrite_a(a);
        mlx.w0 = WIDTH / a->size;
        mlx.h0 = HEIGHT / a->size;
        draw(mlx);
    }
    mlx_loop_hook(mlx.id, reading_str_v, &mlx);
    mlx_loop(mlx.id);
    return (fl);
}


