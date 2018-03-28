/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carlos2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhorvill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 15:06:08 by dhorvill          #+#    #+#             */
/*   Updated: 2018/03/28 14:54:50 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2, int s)
{
	int		x;
	int		y;
	char	*sol;

	x = s1 != NULL ? ft_strlen(s1) : 0;
	y = s2 != NULL ? ft_strlen(s2) : 0;
	sol = (char *)ft_memalloc(sizeof(char) * (x + y + 1));
	x = 0;
	while (s1 && s1[x])
	{
		sol[x] = s1[x];
		x++;
	}
	if (s1 && (s == 1 || s == 3))
		free(s1);
	y = 0;
	while (s2 && s2[y])
	{
		sol[x + y] = s2[y];
		y++;
	}
	if (s2 && (s == 2 || s == 3))
		free(s2);
	return (sol);
}

int		if_extra(char **line, char **extra)
{
	char	*c;
	char	*tmp;

	if ((c = ft_strchr(*extra, '\n')) != NULL)
	{
		*c = '\0';
		tmp = *extra;
		*line = ft_strdup(*extra);
		*extra = ft_strdup(c + 1);
		free(tmp);
		return (1);
	}
	if (extra)
	{
		*line = ft_strdup(*extra);
		ft_strdel(extra);
	}
	return (0);
}

int		get_line(char **line, char **extra)
{
	char	*tmp;
	char	*c;

	if ((c = ft_strchr(*line, '\n')) != NULL)
	{
		*c = '\0';
		tmp = *line;
		*line = ft_strdup(tmp);
		*extra = ft_strdup(c + 1);
		free(tmp);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			ret;
	static char	*extra = NULL;
	char		buf[BUFF_SIZE + 1];

	if (line == NULL || fd < 0 || read(fd, buf, 0) == -1)
		return (-1);
	*line = ft_strnew(1);
	if (extra && if_extra(line, &extra) == 1)
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] = '\0';
		*line = ft_strjoin_free(*line, buf, 1);
	}
	if (get_line(line, &extra) == 1)
		return (1);
	return ((ft_strlen(*line) > 0) ? 1 : 0);
}
