/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:51:51 by enikole           #+#    #+#             */
/*   Updated: 2019/10/05 18:54:42 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char				r_instructions(char *line, t_stack *a, t_stack *b)
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

char				instruction(char *line, t_stack *a, t_stack *b)
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

static	void		reading_str(t_stack *a)
{
	t_stack			b;
	char			fl;
	int				curr;
	char			*line;

	fl = 1;
	line = NULL;
	b.data = NULL;
	b.size = 0;
	while (((curr = get_next_line(0, &line)) > 0) && fl)
	{
		fl = instruction(line, a, &b);
		free(line);
		line = NULL;
	}
	if (!curr && fl)
	{
		check(*a, b);
		return ;
	}
	write(2, "Error\n", 6);
}

int					main(int ac, char **av)
{
	t_stack			a;
	int				i;
	int				fl;

	if ((ac > 2 && av[2][0] != '\0' && !ft_strncmp(av[1], "-v", 3)))
	{
		fl = visualisation(&ac, &av, &a);
		free(a.data);
		if (!fl)
			free_av(av);
	}
	else if (ac > 1 && av[1][0] != '\0')
	{
		if (!ft_strncmp(av[1], "-v", 3) && av[2][0] == '\0')
			exit(0);
		fl = reading_args(&ac, &av, &a);
		if (ac || check_duplicates(a))
			write(2, "Error\n", 6);
		else
			reading_str(&a);
		free(a.data);
		if (!fl)
			free_av(av);
	}
	return (0);
}
