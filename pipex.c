#include"pipex.h"

// < infile  cmd1 | cmd2 outfile
// ./pipex infile cmd1 cmd2 outfile

void child(char **av, char **envp, int *end)
{
	int fd1;
	char *path;
	char **cmd;
	int j;

	cmd = ft_split(av[2], ' ');
	path = ft_paths(envp, findp(envp), cmd[0]);
	fd1 = open(av[1], O_RDONLY);
	dup2(fd1, 0);
    close(fd1);
    dup2(end[1], 1);
	close(end[0]);
	j = execve(path, cmd, envp);
	if(j == -1)
		perror("execve :");
}

void parent(char **av, char **envp, int *end)
{
	int fd2;
	char *path;
	int i;
	char **cmd;

	wait(0);
	cmd = ft_split(av[3], ' ');
	path = ft_paths(envp, findp(envp), cmd[0]);
	fd2 = open(av[4], O_RDWR);
	dup2(fd2, 1);
	close(fd2);
    dup2(end[0], 0);
    close(end[1]);
	i = execve(path, cmd, envp);
	if (i == -1)
		perror("execve :");

}

int main(int ac, char **av, char **envp)
{
	int end[2];
	int id;

	if (pipe(end) == -1)
	{
		perror("Pipe :");
		exit(1);
	}
    id = fork();
	if (id < 0)
	{
		perror("Fork :");
	}
	else if (id == 0)
		child(av, envp, end);
	else
		parent(av, envp, end);
}