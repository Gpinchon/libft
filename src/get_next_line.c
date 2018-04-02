/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:32:09 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 13:05:49 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_gnl	*find_gnl(t_gnl *gnl, const int fd)
{
	t_gnl	*cur_gnl;

	cur_gnl = gnl;
	while (cur_gnl)
	{
		if (cur_gnl->fd == fd)
			return (cur_gnl);
		cur_gnl = cur_gnl->next;
	}
	return (NULL);
}

static t_gnl	*add_gnl(t_gnl **gnl, const int fd)
{
	t_gnl	*new_gnl;
	t_gnl	**cur_gnl;

	if (!(new_gnl = ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	new_gnl->fd = fd;
	cur_gnl = gnl;
	while (*cur_gnl)
		cur_gnl = &(*cur_gnl)->next;
	*cur_gnl = new_gnl;
	return (new_gnl);
}

static void		read_file(t_gnl *gnl)
{
	int		r;
	char	b[BUFF_SIZE + 1];
	char	*buffer_ptr;

	while (!ft_strchr(gnl->buffer, '\n') && (r = read(gnl->fd, b, BUFF_SIZE)))
	{
		b[r] = 0;
		buffer_ptr = gnl->buffer;
		gnl->buffer = ft_strnjoin(gnl->buffer_size, r, gnl->buffer, b);
		free(buffer_ptr);
		gnl->buffer_size += r;
		if (ft_strchr(b, '\n'))
			break ;
	}
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*cgnl;
	char			*back_pos;
	char			*buffer_ptr;

	if (fd <= 0 || !line || (!(cgnl = find_gnl(gnl, fd))
	&& !(cgnl = add_gnl(&gnl, fd))))
		return (-1);
	read_file(cgnl);
	back_pos = ft_strchr(cgnl->buffer, '\n');
	if (!back_pos && !cgnl->buffer_size)
		return (0);
	else if (!back_pos && cgnl->buffer_size)
	{
		*line = ft_strndup(cgnl->buffer, cgnl->buffer_size);
		free(cgnl->buffer);
		ft_bzero(cgnl, sizeof(t_gnl));
		return (1);
	}
	*line = ft_strndup(cgnl->buffer, back_pos - cgnl->buffer);
	buffer_ptr = cgnl->buffer;
	cgnl->buffer_size -= (back_pos + 1 - cgnl->buffer);
	cgnl->buffer = ft_strndup(back_pos + 1, cgnl->buffer_size);
	free(buffer_ptr);
	return (1);
}
