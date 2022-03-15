/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:50:51 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/15 23:46:29 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include<fcntl.h>
#include<stdio.h>

char *get_n_line(int fd, char *line)
{
	int n;
	char *buffer;
	
	n = 1;
	buffer = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!is_new_line(line) && n)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		if (n == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[n] = 0;
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char *ft_get_line(char *str)
{
	int i;
	char *line;

	if(str[0] == '\0')
		return (NULL);
	i = is_new_line(str) + 1;
	line = malloc((i + 1) * sizeof(char));
	if(line == NULL)
		return (NULL);
	ft_strncpy(line, str, i);
	return (line);
}

char * ft_get_rest(char *str)
{
	int line_len;
	int rest_len;
	char *rest;

	line_len = is_new_line(str) + 1;
	rest_len = ft_strlen(str + line_len);
	rest = malloc(sizeof(char) * (rest_len + 1));
	if(rest == NULL)
		return (NULL);
	ft_strncpy(rest, str + line_len, rest_len);
	return (rest);
}

char *get_next_line(int fd)
{
	static char *rest;
	char *str;
	char *line;

	str = get_n_line(fd, rest);
	if (str == NULL)
		return NULL;
	line = ft_get_line(str);
	rest = ft_get_rest(str);
	free(str);
	return (line);
	
}
int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *s;
	while((s = get_next_line(fd)))
	{
		printf("%s", s);
	}
}
