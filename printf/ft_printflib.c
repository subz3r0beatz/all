/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:37:34 by fldumas-          #+#    #+#             */
/*   Updated: 2025/11/05 18:34:43 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthexprint(unsigned long long nbr, int order, char *hex)
{
	if (nbr > 0)
	{
		order = ft_puthexprint(nbr / 16, order, hex) + 1;
		nbr = nbr % 16;
		write(1, &hex[nbr], 1);
	}
	return (order);
}

int	ft_puthex(unsigned long long nbr, char type)
{
	char	*hex;
	int		order;

	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	order = 0;
	order = ft_puthexprint(nbr, order, hex);
	return (order);
}

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	write(1, "0x", 2);
	len = ft_puthex((unsigned long long)ptr, 'x') + 2;
	return (len);
}

static int	ft_putnbrprint(long long nbr, int order)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nbr > 0)
	{
		order = ft_putnbrprint(nbr / 10, order) + 1;
		nbr = nbr % 10 + 48;
		write(1, &nbr, 1);
	}
	return (order);
}

int	ft_putnbr(long long nbr)
{
	int	order;

	order = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		if (nbr < 0)
		{
			if (nbr != -2147483648)
			{
				write(1, "-", 1);
				nbr *= -1;
				order = 1;
			}
		}
		order = ft_putnbrprint(nbr, order);
	}
	return (order);
}
