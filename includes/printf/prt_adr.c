/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_adr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:51:41 by luctan            #+#    #+#             */
/*   Updated: 2023/11/30 18:28:53 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	prt_adr(size_t p, unsigned long int bsd)
{
	int					i;
	char				*base;

	base = "0123456789abcdef";
	i = 0;
	if (p >= bsd)
		i += prt_adr(p / bsd, bsd);
	i += write(1, &base[p % bsd], 1);
	return (i);
}

// int	main(void)
// {
// 	void *min;
// 	void *max;

// 	min = (void *)LONG_MIN;
// 	max = (void *)LONG_MAX;
// 	ft_printf(" %p %p \n", min, max);
// 	printf(" %p %p \n", min, max);
// }
