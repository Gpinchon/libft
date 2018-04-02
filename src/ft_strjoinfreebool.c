/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfreebool.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 22:30:59 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 13:03:30 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char				*ft_strjoinfreebool(char *s1, char *s2,
					char free1, char free2)
{
	char			*str;

	str = ft_strjoin(s1, s2);
	if (free1)
		free(s1);
	if (free2)
		free(s2);
	return (str);
}
