/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fldumas- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 21:13:33 by fldumas-          #+#    #+#             */
/*   Updated: 2025/11/06 09:42:58 by fldumas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if ((unsigned char)c == 0)
		return (1);
	return (0);
}

static int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	return (i);
}

static int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_typehandler(va_list argptr, char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchr((char)va_arg(argptr, int));
	else if (type == 's')
		len += ft_putstr((char *)va_arg(argptr, char *));
	else if (type == 'p')
		len += ft_putptr((void *)va_arg(argptr, void *));
	else if (type == 'd' || type == 'i')
		len += ft_putnbr((long long)va_arg(argptr, int));
	else if (type == 'u')
		len += ft_putnbr((long long)va_arg(argptr, unsigned int));
	else if (type == 'x' || type == 'X')
		len += ft_puthex((unsigned int)va_arg(argptr, unsigned int), type);
	else if (type == '%')
		len += ft_putchr('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list			argptr;
	unsigned int	i;
	unsigned int	count;

	if (!format)
		return (-1);
	va_start(argptr, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1] || !ft_strchr("cspdiuxX%", format[i + 1]))
				return (-1);
			count += ft_typehandler(argptr, format[i + 1]);
			i++;
		}
		else
			count += ft_putchr(format[i]);
		i++;
	}
	return (count);
}
