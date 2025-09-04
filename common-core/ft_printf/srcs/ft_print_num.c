/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmanuell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:37:12 by mmanuell          #+#    #+#             */
/*   Updated: 2024/11/08 20:03:00 by mmanuell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunbr(unsigned int i)
{
	int	len;

	len = 0;
	if (i < 10)
	{
		len += ft_putchar(48 + (int) i);
	}
	else
	{
		len += ft_putunbr(i / 10);
		len += ft_putunbr(i % 10);
	}
	return (len);
}

int	ft_putnbr(int i)
{
	long	n;
	int		len;

	len = 0;
	n = i;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n < 10)
	{
		len += ft_putchar(48 + n);
	}
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putnbr(n % 10);
	}
	return (len);
}

static size_t	ft_baselen(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_putuinbr_base(unsigned int nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr < ft_baselen(base))
	{
		len += ft_putchar(base[nbr]);
	}
	if (nbr >= ft_baselen(base))
	{
		len += ft_putuinbr_base(nbr / ft_baselen(base), base);
		len += ft_putuinbr_base(nbr % ft_baselen(base), base);
	}
	return (len);
}

int	ft_putulnbr_base(unsigned long nbr, char *base)
{
	int	len;

	len = 0;
	if (nbr < ft_baselen(base))
	{
		len += ft_putchar(base[nbr]);
	}
	if (nbr >= ft_baselen(base))
	{
		len += ft_putulnbr_base(nbr / ft_baselen(base), base);
		len += ft_putulnbr_base(nbr % ft_baselen(base), base);
	}
	return (len);
}
