/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 14:16:19 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/12 21:28:41 by gpinchon         ###   ########.fr       */
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

char		*stream_to_str(FILE *stream)
{
	char	*ret;
	size_t	size;
	size_t	cur;

	cur = ftell(stream);
	fseek(stream, 0L, SEEK_END);
	size = ftell(stream);
	rewind(stream);
	ret = ft_memalloc((size + 1) * sizeof(char));
	ret[size] = '\0';
	fread(ret, sizeof(char), size, stream);
	fseek(stream, cur, SEEK_SET);
	return (ret);
}
