/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:46:32 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/10 20:55:09 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t size, size_t nmemb)
{
	unsigned char	*arr;

	if (!size || !nmemb)
	{
		arr = (unsigned char *)malloc(0);
		return (arr);
	}
	if (size > ((size_t)-1) / nmemb)
		return (0);
	arr = (unsigned char *)malloc(size * nmemb);
	if (!arr)
		return (NULL);
	ft_bzero(arr, size * nmemb);
	return (arr);
}