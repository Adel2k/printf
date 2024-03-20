/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:46:45 by aeminian          #+#    #+#             */
/*   Updated: 2024/03/10 19:53:57 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int n, const char s)
{
	int		count;
	char	*symbols;

	count = 0;
	if (s == 'x')
		symbols = "0123456789abcdef";
	else if (s == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 16)
	{
		count++;
		ft_putchar(symbols[n]);
	}
	else
	{
		count = ft_hex((n / 16), s);
		return (count + ft_hex(n % 16, s));
	}
	return (count);
}
