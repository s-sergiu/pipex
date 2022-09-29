#include "../include/pipex.h"

void	here_function(char *string, int fileds[])
{
	char *line;

	while(1)
	{
		line = get_next_line(0);
		dup2(fileds[1], 1);
		if (!ft_strncmp(line, string, ft_strlen(string)))
			exit(0);
		ft_putstr_fd(line,fileds[1]);
	}
}

void	init_files(files *file)
{
	file->testfile = -1;
	file->infile = -1;
	file->outfile = -1;
	file->fileds[1] = -1;
	file->fileds[0] = -1;
}

int	find_path(char **string)
{
	int index;

	index = 1;
	while (string[++index] != 0)
	{
		if (!ft_strncmp(string[index], "PATH=", 5))
			return (index);
	}
	return(0);
}

char	*extract_path(char **string, char *cmd)
{
	int index;
	char *path;
	
	index = -1;
	if (access(cmd, R_OK) == 0)
		return (cmd);
	while(string[++index] != 0)
	{
		path = ft_strjoin(string[index], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, R_OK) == 0)
			return (path);
	}

	return (NULL);
}

void	initialize_pipe(int *fileds)
{
	if (pipe(fileds) == -1)
		perror("Pipe");
}

void	initialize_paths(char **envp, paths *path)
{
	path->functionPointer = &extract_path;	
	path->split = ft_split(envp[find_path(envp)] + 5, ':');
}
