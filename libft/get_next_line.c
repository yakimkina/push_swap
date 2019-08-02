/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 19:24:56 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 23:25:26 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/get_next_line.h"

static	t_str		*search_fd(t_list **begin, const int fd)
{
	t_list			*ptr;
	t_str			elem;

	ptr = *begin;
	while (ptr != NULL)
	{
		if (((t_str*)(ptr->content))->fd == fd)
			return ((t_str*)(ptr->content));
		ptr = ptr->next;
	}
	elem.fd = fd;
	elem.s = ft_strnew(0);
	ft_lstadd(begin, ft_lstnew(&elem, sizeof(t_str)));
	return ((t_str*)((*begin)->content));
}

static	int			rec_line(t_str *elem, char **line)
{
	char			*t;
	char			*tmp;

	if (*(elem->s) == '\0')
		return (0);
	if ((t = ft_strchr(elem->s, '\n')) != NULL)
	{
		*t = '\0';
		if (!(*line = ft_strdup(elem->s)))
			return (-1);
		if (!(tmp = ft_strdup(t + 1)))
			return (-1);
		free(elem->s);
		if (!(elem->s = ft_strdup(tmp)))
			return (-1);
		free(tmp);
		return (1);
	}
	if (!(*line = ft_strdup(elem->s)))
		return (-1);
	free(elem->s);
	elem->s = ft_strnew(0);
	if (elem->s == NULL)
		return (-1);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static	t_list	*begin;
	t_str			*elem;
	size_t			ret;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (!line || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	elem = search_fd(&begin, fd);
	if (!(elem->s))
		return (-1);
	while (ft_strchr(elem->s, '\n') == NULL && (ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		tmp = elem->s;
		if (!(elem->s = ft_strjoin(elem->s, buf)))
			return (-1);
		free(tmp);
	}
	return (rec_line(elem, line));
}
