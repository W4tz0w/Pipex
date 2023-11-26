/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 17:40:16 by daddy_cool        #+#    #+#             */
/*   Updated: 2023/11/26 20:15:46 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Pipex/ft_pipex.h"

/* tube_fd[0] = Lecture
tube_fd[1] = Ecriture */
void	cmd1_process(char **argv, char **envp, int *tube_fd)
{
	int		infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		perror("\033[31;7mInfile opening went wrong\033[0m ");
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
		perror("\033[31;7mOutfile opening went wrong\033[0m ");
	dup2(tube_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(tube_fd[1]);
	execute(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		tube_fd[2];
	pid_t	pid_child;

	if (argc != 5)
		ft_putstr_fd("\033[31;7mWrong number of arguments\033[0m", 2);
	else
	{
		if (pipe(tube_fd) == -1)
			perror("\033[31;7mPipe went wrong\033[0m ");
		pid_child = fork();
		if (pid_child == -1)
			perror("\033[31;7mFork went wrong\033[0m ");
		if (pid_child == 0)
			cmd1_process(argv, envp, tube_fd);
		wait(NULL);
		cmd2_process(argv, envp, tube_fd);
	}
	return (0);
}
