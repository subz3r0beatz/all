/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:38:27 by fldumas-          #+#    #+#             */
/*   Updated: 2025/11/15 16:57:15 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_protectandmalloc(int fd, char *buffer)
{
	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_callocmemcpy(BUFFER_SIZE + 1, NULL, NULL, 1);
	return (buffer);
}

ssize_t	ft_protectedread(char *buffer, char *line, int fd, int flag)
{
	ssize_t	readsize;

	readsize = 0;
	if (flag)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize == -1)
		{
			free(line);
			line = NULL;
		}
		return (readsize);
	}
	if (!buffer[0])
		readsize = read(fd, buffer, BUFFER_SIZE);
	else
		readsize = ft_strchr(buffer, '\0') - 1;
	return (readsize);
}

char	*ft_get_line(char **buffer, char *line, ssize_t readsize)
{
	ssize_t	nextn;

	nextn = 0;
	line = ft_strjoin(line, *buffer);
	if (!line)
		return (NULL);
	nextn = ft_strchr(*buffer, '\n');
	if (nextn)
	{
		line = ft_substr(line, 0, ft_strchr(line, '\n'), 0);
		*buffer = ft_substr(*buffer, nextn, readsize - nextn, 1);
		if (!*buffer)
			return (NULL);
		return (line);
	}
	free(*buffer);
	*buffer = ft_callocmemcpy(BUFFER_SIZE + 1, NULL, NULL, 1);
	if (!*buffer)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	ssize_t		readsize;

	buffer = ft_protectandmalloc(fd, buffer);
	if (!buffer)
		return (NULL);
	line = NULL;
	readsize = ft_protectedread(buffer, line, fd, 0);
	while (readsize > 0)
	{
		line = ft_get_line(&buffer, line, readsize);
		if (!line)
			return (NULL);
		if (ft_strchr(line, '\n'))
			return (line);
		readsize = ft_protectedread(buffer, line, fd, 1);
		if (readsize == -1)
			return (NULL);
		if (!readsize)
			break ;
	}
	free(buffer);
	buffer = NULL;
	return (line);
}
