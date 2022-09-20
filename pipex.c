/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/20 04:43:41 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_printf.h"

#define FLAG 0xaa

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
	while(string[++index] != 0)
	{
		path = ft_strjoin(string[index], "/");
		path = ft_strjoin(path, cmd);
		if (access(path, R_OK) == 0)
			return (path);
	}

	return (NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	int fileds[2];
	int i;
	pid_t pid;
	char **split;
	int infile;
	char *buffer;
	char *path;
	char **path_list;

	

	buffer = malloc(5);
	infile = open(argv[1], O_RDONLY);
	dup2(infile, 0);

	if (argc == 1)
		write(1, "\n", 1);

	path_list = ft_split(envp[find_path(envp)] + 5, ':');

	i = 0;	
	printf("%s\n", argv[1]);
	while (i < argc - 2)
	{
		split = ft_split(argv[i + 2], ' ');
		path = extract_path(path_list, split[0]);

		printf("in --File descriptor fileds[0] is: %d.\n", fcntl(fileds[0], F_GETFD));
		printf("%d", i);
		printf("in --File descriptor fileds[1] is: %d.\n", fcntl(fileds[1], F_GETFD));
		if (fileds[0])
		{
			dup2(fileds[0], 0);
			close(fileds[0]);
			close(fileds[1]);
			write(1, "test", 4);
		}
		if (pipe(fileds) == -1)
			return (0);
		pid = fork();
		if (pid == 0)
		{
			close(fileds[0]);
			dup2(fileds[1], 1);
			close(fileds[1]);
			execve(path, split, NULL);
		}
		waitpid(pid, 0, 0);
		i++;
	}
	close(fileds[1]);
	read(fileds[0], buffer, 10000);
	close(fileds[0]);
	printf("out --File descriptor fileds[0] is: %d.\n", fcntl(fileds[0], F_GETFD));
	printf("out --File descriptor fileds[1] is: %d.\n", fcntl(fileds[1], F_GETFD));
	printf("buffer: %s\n", buffer);
}
