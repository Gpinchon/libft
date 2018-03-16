/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:12:05 by gpinchon          #+#    #+#             */
/*   Updated: 2018/03/16 20:51:21 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void		*ft_memalloc(size_t size)
{
	void	*memalloc;

	if (!(memalloc = malloc(size)) || !size)
		return (NULL);
	ft_memset(memalloc, '\0', size);
	return (memalloc);
}
