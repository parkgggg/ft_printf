/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 02:44:47 by gupark            #+#    #+#             */
/*   Updated: 2022/03/16 03:07:52 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	len;

	len = 0;
	len += write(1, &c, 1);
	return (len);
}

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		s = "(null)";
	while (*s)
		len += write(1, s++, 1);
	return (len);
}
