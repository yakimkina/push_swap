/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enikole <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:51:10 by enikole           #+#    #+#             */
/*   Updated: 2019/07/31 16:58:17 by enikole          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	l;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ((char*)s);
	l = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while ((s[l] == ' ' || s[l] == '\n' || s[l] == '\t') && i != ft_strlen(s))
		l--;
	if ((str = (char*)malloc(sizeof(char) * (l - i + 2))) != NULL)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		str[l - i + 1] = '\0';
		ft_strncpy(str, &s[i], l - i + 1);
	}
	return (str);
}
