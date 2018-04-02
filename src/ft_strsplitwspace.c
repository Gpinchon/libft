/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwspace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchon <gpinchon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 23:15:28 by gpinchon          #+#    #+#             */
/*   Updated: 2018/04/02 13:04:58 by gpinchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	is_wspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

size_t	wordlenws(const char *str)
{
	unsigned int len;

	len = 0;
	while (*str && !is_wspace(*str))
	{
		len++;
		str++;
	}
	return (len);
}

char	*split_cpyws(const char *str)
{
	size_t	size;
	char	*strsplit;

	while (*str && is_wspace(*str))
		str++;
	size = wordlenws(str);
	strsplit = ft_strnew(size + 1);
	ft_strncpy(strsplit, str, size);
	return (strsplit);
}

size_t	wordcountws(const char *str)
{
	size_t size;

	size = 0;
	while (*str)
	{
		if (!is_wspace(*str))
			size++;
		while (!is_wspace(*str) && *(str + 1))
			str++;
		str++;
	}
	return (size);
}

char	**ft_strsplitwspace(char const *s)
{
	char	**split;
	size_t	i;

	if (s)
	{
		i = wordcountws(s);
		split = ft_memalloc(sizeof(char**) * (i + 1));
		i = 0;
		while (*s)
		{
			if (!is_wspace(*s))
			{
				split[i] = split_cpyws(s);
				while (!is_wspace(*s) && *(s + 1))
					s++;
				i++;
			}
			s++;
		}
		return (split);
	}
	return (NULL);
}
