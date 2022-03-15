/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:14:31 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/15 23:31:00 by fael-bou         ###   ########.fr       */
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
void ft_strncpy(char *dst, char *src, size_t n);
int is_new_line(char *s);

#endif