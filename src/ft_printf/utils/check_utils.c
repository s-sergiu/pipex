/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 08:06:57 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/27 21:45:35 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

int	print_p(unsigned long n)
{
	int	len;

	len = 0;
	if (n != 0)
		len += 2 + pointerhex(n, 0);
	else
	{
		len += 3;
		ft_putstr_fd("0x0", 1);
	}
	return (len);
}

int	print_string(char *str)
{
	int	len;

	len = 0;
	if (str != NULL)
	{
		len += ft_strlen(str);
		ft_putstr_fd(str, 1);
	}
	else
	{
		len += 6;
		ft_putstr_fd("(null)", 1);
	}
	return (len);
}

int	print_int(int n)
{
	char	*temp;
	int		len;

	len = 0;
	temp = ft_itoa(n);
	len += ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	free(temp);
	return (len);
}

int	print_unsigned_int(unsigned int n)
{
	char	*temp;
	int		len;

	len = 0;
	temp = ft_itoa_unsigned(n);
	len += ft_strlen(temp);
	ft_putstr_fd(temp, 1);
	free(temp);
	return (len);
}
