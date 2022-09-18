/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:10:02 by ssergiu           #+#    #+#             */
/*   Updated: 2022/06/25 08:08:43 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int		print_p(unsigned long n);
int		print_string(char *str);
int		print_int(int n);
int		print_unsigned_int(unsigned int n);
int		ft_printf(const char *format, ...);
char	*ft_itoa_unsigned(unsigned int n);
int		hex_len(unsigned int n);
void	dectohex(unsigned int n, char format);
int		put_hex(unsigned int n, char format);
int		pointerhex(unsigned long n, int i);

#endif
