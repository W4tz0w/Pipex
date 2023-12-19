/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:40:16 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/12/19 12:36:07 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

/* tube_fd[0] = Lecture
tube_fd[1] = Ecriture */
void	cmd1_process(char **argv, char **envp, int *tube_fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
	{
		perror("\033[31;7mInfile opening went wrong\033[0m ");
		exit(EXIT_FAILURE);
	}
	dup2(tube_fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(tube_fd[0]);
	execute(argv[2], envp);
}

void	cmd2_process(char **argv, char **envp, int *tube_fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
		perror("\033[31;7mOutfile opening went wrong\033[0m ");
		exit(EXIT_FAILURE);
	}
	dup2(tube_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(tube_fd[1]);
	execute(argv[3], envp);
}

int	ft_macro_pipex(char **argv, char **envp)
{
	int		tube_fd[2];
	pid_t	pid_child;

	if (pipe(tube_fd) == -1)
	{
		perror("\033[31;7mPipe went wrong\033[0m ");
		exit(EXIT_FAILURE);
	}
	pid_child = fork();
	if (pid_child == -1)
	{
		perror("\033[31;7mFork went wrong\033[0m ");
		exit(EXIT_FAILURE);
	}
	if (pid_child == 0)
		cmd1_process(argv, envp, tube_fd);
	waitpid(0, NULL, WNOHANG);
	cmd2_process(argv, envp, tube_fd);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		ft_putstr_fd("\033[31;7mWrong number of arguments\033[0m", 2);
		exit(EXIT_FAILURE);
	}
	else
		ft_macro_pipex(argv, envp);
	return (0);
}
