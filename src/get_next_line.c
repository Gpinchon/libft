/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/06 12:32:09 by gpinchon          #+#    #+#             */
/*   Updated: 2017/02/20 15:00:11 by gpinchon         ###   ########.fr       */
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

char	*ft_strndup(const char *s, size_t n)
{
	char			*str;
	char			*ptr;

	str = (char *)malloc(sizeof(char *) * ft_strlen(s));
	ptr = str;
	while (*s && n--)
		*ptr++ = *s++;
	*ptr = '\0';
	return (str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
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
		*line = ft_strndup(tmp, ft_strlen(tmp) -
			ft_strlen(ft_strchr(tmp, '\n')));
		ft_strdel(&save);
		save = ft_strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
	}
	return (value);
}
