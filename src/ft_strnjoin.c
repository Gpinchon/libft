/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:32:16 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 13:04:39 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnjoin(size_t s1_size, size_t s2_size, char *s1, char *s2)
{
	char	*str;

	str = NULL;
	if (!s1 && s2)
		str = ft_strncpy(ft_memalloc(s2_size + 1), (const char*)s2, s2_size);
	else if (!s2 && s1)
		str = ft_strncpy(ft_memalloc(s1_size + 1), (const char*)s1, s1_size);
	else if (s1 && s2)
	{
		if (!(str = ft_memalloc(s1_size + s2_size + 1)))
			return (NULL);
		ft_strncpy(str, s1, s1_size);
		ft_strncat(str, s2, s2_size);
	}
	return (str);
}
