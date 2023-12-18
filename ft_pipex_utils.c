/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:40:13 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/11/18 20:29:02 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	free_all_paths(char **all_paths)
{
	int		i;

	i = -1;
	while (all_paths[++i])
		free(all_paths[i]);
	free(all_paths);
}

char	*test_paths(char *cmd, char **envp)
{
	char	**all_paths;
	char	*path;
	char	*path_n_slash;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		path_n_slash = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(path_n_slash, cmd);
		free(path_n_slash);
		if (access(path, F_OK) == 0)
		{
			free_all_paths(all_paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_all_paths(all_paths);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = test_paths(cmd[0], envp);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("\033[31;7mcommand not found\033[0m ");
	}
	execve(path, cmd, envp);
	perror("\033[31;7mexecve\033[0m ");
}
