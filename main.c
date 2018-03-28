/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 13:02:29 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/20 15:20:00 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"


int		main(int ac, char **av)
{
	char 	*line;
	int 	fd;

	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
		if (line)
			ft_strdel(&line);
	}
	while(1)
		;
	return (0);
}
