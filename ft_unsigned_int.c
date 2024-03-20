/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:45:50 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/11 15:11:15 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
