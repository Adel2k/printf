/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 14:41:22 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/11 09:19:07 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

int ft_printf(const char *format, ...);
int	ft_parser(va_list args, const char s);
int	ft_putchar(int c);
int	ft_strlen(const char *str);
int	ft_string(const char *str);
//int	ft_digit(long n);
#endif
