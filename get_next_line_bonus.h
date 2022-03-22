/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fael-bou <fael-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 21:14:31 by fael-bou          #+#    #+#             */
/*   Updated: 2022/03/22 14:11:57 by fael-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include<unistd.h>
# include<stdlib.h>

typedef struct s_list{
	char			*rest;
	int				fd;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_strncpy(char *dst, char *src, size_t n);
int		is_new_line(char *s);

#endif
