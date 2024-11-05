/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:46:58 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/05 14:52:59 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int i)
{
	long	n;

	n = i;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar(48 + n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	parameters;

	va_start(parameters, str);
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			//write(1, &str[i], 1);
			ft_putchar(str[i]);
			i++;
		}
		if (str[i] && str[i + 1])
		{
			i++;
			if (str[i] == 'd')
				ft_putnbr((int) va_arg(parameters, int));
			if (str[i] == 's')
				ft_putstr((char *) va_arg(parameters, char *));

			i++;
		}
	}
	return (0);
}

int main (int argc, char **argv)
{
	if (argc > 3)
		ft_printf(argv[1], argv[2], atoi(argv[3]));
	return (0);
}
