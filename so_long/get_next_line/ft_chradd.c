/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:34:29 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/11 13:17:09 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_chradd(char *str, char chr)
{
	size_t	i;
	size_t	str_len;
	char	*new_str;

	if (!str)
	{
		new_str = ft_calloc(sizeof(char), 2);
		new_str[0] = chr;
		return (new_str);
	}
	str_len = ft_strlen(str);
	new_str = ft_calloc(sizeof(char), str_len + 2);
	if (!new_str)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	i = 0;
	while(str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
    str = NULL;
	return (new_str);
}