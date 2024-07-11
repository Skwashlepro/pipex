/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prtx.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:14:26 by luctan            #+#    #+#             */
/*   Updated: 2023/11/28 19:11:47 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prtx(unsigned int nbr, unsigned int base)
{
	char	*bsd;
	int		i;

	i = 0;
	bsd = "0123456789abcdef";
	if (nbr >= base)
		i += prtx(nbr / base, base);
	return (i += write(1, &bsd[nbr % base], 1));
}

// int	main(int ac, char **av)
// {
// 	printf("%x\n", atoi(av[1]));
// 	printf("%s\n", "yours :");
// 	prtx(atoi(av[1]), 16);
// }
