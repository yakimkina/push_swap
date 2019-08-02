/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:04:06 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:53:29 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

static	t_list	*ft_del(t_list *b)
{
	t_list		*tmp;

	while (b != NULL)
	{
		tmp = b;
		b = b->next;
		free(tmp);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*tmp;
	t_list		*begin;

	begin = NULL;
	if (lst != NULL && f)
	{
		if (!(begin = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		begin = f(lst);
		lst = lst->next;
		tmp = begin;
	}
	while (lst != NULL && f)
		if ((new = (t_list*)malloc(sizeof(t_list))) != NULL)
		{
			new = f(lst);
			lst = lst->next;
			tmp->next = new;
			tmp = new;
		}
		else
			return (ft_del(begin));
	return (begin);
}
