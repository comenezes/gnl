/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:53:12 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/10 21:57:23 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*content;

	if ((read(fd, 0, 0) < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (!content)
	{
		content = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!content)
			return (NULL);
	}
	content = read_content(fd, content);
	line = strip_line(content);
	content = get_rest(content);
	return (line);
}
