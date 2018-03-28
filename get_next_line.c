/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 17:29:56 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/28 15:02:10 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
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
	if (s1)
		free(s1);
	y = 0;
	while (s2 && s2[y])
	{
		sol[x + y] = s2[y];
		y++;
	}
	return (sol);
}

char	*split_newline2(char *line, char **extra)
{
	char			*c;

	if ((c = ft_strchr(line, '\n')) != NULL)
	{
		*c = '\0';
		*extra = ft_strdup(c + 1);
	}
	return (line);
}

char	*split_newline(char *line, char **extra, char *c)
{
//	if ((c = ft_strchr(*extra, '\n')) != NULL)
//	{
		*c = '\0';
		line = ft_strdup(*extra);
		*extra = ft_strdup(c + 1);
//	}
/*	else if (extra)
	{
		line = ft_strdup(*extra);
		ft_strdel(extra);
	}*/
	return (line);
}

int	get_next_line(int fd, char **line)
{
	static char *extra = NULL;
	int ret;
	char *c;
	char buf[BUFF_SIZE + 1];

	if (line == NULL || fd < 0 || read(fd, buf, 0) == -1)
		return (-1);
	*line = ft_strnew(1);
	if (extra && ((c = ft_strchr(extra, '\n')) != NULL))
	{
		*line = split_newline(*line, &extra, c);
		return (1);
	}
	if (extra)
	{
		*line = ft_strdup(extra);
		ft_strdel(&extra);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
	{
		buf[ret] ='\0';
		*line = ft_strjoin_free(*line, buf);
	}
	*line = split_newline2(*line, &extra);
	return((ft_strlen(*line) > 0) ? 1 : 0);
}
