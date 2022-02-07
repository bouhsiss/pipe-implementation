/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:15:15 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/02/07 15:15:17 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

// < infile  cmd1 | cmd2 outfile
// ./pipex infile cmd1 cmd2 outfile
int	openf(char *cmd, char *file)
{
	if (access(file, F_OK) == 0)
		return (open(file, O_RDONLY));
	else
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
		ft_putstr_fd(": No such file or directory", 2);
		return (-1);
	}
}

void	child(char **av, char **envp, int *end)
{
	int		fd1;
	char	*path;
	char	**cmd;

	cmd = ft_split(av[2], ' ');
	path = ft_paths(envp, findp(envp), cmd[0]);
	fd1 = openf(cmd[0], av[1]);
	if (fd1 == -1)
		exit(1);
	dup2(fd1, 0);
	close(fd1);
	dup2(end[1], 1);
	close(end[0]);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		exit(127);
	}
}

void	parent(char **av, char **envp, int *end)
{
	int		fd2;
	char	*path;
	char	**cmd;

	wait(0);
	cmd = ft_split(av[3], ' ');
	path = ft_paths(envp, findp(envp), cmd[0]);
	fd2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	dup2(fd2, 1);
	close(fd2);
	dup2(end[0], 0);
	close(end[1]);
	if (execve(path, cmd, envp) == -1)
	{
		ft_putstr_fd("zsh: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		exit(0);
	}
}

int	main(int ac, char **av, char **envp)
{
	int	end[2];
	int	id;

	if (ac == 5)
	{
		if (pipe(end) == -1)
		{
			perror("Pipe :");
			exit(1);
		}
		id = fork();
		if (id < 0)
			perror("Fork : ");
		else if (id == 0)
			child(av, envp, end);
		else
			parent(av, envp, end);
	}
	else
	{
		ft_putstr_fd("usage: <file1> <cmd1> <cmd2> <file2>", 2);
		exit(1);
	}
}
