/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmenezes <cmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:05:02 by cmenezes          #+#    #+#             */
/*   Updated: 2022/11/10 22:28:49 by cmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *ch)
{
	size_t	i;

	i = 0;
	while (ch[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*chjoin;

	i = 0;
	j = 0;
	chjoin = malloc (ft_strlen (s1) + ft_strlen (s2) + 1);
	if (chjoin == NULL)
		return (NULL);
	while (s1 [i])
	{
		chjoin [i] = s1 [i];
		i++;
	}
	while (s2 [j])
	{
		chjoin [i + j] = s2 [j];
		j++;
	}
	chjoin [i + j] = '\0';
	return (chjoin);
}

int	ch_find_nl(char *text)
{
	int	i;

	i = 0;
	while (text [i])
	{
		if (text [i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

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
