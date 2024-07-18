/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:47:19 by luctan            #+#    #+#             */
/*   Updated: 2024/07/18 05:43:13 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parsing(char *envp[], char *cmd, t_pipex *data)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	ft_args(cmd);
	data->cmd_args = ft_split(cmd, ' ');
	if (ft_strchr(data->cmd_args[0], '/'))
		ft_abs_path(data, envp);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		return (1);
	data->envp_path = envp[i] + 5;
	data->paths = ft_split(data->envp_path, ':');
	while (data->paths[++j])
	{
		tmp = ft_strjoin(data->paths[j], "/");
		free(data->paths[j]);
		data->paths[j] = ft_strdup(tmp);
		free(tmp);
	}
	return (0);
}

void	child1_proc(t_pipex *data, int *pipette, char *envp[], char **av)
{
	int		i;
	char	*cmd;

	i = -1;
	close(data->f2);
	close(pipette[0]);
	if (dup2(data->f1, STDIN_FILENO) < 0)
		return (perror("Permission denied"), exit(0));
	close(data->f1);
	if (dup2(pipette[1], STDOUT_FILENO) < 0)
		return (perror("STDOUT_CHILD1"), exit(0));
	close(pipette[1]);
	if (parsing(envp, av[2], data))
		ft_exit(av[2]);
	while (data->paths[++i])
	{
		cmd = ft_strjoin(data->paths[i], data->cmd_args[0]);
		ft_execute(cmd, envp, data);
		free(cmd);
	}
	free_data(data);
	ft_exit(av[2]);
}

void	child2_proc(t_pipex *data, int *pipette, char *envp[], char **av)
{
	int		i;
	char	*cmd;

	i = -1;
	close(data->f1);
	close(pipette[1]);
	if (dup2(data->f2, STDOUT_FILENO) < 0)
		return (perror("Permission denied"), exit(1));
	close(data->f2);
	if (dup2(pipette[0], STDIN_FILENO) < 0)
		return (perror("STDIN_CHILD2"), exit(1));
	close(pipette[0]);
	if (parsing(envp, av[3], data))
		ft_exit(av[3]);
	while (data->paths[++i])
	{
		cmd = ft_strjoin(data->paths[i], data->cmd_args[0]);
		ft_execute(cmd, envp, data);
		free(cmd);
	}
	free_data(data);
	ft_exit(av[3]);
}

int	pipex(t_pipex *data, char **av, char *envp[])
{
	int	pipette[2];
	
	if (pipe(pipette) < 0)
		return (perror("Error : Unable to initialize pipe\n"), 1);
	data->pid1 = fork();
	if (data->pid1 < 0)
		return (perror("Error : Unable to fork\n"), 1);
	else if (data->pid1 == 0)
		child1_proc(data, pipette, envp, av);
	data->pid2 = fork();
	if (data->pid2 < 0)
		return (perror("Error : Unable to fork\n"), 1);
	else if (data->pid2 == 0)
		child2_proc(data, pipette, envp, av);
	close(pipette[0]);
	close(pipette[1]);
	return (0);
}
