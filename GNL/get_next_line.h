/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:38:19 by fldumas-          #+#    #+#             */
/*   Updated: 2025/11/15 14:34:58 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, ssize_t len, int flag);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strdup(const char *s);

void	*ft_callocmemcpy(size_t size, char *dest, char *src, int flag);

ssize_t	ft_strchr(const char *s, int c);

#endif
