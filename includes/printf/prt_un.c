/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prt_un.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:13:16 by luctan            #+#    #+#             */
/*   Updated: 2023/11/30 18:07:50 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	prt_un(unsigned int n, unsigned int bsd)
{
	char	*base;
	int		i;

	i = 0;
	if (bsd == 10)
		base = "0123456789";
	else
		base = "0123456789abcdef";
	if (n >= bsd)
		i += prt_un(n / bsd, bsd);
	return (i += write(1, &base[n % bsd], 1));
}

// int	main(int ac, char **av)
// {
// 	prt_un(atoi(av[1]), atoi(av[2]));
// 	printf("%u\n", atoi(av[1]));
// }
