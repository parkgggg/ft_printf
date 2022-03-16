/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:22:12 by gupark            #+#    #+#             */
/*   Updated: 2022/03/16 03:07:16 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_intndec(int i)
{
	long long	n;
	int			len;

	n = i;
	len = 0;
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		len += ft_print_intndec(n / 10);
		len += ft_print_intndec(n % 10);
	}
	else
		len += ft_print_char(n + 48);
	return (len);
}

int	ft_print_undec(unsigned int u)
{
	int	len;

	len = 0;
	if (u >= 10)
	{
		len += ft_print_undec(u / 10);
		len += ft_print_undec(u % 10);
	}
	else
		len += ft_print_char(u + 48);
	return (len);
}

int	ft_print_hexlow(unsigned int x)
{
	int	len;

	len = 0;
	if (x >= 16)
	{
		len += ft_print_hexlow(x / 16);
		len += ft_print_hexlow(x % 16);
	}
	else
	{
		if (x < 10)
			len += ft_print_char(x + 48);
		else
			len += ft_print_char(x + 87);
	}
	return (len);
}

int	ft_print_hexup(unsigned int x)
{
	int	len;

	len = 0;
	if (x >= 16)
	{
		len += ft_print_hexup(x / 16);
		len += ft_print_hexup(x % 16);
	}
	else
	{
		if (x < 10)
			len += ft_print_char(x + 48);
		else
			len += ft_print_char(x + 55);
	}
	return (len);
}

int	ft_print_adr(unsigned long long p)
{
	int	len;

	len = 0;
	if (p >= 16)
	{
		len += ft_print_adr(p / 16);
		len += ft_print_adr(p % 16);
	}
	if (p < 16)
	{
		if (p < 10)
			len += ft_print_char(p + 48);
		else
			len += ft_print_char(p + 87);
	}
	return (len);
}
