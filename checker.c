/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:51:51 by enikole           #+#    #+#             */
/*   Updated: 2019/08/02 22:48:55 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h" //DELETE THIS

static	char		reading(int *stack, int len)
{
	int				curr;
	char			*line;

	line = ft_strnew(3);
	if (get_next_line(0, &line) > 0)
	{
		//do!
		line = ft_strnew(3);
		while ((curr = get_next_line(0, &line)) > 0)
		{
			//do!
			line = ft_strnew(3);
			//printf("line: %s\n", line);
		}
		free(line);
		if (!curr)
			return (1);
	}
	write(2, "Error\n", 6);
	return (0);

}

static	void		instructions(int *stack, int len)
{
	if (reading(stack, len))
	{

	}
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
	int				*stack;
	int				len;
	int				i;
	long	int		curr;

	if (ac > 1)
	{
		len = ac - 1;
		stack = (int *)malloc(sizeof(int) * len);
		i = 0;
		while (--ac)
		{
			if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <= MAX_INT && curr >= MIN_INT))
				stack[i++] = curr;
			else
				break ;
		}
		if (ac || check_dupl(stack, len))
			write(2, "Error\n", 6);
		else
		{
			//printf("stack :");
			//i = 0;
			//while (len--)
			//	printf(" %d", stack[i++]);
			//printf("\nEND_OF_STACK\n");
			instructions(stack, len);
		}
		free(stack);
	}
	return (0);
}
