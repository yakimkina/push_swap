/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:29:51 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:53:32 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;

	if ((tmp = (t_list*)malloc(sizeof(t_list))) != NULL)
	{
		if (!content)
		{
			tmp->content = NULL;
			tmp->content_size = 0;
		}
		else
		{
			if ((tmp->content = (void*)malloc(content_size)) != NULL)
			{
				ft_memcpy(tmp->content, content, content_size);
				tmp->content_size = content_size;
			}
			else
			{
				free(tmp);
				return (NULL);
			}
		}
		tmp->next = NULL;
	}
	return (tmp);
}
