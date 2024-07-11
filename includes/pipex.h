/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:50:16 by luctan            #+#    #+#             */
/*   Updated: 2024/07/11 21:35:30 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

#endif
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"
#include "gnl/get_next_line.h"

typedef struct s_pipex
{
	char **paths;
	char **cmd_args;
	int f1;
	int	f2;
	
}	t_pipex;


void	pipex(int f1, int f2, char **av, char *envp[]);