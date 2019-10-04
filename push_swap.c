/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 12:51:55 by enikole           #+#    #+#             */
/*   Updated: 2019/09/13 19:07:30 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	char		is_sort(t_stack stack)
{
	int				i;

	i = 0;
	while (i < (stack.size - 1))
	{
		if (stack.data[i] < stack.data[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

static	int			bubble_sort(int *stack, int len) //rewrite this to quickselect
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
	tmp = mas[(len / 2)];
	free(mas);
	return (tmp);
}

void                    three_sort_stack_a(t_stack *a, t_stack *b)
{
    char                 fl;

    if (a->data[0] < a->data[1] && a->data[0] < a->data[2])
    {
        rotate(a, "ra\n");
        if (a->data[0] > a->data[1])
            swap(a, "sa\n");
        rotate(a, "ra\n");
    }
    else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
    {
        swap(a, "sa\n");
        rotate(a, "ra\n");
        if (a->data[0] > a->data[1])
            swap(a, "sa\n");
        rotate(a, "ra\n");
    }
    else
    {
        fl = 0;
        push(b, a, "pb\n");
        swap(a, "sa\n");
        rotate(a, "ra\n");
        if (a->data[0] > b->data[0])
            fl = push(a, b, "pa\n");
        rotate(a, "ra\n");
        if (!fl)
            push(a, b, "pa\n");
    }
    rotate(a, "ra\n");
}

int			stack_max(t_stack stack)
{
	int		i;
	int		max;
	//int     tmp;

	i = 1;
	max = stack.data[0];
	while (i < stack.size)
	{
	    //tmp = stack.data[i];
		if (stack.data[i] > max)
			max = stack.data[i];
		i++;
	}
	return (max);
}

int			stack_min(t_stack stack)
{
	int		i;
	int		min;

	i = 1;
	min = stack.data[0];
	while (i < stack.size)
	{
		if (stack.data[i] < min)
			min = stack.data[i];
		i++;
	}
	return (min);
}

int			smart_rotate(t_stack *a, t_stack *b, int i)
{
    int     j;

    if (i <= b->size / 2)
	{
		while (i > 0)
		{
			if ((b->data)[0] == stack_min(*b))
			{
				push(a, b, "pa\n");
				i--;
				if (i && b->data[0] != stack_min(*b))
                {
				    rotate(a, NULL);
				    rotate(b, "rr\n");
				    i--;
                }
				else
				    rotate(a, "ra\n");
                //print_stack(*a, *b);
			}
			if (i)
            {
			    rotate(b, "rb\n");
                //print_stack(*a, *b);
            }
			i--;
		}
	}
	else
	{
		j = b->size - i;
	    while (j > 0)
		{
			if ((b->data)[0] == stack_min(*b))
			{
                push(a, b, "pa\n");
                rotate(a, "ra\n");
                //print_stack(*a, *b);
            }
			rev_rotate(b, "rrb\n");
            //print_stack(*a, *b);
			j--;
		}
	}
	push(a, b, "pa\n");
    //print_stack(*a, *b);
	return (1);
}

int			twelve_split(t_stack *a, t_stack *b)
{
	int		i;
	int		max;
	int		res_max;

	res_max = 0;
	while (b->size)
	{
		if ((b->data)[0] == stack_min(*b))
		{
			push(a, b, "pa\n");
			//if (b->size && b->data[0] != stack_min(*b) && )
			rotate(a, "ra\n");
            //print_stack(*a, *b);
		}
		else
		{
			i = 0;
			max = stack_max(*b);
			while ((b->data)[i] != max)
				i++;
			res_max += smart_rotate(a, b, i);
		}
	}
	return (res_max);
}

void        add_max(t_max **begin, int max)
{
    t_max   *tmp;

    if (!(*begin) || (*begin)->max != max)
    {
        tmp = (t_max *)malloc(sizeof(t_max) * 1);
        tmp->max = max;
        if (!(*begin))
           tmp->next = NULL;
        else
            tmp->next = *begin;
        *begin = tmp;
    }
}

void		split_b(t_stack *a, t_stack *b, t_max **begin)
{
    int		med;
	int		max;
	int		k;
	int     i;

	if (b->size)
    {
	    if (b->size <= 12)
        {
	        max = stack_max(*b);
	        add_max(begin, max);
        }
        while (b->size > 12)
        {
            max = stack_max(*b);
            add_max(begin, max);
            med = bubble_sort(b->data, b->size);
            i = (b->size / 2);
            while (b->size != i && b->size)
            {
                if (b->data[0] >= med)
                    push(a, b, "pa\n");
                else
                {
                    if (b->data[0] == stack_min(*b))
                    {
                        push(a, b, "pa\n");
                        if (b->size != i && b->size && b->data[0] < med &&
                                b->data[0] != stack_min(*b))
                        {
                            rotate(a, NULL);
                            rotate(b, "rr\n");
                        }
                        else
                            rotate(a, "ra\n");
                        i--;
                    }
                    else
                        rotate(b, "rb\n");
                }
            }
	    }
        k = twelve_split(a, b);
        while (k--)
	        rotate(a, "ra\n");
    }
}

int			count_num(t_stack a, int max, int border)
{
	int		i;

	i = 0;
	if (max != border)
    {
	    while (a.data[i] > max && a.data[i] <= border)
		    i++;
    }
	else
    {
	    while (a.data[i] <= max)
	        i++;
    }
	return (i);
}

char            check_rot(t_stack *a, t_stack *b, int num, int med)
{
    t_stack     *tmp;
    int         i;

    i = 0;
    while (i != num)
    {
        if (a->data[i] >= med)
            i++;
        else
            break ;
    }
    if (i == num)
    {
        tmp = (t_stack *)malloc(sizeof(t_stack) * 1);
        tmp->data = &(a->data[i]);
        tmp->size = a->size - num;
        if (is_sort(*tmp) || b->data)
        {
            free(tmp);
            return (0);
        }
        free(tmp);
    }
    return (1);
}

void        del_max(t_max **begin)
{
    t_max   *tmp;

    if (*begin)
    {
        tmp = (*begin);
        *begin = (*begin)->next;
        tmp->next = NULL;
        free(tmp);
    }
}

void        three_rot_a(t_stack *a, t_stack *b, int i)
{
    if (i == 3)
    {
        if (a->data[a->size - 3] < a->data[a->size - 2] &&
            a->data[a->size - 3] < a->data[a->size - 1])
        {
            if (a->data[a->size - 2] > a->data[a->size - 1])
            {
                rev_rotate(a, "rra\n");
                rev_rotate(a, "rra\n");
                swap(a, "sa\n");
                rotate(a, "ra\n");
                rotate(a, "ra\n");
            }
        }
        else
        {
            while (i--)
                rev_rotate(a, "rra\n");
            three_sort_stack_a(a, b);
        }
    }
    else if (i == 2)
    {
        if (a->data[0] > a->data[a->size - 2] && a->data[a->size - 2] < a->data[a->size - 1])
        {
            if (a->data[0] < a->data[a->size - 1])
            {
                rev_rotate(a, "rra\n");
                swap(a, "sa\n");
                rotate(a, "ra\n");
            }
            rotate(a, "ra\n");
        }
        else
        {
            rev_rotate(a, "rra\n");
            if (a->data[1] < a->data[0])
                swap(a, "sa\n");
            rev_rotate(a, "rra\n");
            three_sort_stack_a(a, b);
        }
    }
    else
    {
        if (a->data[a->size - 1] < a->data[0] && a->data[1] > a->data[a->size - 1])
        {
            if (a->data[0] > a->data[1])
                swap(a, "sa\n");
            rotate(a, "ra\n");
            rotate(a, "ra\n");
        }
        else
        {
            if (a->data[0] > a->data[1])
                swap(a, "sa\n");
            rev_rotate(a, "rra\n");
            three_sort_stack_a(a, b);
        }
    }
}

void        five_sort_stack_a(t_stack *a, t_stack *b, int num, int med)
{
    int     i;

    if (num == 4)
    {
        i = 0;
        while (!b->size)
        {
            if (a->data[0] > med)
                push(b, a, "pb\n");
            else
                i += rotate(a, "ra\n");
        }
        (i) ? three_rot_a(a, b, i) : (three_sort_stack_a(a, b));
        push(a, b, "pa\n");
        rotate(a, "ra\n");
    }
    else if (num == 3)
        three_sort_stack_a(a, b);
    else if (num == 2)
    {
        if (a->data[0] > a->data[1])
            swap(a, "sa\n");
        rotate(a, "ra\n");
        rotate(a, "ra\n");
    }
    else if (num == 1)
        rotate(a, "ra\n");
}

void		three_sort_stack(t_stack *a)
{
    if ((a->data)[0] < (a->data)[1] && (a->data)[1] > (a->data)[2])
    {
        rev_rotate(a, "rra\n");
        if ((a->data)[1] < (a->data)[0])
            swap(a, "sa\n");
    }
    else if ((a->data)[0] > (a->data)[1])
    {
        if ((a->data)[0] < (a->data)[2])
            swap(a, "sa\n");
        else if ((a->data)[1] < (a->data)[2])
            rotate(a, "ra\n");
        else
        {
            swap(a, "sa\n");
            rev_rotate(a, "rra\n");
        }
    }
}

void                five_sort_stack(t_stack *a, t_stack *b)
{
    int             med;
    int             i;

    if (a->size == 2 && a->data[0] > a->data[1])
        swap(a, "sa\n");
    else if (a->size == 3)
        three_sort_stack(a);
    else if (a->size > 3)
    {
        med = bubble_sort(a->data, a->size);
        i = (a->size % 2 == 0) ? (a->size / 2) : (a->size / 2 + 1);
        while (a->size != i)
        {
            if (a->data[0] < med)
                push(b, a, "pb\n");
            else
                rotate(a, "ra\n");
        }
        three_sort_stack(a);
        if (b->size == 2 && b->data[0] < b->data[1])
            swap(b, "sb\n");
        while (b->size)
            push(a, b, "pa\n");
    }
}

void		split_a(t_stack *a, t_stack *b, int max, t_max **begin)
{
    //char    *tmp;
	int     border;
    int		med;
	int		num;
	int		i;

	if (a->data[0] <= max)
	{
		while ((a->data)[0] <= max)
		{
		    if (a->data[1] > max && a->data[0] < stack_min(*b))
		        rotate(a, "ra\n");
		    else
		        push(b, a, "pb\n");
		    //print_stack(*a, *b);
		}
	}
	else
    {
	    del_max(begin);
	    border = ((*begin)) ? ((*begin)->max) : (stack_max(*a));
	    num = count_num(*a, max, border);
        //tmp = ft_itoa(num);
        //write(1, "num = ", 6);
        //write(1, tmp, ft_strlen(tmp));
        //write(1, "\n", 1);
	    med = bubble_sort(a->data, num);
        //tmp = ft_itoa(med);
        //write(1, "medA = ", 7);
        //write(1, tmp, ft_strlen(tmp));
        //write(1, "\n", 1);
	    i = 0;
	    if (num < 6 && a->size < 6)
	        five_sort_stack(a, b);
	    else if (num < 5)
	        five_sort_stack_a(a, b, num, med);
        else
        {
	        while (num--)
	        {
	            if ((a->data)[0] < med)
                {
	                push(b, a, "pb\n");
                    //print_stack(*a, *b);
                }
	            else if (check_rot(a, b, num + 1, med))
	                    i += rotate(a, "ra\n");
	            else
                    break ;
	        }
	        if (is_sort(*a) || b->data)
	        {
	            while (i--)
                {
	                rev_rotate(a, "rra\n");
                    //print_stack(*a, *b);
                }
	        }
        }
    }
	//if (is_sort(*a) || b->data)
	//	split_b(a, b);
}

void		first_split(t_stack *a, t_stack *b)
{
    int     i;
    int		med;

	med = bubble_sort(a->data, a->size);
	i = (a->size % 2 == 0) ? (a->size / 2) : (a->size / 2 + 1);
	//printf("BEGIN");
	//print_stack(*a, *b);`
	while (a->size != i)
	{
		if ((a->data)[0] < med)
        {
			push(b, a, "pb\n");
			//print_stack(*a, *b);
        }
		else
        {
			rotate(a, "ra\n");
            //print_stack(*a, *b);
        }
		//print_stack(*a, *b);
	}
	 //print_stack(*a, *b);
	//write(1, "hear\n", 5);
}

static	void		quicksort(t_stack *a, t_stack *b)
{
//	int				max;
    t_max           *begin;
	//write(1, "hear2\n", 6);
	first_split(a, b);
//	max = stack_max(*b);
    begin = NULL;
    while (is_sort(*a) || b->data)
    {
	    split_b(a, b, &begin);
	    split_a(a, b, begin->max, &begin);
    }
}

/* static	void		three_sort_stack(t_stack *a)
{
	if ((a->data)[0] < (a->data)[1] && (a->data)[1] > (a->data)[2])
	{
		rev_rotate(a, "rra\n");
		if ((a->data)[1] < (a->data)[0])
			swap(a, "sa\n");
	}
	else if ((a->data)[0] > (a->data)[1])
	{
		if ((a->data)[0] < (a->data)[2])
			swap(a, "sa\n");
		else if ((a->data)[1] < (a->data)[2])
			rotate(a, "ra\n");
		else
		{
			swap(a, "sa\n");
			rev_rotate(a, "rra\n");
		}
	}
}

void                five_sort_stack(t_stack *a, t_stack *b)
{
    int             med;
    int             i;

    if (a->size == 2)
        swap(a, "sa\n");
    else if (a->size == 3)
        three_sort_stack(a);
    else
    {
        med = bubble_sort(a->data, a->size);
        i = (a->size % 2 == 0) ? (a->size / 2) : (a->size / 2 + 1);
        while (a->size != i)
        {
            if (a->data[0] < med)
                push(b, a, "pb\n");
            else
                rotate(a, "ra\n");
        }
        three_sort_stack(a);
        if (b->size == 2 && b->data[0] < b->data[1])
            swap(b, "sb\n");
        while (b->size)
            push(a, b, "pa\n");
    }
}
*/
int					main(int ac, char **av)
{
	t_stack			a;
	t_stack			b;
	int				i;
	int				fl;

	if (ac > 1)
	{
		/* stack.la = ac - 1;
		stack.a = (int *)malloc(sizeof(int) * stack.la);
		i = 0;
		while (--ac)
		{
			if (check_int(av[i + 1]) && ((curr = ft_atoi_long(av[i + 1])) <=
						MAX_INT && curr >= MIN_INT))
				(stack.a)[i++] = curr;
			else
				break ;
		} */
		fl = reading_args(&ac, &av, &a);
		if (ac || check_dupl(a))
			write(2, "Error\n", 6);
		else
		{
			//write(1, "hear\n", 5);
			//printf("stack :");
			//i = 0;
			//while (i < stack.la)
				//printf(" %d", stack.a[i++]);
			//printf("\nEND_OF_STACK\n");
			b.data = NULL;
			b.size = 0;
			//write(1, "hear\n", 5);
			if (is_sort(a))
			{
				if (a.size < 6)
					five_sort_stack(&a, &b);
				else
					quicksort(&a, &b);
				//printf("sorted:\n");
				//i = 0;
				//while (i < a.size)
					//printf("%d ", a.data[i++]);
			}
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
