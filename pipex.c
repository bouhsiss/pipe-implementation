#include"pipex.h"

// < infile  cmd1 | cmd2 outfile
// ./pipex infile cmd1 cmd2 outfile

void child(char **av, char **envp, int **end)
{
	int fd1;
	char *path;

	close(end[0]);
	path = ft_path(envp, findp(envp), av[2]);
	fd1 = open(av[1], O_RDONLY);
	dup2(fd1, 0);
	dup2(end[1], 1);
}

void parent(char **av, char **envp, int **end)
{
	int fd2;
	char *path;

	wait(NULL);
	close(end[1]);
	path = ft_path(envp, findp(envp), av[3]);
	fd2 = open(av[4], O_WRONLY);
	dup2(end[0], 0);
	dup2(fd2, 1);
}

int main(int ac, char **av, char **envp)
{
	int end[2];
	int id;

	id = fork();
	if (pipe(end) == -1)
	{
		perror("Pipe :");
		exit(1);
	}
	if (id < 0)
	{
		perror("Fork :");
		exit(1);
	}
	else if (id == 0)
		child(av, envp, end);
	else
		parent(av, envp, end);
}