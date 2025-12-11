/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <fldumas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 20:46:57 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/10 21:05:13 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

void    ft_bzero(void *arr, size_t len);
void    *ft_calloc(size_t size, size_t nmemb);

size_t	ft_strlen(const char *str);

#endif