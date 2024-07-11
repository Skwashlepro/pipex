/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:50:01 by luctan            #+#    #+#             */
/*   Updated: 2024/07/11 21:14:54 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(char **av, int ac, char *envp[])
{
	t_pipex *data;

	data->f1 = open(av[1], O_RDONLY);
	data->f2 = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (data->f1 > 0 && data->f2 > 0 && ac == 5 && envp[0])
		pipex(data, av, envp);
	else if (data->f1 < 0 || data->f2 < 0)
		return (-1);
	return (0);
}