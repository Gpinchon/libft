/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:16:19 by gpinchon          #+#    #+#             */
/*   Updated: 2017/02/23 23:18:42 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strjoinfreefirst(char *s1, char *s2)
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
		free(s1);
		return (str);
	}
	return (NULL);
}

char		*file_to_str(int fd)
{
	char	*ret;
	char	*l;

	ret = NULL;
	while (get_next_line(fd, &l) > 0)
	{
		ret = ft_strjoinfree(ret, l);
		ret = ft_strjoinfreefirst(ret, "\n");
	}
	return (ret);
}
