/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:33 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/11 09:17:15 by adel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}

int	ft_count(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_digit(int n)
{
	int	count;

	count = ft_count(n);
	if (n == INT_MIN)
		{
			ft_putchar('-');
			ft_putchar('2');
			n = 147483648;
		}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_digit(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + 48);
	return (count);
}

int	ft_unsigned_int(unsigned int n)
{
	int	count;

	count = ft_count(n);
	if (n == INT_MAX)
			n = 2147483647;
	if (n >= 10)
	{
		ft_digit(n / 10);
		n = n % 10;
	}
	if (n < 10)
		ft_putchar(n + 48);
	return (count);
}
int	ft_hex(int n, const char s)
{
	int	count;
	char	*symbols;

	count = 0;
	if (s == 'x')
		symbols = "0123456789abcdef";
	else if (s == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (ft_hex(-n, s) + 1);
	}
	else if (n < 16)
		ft_putchar(symbols[n]);
	else 
	{
		count = ft_hex((n / 16), s);
		return ( count + ft_hex(n % 16, s));
	}
	return (count);
}

int	ft_parser(va_list args, const char s)
{
	int	count;

	count = 0;
	if (s == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (s == 's')
		count += ft_string(va_arg(args, char *));
	else if (s == 'd' || s == 'i')
		count += ft_digit(va_arg(args, int));
	else if (s == 'u' )
		count += ft_unsigned_int(va_arg(args, unsigned int));
	else if (s == 'x')
		count += ft_hex(va_arg(args, int), s);
	else if (s == 'X')
		count += ft_hex(va_arg(args, int), s);
	return (count);
}


int ft_printf(const char *format, ...)
{
    va_list ap;
    int count;

    va_start(ap, format);
    count = 0;
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
                count += ft_putchar('%');
            count += ft_parser(ap, *format);
        }
        else
            count += ft_putchar(*format);
        format++;
    }
	va_end(ap);
    return (count);
}
/*
int main ()
{
	long i = -123456;
    printf("%d\n",ft_digit(i));
	printf("%d\n", printf("%ld", i));
}*/
