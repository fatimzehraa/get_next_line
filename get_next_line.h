/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:14:31 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/10 22:16:10 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include<unistd.h>
#include<stdlib.h>

# define BUFFER_SIZE 5


char    *get_next_line(int fd);
size_t  ft_strlen(char *s);
char    *ft_strjoin(char *s1, char *s2);
void    ft_bzero(void *str, size_t n);
void    *ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);

#endif