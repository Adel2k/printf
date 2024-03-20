/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:55:33 by aeminian          #+#    #+#             */
/*   Updated: 2024/03/10 19:50:49 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (s == 'x' || s == 'X')
		count += ft_hex(va_arg(args, unsigned int), s);
	else if (s == 'p')
	{
		write(1, "0x", 2);
		count = 2 + ft_pointer(va_arg(args, unsigned long long ));
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				count += ft_putchar('%');
			else if (*format == 0)
				break ;
			count += ft_parser(ap, *format);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(ap);
	return (count);
}

int main ()
{
//   printf("%d\n",printf("cspdiuxX%"));
//	printf("%d\n", ft_printf("cspdiuxX%"));

	ft_printf("%p\n", "42");
	printf("%p", "42");


}
