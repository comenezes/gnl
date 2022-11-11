/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 22:53:12 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/10 23:53:07 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_content(int fd, char *content)
{
	int		nbytes;
	char	*temp;
	char	*cache;

	temp = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	nbytes = 1;
	while (nbytes != 0 && !ch_find_nl (temp))
	{
		nbytes = read(fd, temp, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free(temp);
			free(content);
			return (NULL);
		}
		temp[nbytes] = '\0';
		cache = ft_strjoin (content, temp);
		free (content);
		content = cache;
	}
	free (temp);
	return (content);
}

char	*strip_line(char *content)
{
	int		i;
	char	*temp;

	i = 0;
	while (content [i] != '\n' && content [i] != '\0')
		i++;
	temp = malloc (sizeof (char) * i + 2);
	temp [i + 1] = '\0';
	while (i >= 0)
	{
		temp [i] = content [i];
		i--;
	}
	return (temp);
}

char	*get_rest(char *content)
{
	size_t	i;
	int		j;
	char	*temp;

	i = 0;
	while ((content[i] != '\n') && (content[i] != '\0'))
		i++;
	if (content [i] == '\n')
		i++;
	temp = malloc (sizeof (char) * (ft_strlen (content) - i + 1));
	if (!temp)
		return (NULL);
	j = -1;
	while (i <= ft_strlen (content))
	{
		temp [++j] = content [i++];
	}
	temp [j + 1] = '\0';
	free (content);
	return (temp);
}

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
