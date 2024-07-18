/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:50:01 by luctan            #+#    #+#             */
/*   Updated: 2024/07/18 05:27:09 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_data(t_pipex *data)
{
	int	i;

	i = -1;
	while (data->paths[++i])
		free(data->paths[i]);
	i = -1;
	while (data->cmd_args[++i])
		free(data->cmd_args[i]);
	free(data->cmd_args);
	free(data->paths);
	data = NULL;
}

char	**comma(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j])
			j++;
		if (av[i][j - 1] == ',')
			av[i][j - 1] = '\0';
		i++;
	}
	return (av);
}

int	main(int ac, char **av, char *envp[])
{
	t_pipex	data;

	if (ac == 5)
	{
		av = comma(av);
		data.f1 = open(av[1], O_RDONLY);
		data.f2 = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0644);
		pipex(&data, av, envp);
		close(data.f1);
		close(data.f2);
	}
	else
		ft_putstr_fd("Invalid Arguments\nuse it like : ./pipex infile cmd1 cmd2 outfile\n", 2);
	waitpid(data.pid1, &data.status, 0);
	waitpid(data.pid2, &data.status, 0);
	if (WIFEXITED(data.status))
		data.status = WEXITSTATUS(data.status);
	return (data.status);
}
