/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 22:53:02 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/10 22:38:39 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *ch);
char	*ft_strjoin(char const *s1, char const *s2);
int		ch_find_nl(char *text);
char	*read_content(int fd, char *content);
char	*strip_line(char *content);
char	*get_rest(char *content);
char	*get_next_line(int fd);
#endif
