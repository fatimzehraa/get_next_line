/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:50:51 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/10 21:27:59 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include<fcntl.h>

char *get_next_line(int fd)
{
	int i;
	int buf;
	char *buffer;
	static char *line;
	line = 0;

	i = 0;
	buf = 1;
	buffer = NULL;

	buffer = ft_calloc(6, sizeof(char));
	while (!ft_strchr(line, '\n') && buf)
	{
		buf = read(fd, buffer, BUFFER_SIZE);
		if (buf == -1)
		{
			free(buffer);
			return (NULL);
		}
		//buffer[buf] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

int main()
{
	int fd = open("file.txt", O_RDONLY);
	printf("'%s'", get_next_line(fd));
}
