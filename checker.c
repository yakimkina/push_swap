/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:51:51 by enikole           #+#    #+#             */
/*   Updated: 2019/09/09 21:22:38 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void		check(t_stack a, t_stack b)
{
	int				i;
	char			fl;

	i = 0;
	fl = 1;
	//while(i < a.size)
	//	printf("%d", a.data[i++]);
	i = 0;
	while (i < (a.size - 1))
	{
		if ((a.data)[i] < (a.data)[i + 1])
			i++;
		else
		{
			fl = 0;
			break ;
		}
	}
	fl = (b.data == NULL && b.size == 0) ? (fl) : (0);
	if (fl)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static	char		r_instructions(char *line, t_stack *a, t_stack *b)
{
	if (line[1] == 'a' && line[2] == 0)
		return (rotate(a, NULL));
	else if (line[1] == 'b' && line[2] == 0)
		return (rotate(b, NULL));
	else if (line[1] == 'r')
	{
		if (line[2] == 'a' && line[3] == 0)
			return (rev_rotate(a, NULL));
		else if (line[2] == 'b' && line[3] == 0)
			return (rev_rotate(b, NULL));
		else if (line[2] == 'r' && line[3] == 0)
			return (rev_rotate(a, NULL) && rev_rotate(b, NULL));
		else if (line[2] == 0)
			return (rotate(a, NULL) && rotate(b, NULL));
	}
	return (0);
}

static	char		instructions(char *line, t_stack *a, t_stack *b)
{
	if (line[0] == 's')
	{
		if (line[1] == 'a' && line[2] == 0)
			return (swap(a, NULL));
		else if (line[1] == 'b' && line[2] == 0)
			return (swap(b, NULL));
		else if (line[1] == 's' && line[2] == 0)
			return (swap(a, NULL) && swap(b, NULL));
	}
	else if (line[0] == 'p')
	{
		if (line[1] == 'a' && line[2] == 0)
			return (push(a, b, NULL));
		else if (line[1] == 'b' && line[2] == 0)
			return (push(b, a, NULL));
	}
	else if (line[0] == 'r')
		return (r_instructions(line, a, b));
	return (0);
}

static	void		reading(t_stack *a)
{
	t_stack			b;
	char			fl;
	int				curr;
	char			*line;

//	line = ft_strnew(3);
//	if (get_next_line(0, &line) > 0)
//	{
//		stack->b = NULL;
//		stack->lb = 0;
//		fl = instructions(line, stack);
	fl = 1;
	line = ft_strnew(3);
	b.data = NULL;
	b.size = 0;
	while (((curr = get_next_line(0, &line)) > 0) && fl)
	{
		fl = instructions(line, a, &b);
		line = ft_strnew(3);
	}
	free(line);
	//fl = fl + 48;
	//printf("curr = %d, fl = %c\n", curr, fl);
	if (!curr && fl)
	{
		//printf("hear1");
		check(*a, b);
		return ;
	}
//	}
	write(2, "Error\n", 6);
}

int					main(int ac, char **av)
{
	t_stack			a;
	int				i;
	int				fl;

	if (ac > 1)
	{
		//printf("ac = %d, av[0] = %s\n", ac, av[0]);
		fl = (rec_str(&ac, &av, &a));
		//printf("ac = %d, a.size = %d\n", ac, a.size);
		//i = 0;
		//while (i < a.size)
		//	printf("%d", a.data[i++]);
		/* a.size = ac - 1;
		a.data = (int *)malloc(sizeof(int) * a.size);
		i = 0;
		while (--ac)
		{
			if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <=
						MAX_INT && curr >= MIN_INT))
				(a.data)[i++] = curr;
			else
				break ;
		} */
		if (ac || check_dupl(a))
			write(2, "Error\n", 6);
		else
		{
			//printf("stack :");
			//i = 0;
			//while (len--)
			//printf(" %d", stack[i++]);
			//printf("\nEND_OF_STACK\n");
			//printf("hear");
			reading(&a);
		}
		free(a.data);
		if (!fl)
		{
			i = 0;
			while (av[i])
				free(av[i++]);
		}
	}
	return (0);
}
