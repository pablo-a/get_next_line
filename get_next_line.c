/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:02:22 by pabril            #+#    #+#             */
/*   Updated: 2016/01/06 18:26:51 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int	get_next_line(int const fd, char **line)
{
	static char *buffer;
	int			ret;

	buffer = (char *)malloc(BUFF_SIZE + 1);
	ret = BUFF_SIZE;
	while (ret == BUFF_SIZE)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		//fill_lines(buffer, line, ret);
		printf("%s\n", buffer);
	}
	printf("%s\n", buffer);
	return (0);
}

int main(int argc, const char *argv[])
{
	char **line;

	get_next_line(0, line);
	return 0;
}
