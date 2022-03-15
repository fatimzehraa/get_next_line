/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:03:13 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/15 20:29:55 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

size_t ft_strlen(char *s)
{
    size_t i;

    i = 0;
    if(s == NULL)
        return (0);
    while(s[i])
        i++;
    return (i);
}

void ft_strncpy(char *dst, char *src, size_t n)
{
    size_t i;

    i = 0;
    while(i < n && src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = 0;
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
    ft_strncpy(s, s1, s1_len);
    ft_strncpy(s + s1_len, s2, s2_len);
    return (s);
}

int is_new_line(char *s)
{
	int		i;

	i = 0;
    if (s == NULL)
        return 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}










// void befor_new_line(char *line)
// {
//     int i;
//     int j;
//     int check_new_line;
//     char *befor;
//     char *after;

//     i = 0;
//     j = 0;
//     check_new_line = 1;
//     while(line[i])
//     {
//         if(line[i] != '\n' && check_new_line)
//         {
//             befor[i] = line[i];
//         }
//         else
//         {
//             check_new_line = 0;
//             after[j] = line[i];
//         }
//         i++;
//         j++;
//     }
// }

// int main ()
// {
//     char str[] = "hello world";
//     printf("%s", str);
//     ft_bzero(str, 5);
//     if (str[0] == 0)
//         printf("khawyaa");
//     printf("%s", str);
// }