/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:47:19 by luctan            #+#    #+#             */
/*   Updated: 2024/07/11 21:41:41 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	parsing(char *envp[], char **av, t_pipex *data)
{
	char *envp_path;
	
	envp_path = ft_substr(envp, 0, ft_strlen(envp));
	data->paths = ft_split(envp, ':');
	data->cmd_args = ft_split(av[2], ' ');
}

void	child_proc(t_pipex *data, int *pipette, char *envp[])
{
	int	status;
	int	i;
	char *cmd;
	
	i = -1;
	if (dup2(data->f1, STDIN_FILENO) < 0);
		return (close(data->f1), perror("STDIN_CHILD"));	
	if (dup2(pipette[1], STDOUT_FILENO) < 0);
		return (close(pipette[1]), perror("STDOUT_CHILD"));
	close(pipette[0]);
	close(data->f1);
	while (data->paths[++i])
	{
		cmd = ft_strjoin(data->paths[i], data->cmd_args[0]);
		execve(data->paths[i], data->cmd_args, envp);
		free(cmd);
	}
}

void	parent_proc(t_pipex *data, int *pipette, char *envp[])
{
	int	status;
	int		i;
	char	*cmd;

	i = -1;
	waitpid(-1, &status, 0);
	if (dup2(data->f2, STDOUT_FILENO) < 0);
		return (perror("STDOUT_PARENT"));
	if (dup2(pipette[0], STDIN_FILENO) < 0);
		return (perror("STDIN_PARENT"));
	close(pipette[1]);
	close(data->f2);
}

void	pipex(t_pipex *data, char **av, char *envp[])
{
	int	pipette[2];
	pid_t papa;

	pipe(pipette);
	papa = fork();
	parsing(envp, av, data);
	if (papa < 0)
		return (perror("ah zebi"));
	if (!papa)
		child_proc(data, *pipette, envp);
	else
		parent_proc(data, *pipette, envp);
}