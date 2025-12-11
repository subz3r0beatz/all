/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:20:29 by fldumas-          #+#    #+#             */
/*   Updated: 2025/12/04 11:41:56 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	push_swap_check(char *list)
{
	size_t	i;

	while (list && list[i])
	{
		if (!list[i] || !ft_isdigit(list[i]) || !ft_strchr(list, list[i]))
			   return (0);
		i++;
	}
	return (1);
}

stack	push_swap_parsing(char *list)
{
	stack 
}

void	push_swap(char *list)
{
	stack	a;
	stack	b;

	if (!list || !push_swap_check(list))
	{
		ft_printf("Error\n");
		return ;
	}
	a = push_swap_parsing(list);
}
