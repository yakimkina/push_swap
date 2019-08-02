/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 17:04:17 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:53:19 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!(*alst) || !alst || !del)
		return ;
	while (*alst != NULL)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = *alst;
		*alst = (*alst)->next;
		free(tmp);
	}
	ft_memdel((void**)alst);
}
