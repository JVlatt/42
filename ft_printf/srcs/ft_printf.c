/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:46:58 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/08 20:03:55 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_select_print_func(char c, va_list parameters)
{
	if (c == 'c')
		return (ft_putchar(va_arg(parameters, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(parameters, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(parameters, unsigned int)));
	else if (c == 'x')
		return (ft_putuinbr_base(va_arg(parameters, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putuinbr_base(va_arg(parameters, unsigned int),
				"0123456789ABCDEF"));
	else if (c == 'p')
		return (ft_putptr(va_arg(parameters, void *)));
	else if (c == 's')
		return (ft_putstr(va_arg(parameters, char *)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	parameters;

	va_start(parameters, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			len += ft_putchar(str[i]);
			i++;
		}
		if (str[i] && str[i + 1])
		{
			len += ft_select_print_func(str[i + 1], parameters);
			i += 2;
		}
		else if (str[i])
			i++;
	}
	return (len);
}
