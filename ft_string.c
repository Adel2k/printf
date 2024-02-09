/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeminian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:15:34 by aeminian          #+#    #+#             */
/*   Updated: 2024/02/09 23:07:07 by aeminian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_string(const char *str)
{
	int	count;

	count = ft_strlen(str);
	while (str && *str)
	{
		write(1, str, 1);
		str++;
	}
	return (count);
}

/*int	ft_digit(long n)
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

*/
