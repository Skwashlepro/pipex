/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:55:36 by luctan            #+#    #+#             */
/*   Updated: 2024/07/17 22:21:50 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_status(int status)
{
	int	exit_stat;

	exit_stat = 0;
	if (WIFEXITED(status))
		exit_stat = WEXITSTATUS(status);
	return (exit_stat);
}

void	ft_execute(char *cmd, char *envp[], t_pipex *data)
{
	if (access(cmd, F_OK | X_OK | R_OK) == 0)
		execve(cmd, data->cmd_args, envp);
	if (access(cmd, X_OK | R_OK) < 0 && access(cmd, F_OK) == 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
}

void	ft_exit(char *av, t_pipex *data)
{
	if (av)
		ft_putstr_fd(av, 2);
	ft_putstr_fd(": No such file or directory\nCommand not found", 2);
	free_data(data);
	exit(127);
}

void	ft_args(char *cmd)
{
	int	i;
	int	letters;

	i = -1;
	letters = 1;
	while (cmd[++i])
		if (ft_isalpha(cmd[i]))
			return ;
	if (!cmd[i])
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
}
