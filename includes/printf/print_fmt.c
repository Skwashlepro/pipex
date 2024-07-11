/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_fmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:59:36 by luctan            #+#    #+#             */
/*   Updated: 2024/05/16 03:32:11 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_fmt(char str, va_list ptr, int i,	size_t j)
{
	if (str == 'c')
		i += prt_char(va_arg(ptr, int));
	else if (str == 's')
		i += prt_str(va_arg(ptr, char *));
	else if (str == 'p')
	{
		j = va_arg(ptr, size_t);
		if (!j)
			return (i += write(1, "(nil)", 5));
		return (i += write(1, "0x", 2), i += prt_adr(j, 16));
	}
	else if (str == 'd' || str == 'i')
		i += prt((long long int)va_arg(ptr, int), 10);
	else if (str == 'u')
		i += prt_un(va_arg(ptr, unsigned int), 10);
	else if (str == 'X')
		i += prt(va_arg(ptr, unsigned int), 16);
	else if (str == 'x')
		i += prtx(va_arg(ptr, unsigned int), 16);
	else if (str == '%')
		i += write(1, "%", 1);
	else if (str)
		return (i += write(1, "%", 1), i += write(1, &str, 1));
	return (i);
}

// int	is_s(va_list ptr, int i)
// {
// 	char	*j;

// 	j = va_arg(ptr, char *);
// 	if (j)
// 		i += prt_str(j);
// 	else if (!j)
// 		i += write(1, "(null)", 6);
// 	return (i);
// }
