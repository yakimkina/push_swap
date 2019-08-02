/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 14:51:28 by enikole           #+#    #+#             */
/*   Updated: 2019/08/02 17:54:23 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4
# include <libc.h>
# include "libft.h"

typedef	struct		s_str
{
	int				fd;
	char			*s;
}					t_str;

int					get_next_line(const int fd, char **line);

#endif
