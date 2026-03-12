/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 13:51:53 by mirajora          #+#    #+#             */
/*   Updated: 2026/02/28 10:12:36 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char	*stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	return (line);
}

static char	*get_content(char	*stash, int fd)
{
	int		byte;
	char	*buff;
	char	*tmp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	byte = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && byte > 0)
	{
		byte = read (fd, buff, BUFFER_SIZE);
		if (byte < 0)
			return (free(buff), free(stash), NULL);
		if (byte == 0)
			break ;
		buff[byte] = '\0';
		if (!stash)
			stash = ft_strdup("");
		tmp = ft_strjoin(stash, buff);
		free(stash);
		stash = tmp;
	}
	free(buff);
	return (stash);
}

static char	*get_update_content(char	*stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = ft_strdup(stash + i);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = get_content(stash, fd);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = get_line(stash);
	stash = get_update_content(stash);
	return (line);
}
