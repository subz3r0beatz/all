/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 15:03:26 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/04 11:44:43 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack
{
	int				*content;
	struct s_list	*next;
	struct s_list	*prev;
}					t_stack;

size_t	ft_isdigit(int c);
size_t	ft_strchr(const char *s, int c);

int	ft_printf(const char *format, ...);
int	ft_atoi(const char *nptr);

#endif
