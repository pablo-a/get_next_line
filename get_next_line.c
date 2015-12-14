/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:02:22 by pabril            #+#    #+#             */
/*   Updated: 2015/12/14 13:59:29 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static int	find_end_line(char buffer[BUFF_SIZE + 1])
{
	int i;

	while (buffer[i] != '\n' || buffer[i] == '\0')
		i++;
	return (i);
}

int			get_next_line(int const fd, char **line)
{
	static char buffer[BUFF_SIZE + 1] = {'\0'};
	int			ret;
	int			len;

	if (buffer[0] == '\0')
		ret = read(fd, &buffer, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	if (ret == 0)
		return (0);
	len = find_end_line(buffer);
	*line = ft_strnew(len + 1);
	ft_memmove(*line, buffer, len);
	if (buffer[len] == '\n')
		ft_memmove(buffer, buffer + len + 1);
	else
		buffer += len
	return (0);
}
