/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:54:42 by luctan            #+#    #+#             */
/*   Updated: 2023/11/28 19:11:35 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt(long long int nbr, int base)
{
	char	*bsd;
	int		i;

	i = 0;
	bsd = NULL;
	if (base == 10)
		bsd = "0123456789";
	else if (base == 16)
		bsd = "0123456789ABCDEF";
	if (nbr < 0 && base == 10)
	{
		nbr *= -1;
		i += write (1, "-", 1);
	}
	if (nbr >= base)
		i += prt(nbr / base, base);
	return (i += write(1, &bsd[nbr % base], 1));
}
