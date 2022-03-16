/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupark <gupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:29:05 by gupark            #+#    #+#             */
/*   Updated: 2022/03/16 02:47:33 by gupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_intndec(int i);
int	ft_print_undec(unsigned int u);
int	ft_print_hexlow(unsigned int x);
int	ft_print_hexup(unsigned int x);
int	ft_print_adr(unsigned long long p);
int	ft_printva(char c, va_list *va);
int	ft_printf(const char *types, ...);
#endif
