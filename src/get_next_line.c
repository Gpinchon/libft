/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:32:09 by gpinchon          #+#    #+#             */
/*   Updated: 2018/01/12 21:14:27 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_gnlstrjoinfree(size_t s1_size, size_t s2_size, char *s1, char *s2)
{
	char			*str;

	if (!s1 && s2)
		str = null((char*)s2);
	else if (s1 && s2)
	{
		
		if (!(str = ft_memalloc(s1_size + s2_size + 1)))
			return (NULL);
		ft_strncpy(str, s1, s1_size);
		ft_strncat(str, s2, s2_size);
		free(s1);
	}
	return (str);
}

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
	t_gnl	*new_gnl, **cur_gnl;

	if (!(new_gnl = ft_memalloc(sizeof(t_gnl))))
		return (NULL);
	new_gnl->fd = fd;
	cur_gnl = gnl;
	while (*cur_gnl)
		cur_gnl = &(*cur_gnl)->next;
	*cur_gnl = new_gnl;
	return (new_gnl);
}

static void	read_file(t_gnl *gnl)
{
	int		r;
	char	b[BUFF_SIZE + 1];

	while (!ft_strchr(gnl->buffer, '\n') && (r = read(gnl->fd, b, BUFF_SIZE)))
	{
		b[r] = 0;
		gnl->buffer = ft_gnlstrjoinfree(gnl->buffer_size, r, gnl->buffer, b);
		gnl->buffer_size += r;
		if (ft_strchr(b, '\n'))
			break ;
	}
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*cgnl;
	char			*back_pos;
	char			*buffer_ptr;

	if (fd <= 0 || !line ||(!(cgnl = find_gnl(gnl, fd))
	&& !(cgnl = add_gnl(&gnl, fd))))
		return (-1);
	read_file(cgnl);
	back_pos = ft_strchr(cgnl->buffer, '\n');
	if (!back_pos)
		return (0);
	*line = ft_strndup(cgnl->buffer, back_pos - cgnl->buffer);
	buffer_ptr = cgnl->buffer;
	cgnl->buffer_size -= (back_pos + 1 - cgnl->buffer);
	cgnl->buffer = ft_strndup(back_pos + 1, cgnl->buffer_size);
	free(buffer_ptr);
	return (1);
}