/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:39:38 by fldumas-          #+#    #+#             */
/*   Updated: 2025/11/15 16:41:38 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

ssize_t	ft_strchr(const char *s, int c)
{
	ssize_t	i;

	i = 0;
	while (s && s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (i + 1);
		i++;
	}
	if ((unsigned char)c == 0)
		return (i + 1);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ns;

	if (!s)
		return (NULL);
	i = ft_strchr(s, '\0') - 1;
	ns = (char *)malloc(sizeof(char) * (i + 1));
	if (!ns)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = '\0';
	return (ns);
}

void	*ft_callocmemcpy(size_t size, char *dest, char *src, int flag)
{
	unsigned char	*arr;

	if (flag)
	{
		if (size > INT_MAX)
			return (0);
		arr = (unsigned char *)malloc(size);
		if (!arr)
			return (NULL);
		while (size)
		{
			size--;
			arr[size] = 0;
		}
		return (arr);
	}
	while (size > 0)
	{
		size--;
		((unsigned char *)dest)[size] = ((unsigned char *)src)[size];
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	ls1;
	size_t	ls2;
	size_t	lns;
	char	*ns;

	if (!s1)
	{
		ns = ft_strdup(s2);
		return (ns);
	}
	if (!s2)
		return ((char *)s1);
	ls1 = ft_strchr(s1, '\0') - 1;
	ls2 = ft_strchr(s2, '\0') - 1;
	lns = ls1 + ls2;
	ns = ft_callocmemcpy(lns + 1, NULL, NULL, 1);
	if (!ns)
		return (NULL);
	ft_callocmemcpy(ls1, ns, s1, 0);
	ft_callocmemcpy(ls2 + 1, ns + ls1, (char *)s2, 0);
	free((char *)s1);
	return (ns);
}

char	*ft_substr(char *s, unsigned int start, ssize_t len, int flag)
{
	ssize_t	i;
	ssize_t	slen;
	char	*ns;

	if (flag)
		ns = (char *)ft_callocmemcpy(BUFFER_SIZE + 1, NULL, NULL, 1);
	else
	{
		slen = ft_strchr(s, '\0') - start;
		if (slen > len)
			slen = len;
		ns = (char *)ft_callocmemcpy((slen + 1), NULL, NULL, 1);
	}
	if (!ns)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		ns[i] = s[i + start];
		i++;
	}
	free((char *)s);
	return (ns);
}
