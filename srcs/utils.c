/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:55:36 by luctan            #+#    #+#             */
/*   Updated: 2024/07/18 05:41:52 by luctan           ###   ########.fr       */
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
	else if (access(cmd, X_OK | R_OK) < 0 && access(cmd, F_OK) == 0)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": Permission denied\n", 2);
		exit(126);
	}
}

void	ft_exit(char *av)
{
	if (av)
		ft_putstr_fd(av, 2);
	ft_putstr_fd(": Command not found\nNo such file or directory\n", 2);
	exit(127);
}

void	ft_args(char *cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		if (ft_isalpha(cmd[i]))
			return ;
	if (!cmd[i])
	{
		ft_putstr_fd("Command not found\n", 2);
		exit(127);
	}
}

void	ft_abs_path(t_pipex *data, char *envp[])
{
	if (ft_strchr(data->cmd_args[0], '/'))
	{
		if (access(data->cmd_args[0], X_OK | R_OK) < 0 && access(data->cmd_args[0], F_OK) == 0)
		{
			ft_putstr_fd(data->cmd_args[0], 2);
			ft_putstr_fd(": Permission denied\n", 2);
			exit(126);
		}
		if (access(data->cmd_args[0], F_OK | X_OK | R_OK) == 0)
			execve(data->cmd_args[0], data->cmd_args, envp);
		else if (access(data->cmd_args[0], F_OK < 0) && WIFEXITED(data->status))
		{
			ft_putstr_fd("No such file or directory\n", 2);
			exit(127);
		}
	}
}
