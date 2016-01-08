/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabril <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 12:02:22 by pabril            #+#    #+#             */
/*   Updated: 2016/01/08 14:37:06 by pabril           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

size_t	check_newline(char buffer[])
{
	size_t i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	return (i);
}

char	*fill_lines(char *tempo, char *buffer, size_t len)
{
	size_t i;
	size_t j;
	char *result;

	i = 0;
	j = 0;
	result = ft_strnew(ft_strlen(tempo) + len + 1);
	while (tempo[i])
	{
		result[i] = tempo[i];
		i++;
	}
	while (j < len)
	{
		result[i] = buffer[j];
		i++;
		j++;
	}
	return (result);
}

void	decale_buffer(char buffer[], size_t len, char **line)
{
	int i;

	i = 0;
	if (buffer[0] == '\0' && *line != '\0')
		return ;
	else
	{
		while (buffer[i + len + 1] != '\0')
		{
			buffer[i] = buffer[i + len + 1];
			i++;
		}
		while (i < BUFF_SIZE)
		{
			buffer[i] = '\0';
			i++;
		}
		return ;
	}
}

int		get_next_line(int const fd, char **line)
{
	static char buffer[BUFF_SIZE + 1] = {'\0'};
	int			ret;
	size_t		len;
	char		*tempo;

	ret = 1;
	*line = ft_strnew(1);
	while (ret > 0)
	{
		if (buffer[0] == '\0')
			ret = read(fd, buffer, BUFF_SIZE);
		if (ret < 0)
			return (-1);
		len = check_newline(buffer);
		tempo = *line;
		*line = fill_lines(tempo, buffer, len);
		free(tempo);
		if (buffer[len] != '\0' || (buffer[0] == '\0' && *line[0] != '\0'))
		{
			decale_buffer(buffer, len, line);
			return (1);
		}
		ft_strclr(buffer);
	}
	return (0);
}

int main(int argc, const char *argv[])
{
	char **line;
	int fd;

	line = malloc(sizeof(char **) * 2);
	fd = open(argv[1], O_RDWR);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	get_next_line(fd, line);
	printf("%s", *line);
	return (0);
}
