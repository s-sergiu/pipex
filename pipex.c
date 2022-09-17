/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/17 22:37:24 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

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

char	*extract_path(char **string)
{
	int index;
	char *path;
	
	index = -1;
	while(string[++index] != 0)
	{
		path = ft_strjoin(string[index], "/");
		path = ft_strjoin(path, "ls");
		if (access(path, R_OK) == 0)
			return (path);
	}

	return (NULL);
}

int main(int argc, char *argv[], char *envp[])
{
	int fileds[2];
	pid_t pid;
	pid_t pid2;
	int code;
	char **split;
	char **split_args;
	char **split_args2;
	char *test;

	split = ft_split(envp[find_path(envp)] + 5, ':');
	split_args = ft_split(*(argv), ' ');
	split_args2 = ft_split(*(argv + 3), ' ');

	if (argc == 1)
		write(1, "\n", 1);
	printf("Arg1 split: %s \n", split_args[0]);
	printf("Arg1 split: %s \n", split_args[1]);
	printf("Arg1 split: %s \n", split_args[2]);
	printf("Arg1 split: %s \n", split_args[3]);

	test = extract_path(split);
	printf("Path: %s \n", test);	

	if (pipe(fileds) == -1)
		return(0);

	pid = fork();
	if (pid == 0)
	{
		close(fileds[0]);
		dup2(fileds[1], 1);
		close(fileds[1]);
		execve("/bin/ls", split_args, NULL);
	}
	waitpid(pid, &code, 0);
	printf("ls terminated with code %d \n", code);
	pid2 = fork();
	if (pid2 == 0)
	{
		close(fileds[1]);
		dup2(fileds[0], 0);
		close(fileds[0]);
		execve("/usr/bin/grep", split_args2, NULL);
	}
	close(fileds[0]);
	close(fileds[1]);
	waitpid(pid2, &code, 0);
	printf("ls terminated with code %d \n", code);
	printf("File descriptor fileds[1] is: %d, and size %d \n", 
			fcntl(fileds[1], F_GETFD), getdtablesize());
	printf("File descriptor fileds[0] is: %d, and size %d \n",
		   	fcntl(fileds[0], F_GETFD), getdtablesize());
}
