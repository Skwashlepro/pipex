/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luctan <luctan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:50:16 by luctan            #+#    #+#             */
/*   Updated: 2024/07/18 05:04:55 by luctan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	char	**paths;
	char	**cmd_args;
	char	*envp_path;
	int		f1;
	int		f2;
	int		status;
	pid_t	pid1;
	pid_t	pid2;

}			t_pipex;

int			pipex(t_pipex *data, char **av, char *envp[]);
void		free_data(t_pipex *data);
void		ft_swap(t_pipex *data);
int			child_status(int status);
void		ft_execute(char *cmd, char *envp[], t_pipex *data);
void		ft_args(char *cmd);
void		ft_exit(char *cmd);
void		ft_abs_path(t_pipex *data, char *envp[]);

#endif