/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:03:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/10 21:58:02 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

size_t ft_strlen(char *s)
{
    size_t i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
    char *s;
    int s1_len;
    int s2_len;
    int i;

    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);

    s = malloc((s1_len + s2_len) * sizeof(char));
    if (s == NULL)
        return(NULL);
    i = 0;
    while (s1[i])
    {
        s[i] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        s[s1_len + i] = s2[i];
        i++;
    }

    return (s);
}

void ft_bzero(void *str, size_t n)
{
    char *s;
    size_t i;

    s = (char *)str;
    i = 0;
    while(i < n)
    {
        s[i] = 0;
        i++;
    }
}

void *ft_calloc(size_t count, size_t size)
{
    char *s;
    size_t i;

    i = 0;
    s = malloc(size * count);
    if(s == NULL)
        return (NULL);
    while(i < size * count)
    {
        s[i] = '\0';
        i++;
    }
    return (s);
}

char	*ft_strchr(const char *s, int c)
{
	char	a;
	int		i;

	a = (char)c;
	i = 0;
	if (a == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

void befor_new_line(char *line)
{
    int i;
    int j;
    int check_new_line;
    char *befor;
    char *after;

    i = 0;
    j = 0;
    check_new_line = 1;
    while(line[i])
    {
        if(line[i] != '\n' && check_new_line)
        {
            befor[i] = line[i];
        }
        else
        {
            check_new_line = 0;
            after[j] = line[i];
        }
        i++;
        j++;
    }
}

// int main ()
// {
//     char str[] = "hello world";
//     printf("%s", str);
//     ft_bzero(str, 5);
//     if (str[0] == 0)
//         printf("khawyaa");
//     printf("%s", str);
// }