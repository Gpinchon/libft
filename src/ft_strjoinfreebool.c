/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfreebool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 22:30:59 by gpinchon          #+#    #+#             */
/*   Updated: 2018/01/12 14:23:59 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strjoinfreebool(char *s1, char *s2, char free1, char free2)
{
	char			*str;

	if (!s1 && s2)
		return (null((char*)s2));
	else if (!s2 && s1)
		return (null((char*)s1));
	else if (s1 && s2)
	{
		if (!(str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(str, s1);
		ft_strcat(str, s2);
		if (free1)
			free(s1);
		if (free2)
			free(s2);
		return (str);
	}
	return (NULL);
}
