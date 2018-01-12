/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:32:09 by gpinchon          #+#    #+#             */
/*   Updated: 2018/01/12 16:44:42 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_gnlstrjoinfree(char **a, char **b)
{
	char	*joined;

	joined = ft_strjoin(*a, *b);
	ft_strdel(a);
	ft_strdel(b);
	return (joined);
}

int		get_single_line(const int fd, char **save)
{
	int		value;
	char	*buffer;

	while (!ft_strchr(*save, '\n'))
	{
		buffer = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
		ft_memset(buffer, 0, BUFF_SIZE + 1);
		if ((value = read(fd, buffer, BUFF_SIZE)) <= 0)
		{
			free(buffer);
			return (value);
		}
		*save = ft_gnlstrjoinfree(save, &buffer);
	}
	return (1);
}



int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	size_t		tmp_len, tmp_backlen;
	int			value;
	char		*tmp;

	if (fd <= 0 || !line)
		return (-1);
	tmp = save && *save ? ft_strdup(save) : NULL;
	if ((value = get_single_line(fd, &tmp)) == -1)
		return (-1);
	if (!ft_strchr(tmp, '\n') || !value)
	{
		*line = tmp && *tmp ? tmp : NULL;
		ft_strdel(&save);
	}
	else
	{
		tmp_len = ft_strlen(tmp);
		tmp_backlen = ft_strlen(ft_strchr(tmp, '\n'));
		*line = ft_strndup(tmp, tmp_len - tmp_backlen);
		ft_strdel(&save);
		save = ft_strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
	}
	return (value);
}

/*typedef struct	s_gnl
{
	int		fd;
	char	*save;
	struct s_gnl	*next;
}				t_gnl;

t_gnl	*find_gnl(t_gnl *gnl, const int fd)
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

t_gnl	*add_gnl(t_gnl **gnl, const int fd)
{
	ft_putstr("add_gnl\n");
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

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*gnl = NULL;
	t_gnl			*cur_gnl;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd <= 0 || !line)
		return (-1);
	if (!(cur_gnl = find_gnl(gnl, fd)))
		if (!(cur_gnl = add_gnl(&gnl, fd)))
			return (-1);
	char *save_buf = cur_gnl->save;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		save_buf = ft_strjoinfreebool(save_buf, buf, 1, 0);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	char *back_pos;
	back_pos = ft_strchr(save_buf, '\n');
	if (!back_pos)
		return (0);
	*line = ft_strndup(save_buf, back_pos - save_buf);
	cur_gnl->save = ft_strdup(back_pos + 1);
	free(save_buf);
	return (1);
}*/