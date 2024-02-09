/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:33 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/09 23:07:56 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(int c)
{
    write(1, &c, 1);
    return (1);
}
int	ft_digit(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		count++;
		n /= 10;
	}
	if (n < 0)
	{
		ft_putchar('-');
		ft_digit(-n);
	}
	if (n >= 10)
	{
		ft_digit(n / 10);
		n = n %  10;
	}
	if (n < 10)
		ft_putchar(n + 48);
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
		count += ft_digit(va_arg(args, long));
/*	else if (s == 'u' )
		count += ft_digit(va_arg(args, int), s);
	else if (s == 'x' || s == 'X')
		count += ft_digit(va_arg(args, int ), s);*/
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
/*int main ()
{
    int n = 5;
    ft_printf("My printf = %d\n", n);
    print("org = %d", n);
}*/
