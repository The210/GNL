/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouzgao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 12:53:55 by ybouzgao          #+#    #+#             */
/*   Updated: 2018/03/28 14:51:23 by dhorvill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include "libft/libft.h"
# define BUFF_SIZE 1
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

int	get_next_line(int fd, char **line);

#endif
