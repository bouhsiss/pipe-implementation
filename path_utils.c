#include"pipex.h"

int findp(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5)==0)
			return(i);
		i++;
	}
	return(0);
}

char *ft_paths(char **envp, int p, char *cmd)
{
	char **path;
	int i;

	i=0;
	path = ft_split(envp[p], '=');
	path = ft_split(path[1], ':');
	
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], cmd);
		if (access(path[i], F_OK)==0)
		{
			return(path[i]);
		}
		i++;
	}
	return(NULL);
}
