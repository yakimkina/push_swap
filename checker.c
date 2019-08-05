/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:51:51 by enikole           #+#    #+#             */
/*   Updated: 2019/08/05 12:16:46 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void		check(t_stack *stack)
{
	int				i;
	char			fl;

	i = 0;
	fl = 1;
	while (i < (stack->la - 1))
	{
		if ((stack->a)[i] < (stack->a)[i + 1])
			i++;
		else
		{
			fl = 0;
			break ;
		}
	}
	fl = (stack->b == NULL && stack->lb == 0) ? (fl) : (0);
	if (fl)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static	char		instructions(char *line, t_stack *stack)
{
	if (line[0] == 's')
	{
		if (line[1] == 'a' && line[2] == 0)
			return (swap(stack->a, stack->la));
		else if (line[1] == 'b' && line[2] == 0)
			return (swap(stack->b, stack->lb));
		else if (line[1] == 's' && line[2] == 0)
			return (swap(stack->a, stack->la) && swap(stack->b, stack->lb));
	}
	else if (line[0] == 'p')
	{
		if (line[1] == 'a' && line[2] == 0)
			return (push(&stack->a, &stack->b, &stack->la, &stack->lb));
		else if (line[1] == 'b' && line[2] == 0)
			return (push(&stack->b, &stack->a, &stack->lb, &stack->la));
	}
	else if (line[0] == 'r')
		return (r_inst(line, stack));
	return (0);
}

static	void		reading(t_stack *stack)
{
	char			fl;
	int				curr;
	char			*line;

	line = ft_strnew(3);
	if (get_next_line(0, &line) > 0)
	{
		stack->b = NULL;
		stack->lb = 0;
		fl = instructions(line, stack);
		line = ft_strnew(3);
		while (((curr = get_next_line(0, &line)) > 0) && fl)
		{
			fl = instructions(line, stack);
			line = ft_strnew(3);
			//printf("line: %s\n", line);
		}
		free(line);
		if (!curr && fl)
		{
			check(stack);
			return ;
		}
	}
	write(2, "Error\n", 6);
}

static	char		check_dupl(int *stack, int len)
{
	int				i;
	int				j;

	i = len;
	while (--i)
	{
		j = i;
		while (j--)
		{
			if (stack[i] == stack[j])
				return (1);
		}
	}
	return (0);
}

static	char		check_int(char *str)
{
	char			fl;

	fl = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str)
	{
		if (fl && (*str == '-' || *str == '+'))
		{
			fl = 0;
			str++;
		}
		else if ((*str >= '0' && *str <= '9'))
		{
			str++;
			if (!(*str))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

int					main(int ac, char **av)
{
	t_stack			stack;
	int				i;
	long	int		curr;

	if (ac > 1)
	{
		stack.la = ac - 1;
		stack.a = (int *)malloc(sizeof(int) * stack.la);
		i = 0;
		while (--ac)
		{
			if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <= MAX_INT && curr >= MIN_INT))
				(stack.a)[i++] = curr;
			else
				break ;
		}
		if (ac || check_dupl(stack.a, stack.la))
			write(2, "Error\n", 6);
		else
		{
			//printf("stack :");
			//i = 0;
			//while (len--)
			//	printf(" %d", stack[i++]);
			//printf("\nEND_OF_STACK\n");
			reading(&stack);
		}
		free(stack.a); //specify!!
	}
	return (0);
}
