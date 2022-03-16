/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <gupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:16:51 by gupark            #+#    #+#             */
/*   Updated: 2022/03/16 03:21:48 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_printva(char c, va_list *va)
{
	int	len;

	len = 0;
	if (c == '%')
		len += write(1, "%", 1);
	if (c == 'c')
		len += ft_print_char(va_arg(*va, int));
	if (c == 's')
		len += ft_print_str(va_arg(*va, char *));
	if (c == 'i' || c == 'd')
		len += ft_print_intndec(va_arg(*va, int));
	if (c == 'u')
		len += ft_print_undec(va_arg(*va, unsigned int));
	if (c == 'x')
		len += ft_print_hexlow(va_arg(*va, unsigned int));
	if (c == 'X')
		len += ft_print_hexup(va_arg(*va, unsigned int));
	if (c == 'p')
	{
		len += write(1, "0x", 2);
		len += ft_print_adr(va_arg(*va, unsigned long long));
	}
	return (len);
}

int	ft_printf(const char *types, ...)
{
	int		len;
	int		i;
	va_list	va;

	len = 0;
	i = 0;
	va_start(va, types);
	while (types[i])
	{
		if (types[i] != '%')
			len += write(1, &types[i], 1);
		if (types[i] == '%')
		{
			len += ft_printva(types[i + 1], &va);
			i++;
		}
		i++;
	}
	va_end(va);
	return (len);
}
