/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:14:02 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/10 21:14:07 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char    *buffer;
    char    *line;
    size_t  i;
    ssize_t readsize;

    buffer = ft_calloc(sizeof(char), 1);
    if (!buffer)
        return (NULL);
    readsize = read(fd, buffer, 1);
    line = NULL;
    while (readsize > 0)
    {
        line = ft_chradd(line, buffer);
        if (!line)
            break;
        readsize = read(fd, buffer, 1);
        if (readsize < 0)
        {
            free(line);
            line = NULL;
            break;
        }
        if (buffer[0] == '\n')
            return (line);
    }
    free(buffer);
    buffer = NULL;
    return (line);
}