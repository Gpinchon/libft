/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:16:19 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/10 17:57:30 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*file_to_str(int fd)
{
	char	*ret;
	size_t	size;
	size_t	cur;

	cur = lseek(fd, 0, SEEK_CUR);
	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	ret = malloc(size * sizeof(char) + 1);
	read(fd, ret, size);
	lseek(fd, cur, SEEK_SET);
	ret[size] = 0;
	return (ret);
}
