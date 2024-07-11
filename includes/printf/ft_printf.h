/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:43:10 by luctan            #+#    #+#             */
/*   Updated: 2024/05/09 02:21:34 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		print_fmt(char str, va_list ptr, int i, size_t j);
int		prt_adr(unsigned long int p, unsigned long int bsd);
int		prt_char(int c);
int		prt_str(char *str);
int		prt_un(unsigned int n, unsigned int bsd);
int		prt(long long int nbr, int base);
int		prtx(unsigned int nbr, unsigned int base);

#endif