/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:58:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 00:34:29 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_logic(const char *format, int i, va_list ap)
{
	int		len;

	len = 0;
	if (!ft_strncmp(format + i, "%%", 2))
		len += write(1, "%", 1);
	else if (!ft_strncmp(format + i, "%x", 2)
		|| !ft_strncmp(format + i, "%X", 2))
		len += put_hex(va_arg(ap, unsigned int), (char )(format[i + 1]));
	else if (!ft_strncmp(format + i, "%p", 2))
		len += print_p(va_arg(ap, unsigned long));
	else if (!ft_strncmp(format + i, "%c", 2))
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		len++;
	}
	else if (!ft_strncmp(format + i, "%s", 2))
		len += print_string(va_arg(ap, char *));
	else if (!ft_strncmp(format + i, "%d", 2)
		|| !ft_strncmp(format + i, "%i", 2))
		len += print_int(va_arg(ap, int));
	else if (!ft_strncmp(format + i, "%u", 2))
		len += print_unsigned_int(va_arg(ap, unsigned int));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] && format[i] != '%')
			len += write(1, &format[i], 1);
		if (format[i] == '%')
		{
			len += check_logic((char *)format, i, ap);
			i = i + 2;
		}
		else
			i++;
		va_end(ap);
	}
	return (len);
}
