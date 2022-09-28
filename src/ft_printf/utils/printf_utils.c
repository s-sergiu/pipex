/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:18:13 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/27 21:45:35 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	hex_len(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 16;
	}
	return (count);
}

void	dectohex(unsigned int n, char format)
{
	unsigned int	temp;

	if (n == 0)
		;
	else
	{
		dectohex(n / 16, format);
		temp = n % 16;
		if (temp > 9)
		{
			temp += 87;
			if (format == 'X')
				temp -= 32;
			ft_putchar_fd(temp, 1);
		}
		else
			ft_putnbr_fd(temp, 1);
	}
}

int	put_hex(unsigned int n, char format)
{
	if (n == 0)
		return (write(1, "0", 1));
	dectohex(n, format);
	return (hex_len(n));
}

int	pointerhex(unsigned long n, int i)
{
	int	temp;

	if (n == 0)
	{
		ft_putnbr_fd(n, 1);
		ft_putchar_fd('x', 1);
	}
	else
	{
		i = i + pointerhex(n / 16, 1);
		temp = n % 16;
		if (temp > 9)
		{
			temp += 87;
			ft_putchar_fd(temp, 1);
		}
		else
			ft_putnbr_fd(temp, 1);
	}
	return (i);
}
