/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:01:41 by gpinchon          #+#    #+#             */
/*   Updated: 2018/01/12 14:02:13 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *s, size_t n)
{
	char			*str;
	char			*ptr;

	str = (char *)malloc(sizeof(char *) * n);
	ptr = str;
	while (*s && n--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (str);
}