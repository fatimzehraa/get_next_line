/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 20:50:51 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/23 16:18:35 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include<stdio.h>

char	*ft_get_line(char *str)
{
	int		i;
	char	*line;

	if (str[0] == '\0')
		return (NULL);
	i = is_new_line(str);
	if (i == 0)
		i = ft_strlen(str);
	line = malloc((i + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strncpy(line, str, i);
	return (line);
}

char	*ft_get_rest(char *str)
{
	int		line_len;
	int		rest_len;
	char	*rest;

	if (str[0] == '\0')
		return (NULL);
	line_len = is_new_line(str);
	if (line_len == 0)
		line_len = ft_strlen(str);
	rest_len = ft_strlen(str + line_len);
	rest = malloc(sizeof(char) * (rest_len + 1));
	if (rest == NULL)
		return (NULL);
	ft_strncpy(rest, str + line_len, rest_len);
	return (rest);
}

t_list	*get_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*last;
	t_list	*new_node;

	current = *head;
	last = NULL;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		last = current;
		current = current->next;
	}
	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->rest = NULL;
	new_node->next = NULL;
	if (last == NULL)
		*head = new_node;
	else
		last->next = new_node;
	return (new_node);
}

void	free_node(t_list **head, int fd)
{
	t_list	*current;
	t_list	*previous;

	current = *head;
	previous = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous == NULL)
			{
				*head = current->next;
				free(current);
			}
			else
			{
				previous->next = current->next;
				free(current);
			}
			return ;
		}
		previous = current;
		current = current->next;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*node;
	char			*str;
	char			*line;

	node = get_node(&head, fd);
	if (node == NULL)
		return (NULL);
	str = get_until_newline(fd, node->rest);
	if (str == NULL)
	{
		free_node(&head, fd);
		return (NULL);
	}
	line = ft_get_line(str);
	node->rest = ft_get_rest(str);
	free(str);
	if (line == NULL)
		free_node(&head, fd);
	return (line);
}
