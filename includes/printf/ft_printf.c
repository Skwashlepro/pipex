/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:42:23 by luctan            #+#    #+#             */
/*   Updated: 2023/12/04 16:29:11 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ptr;
	int		i;

	i = 0;
	va_start(ptr, str);
	if (str)
	{
		while (*str)
		{
			if (*str == '%')
				i += print_fmt(*++str, ptr, 0, 0);
			else if (str)
				i += write(1, str, 1);
			++str;
		}
	}
	va_end(ptr);
	return (i);
}
