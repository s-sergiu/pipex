/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/18 20:57:50 by ssergiu          ###   ########.fr       */
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
	pid_t pid;
	pid_t pid2;
	int code;
	char **split;
	char **split_args;
	char **split_args2;
	char *test;
	char *test2;
	char *infile;

	infile = argv[1];
	ft_printf("%s \n", infile);
	if (open(infile, O_RDONLY) == -1)
	{
		ft_printf("closed \n");
		perror("Error");
		ft_printf("\n");
		exit(1);
	}

	split = ft_split(envp[find_path(envp)] + 5, ':');
	split_args = ft_split(*(argv + 2), ' ');
	split_args2 = ft_split(*(argv + 3), ' ');
	test = extract_path(split,split_args[0]);
	test2 = extract_path(split,split_args2[0]);

	ft_printf("Flag is: %d \n", FLAG);

	if (argc == 1)
		write(1, "\n", 1);

	ft_printf("Arg1 split: %s \n", split_args[0]);
	ft_printf("Arg1 split: %s \n", split_args[1]);
	ft_printf("Path: -%s-\n", test);	
	while (i < argc)

	if (pipe(fileds) == -1)
		return(0);

	pid = fork();
	if (pid == 0)
	{
		close(fileds[0]);
		dup2(fileds[1], 1);
		close(fileds[1]);
		execve(test, split_args, NULL);
	}
	waitpid(pid, &code, 0);
	ft_printf("ls terminated with code %d; \n", code);
	
	ft_printf("Arg2 split: %s \n", split_args2[0]);
	ft_printf("Arg2 split: %s \n", split_args2[1]);
	ft_printf("Path: -%s-\n", test2);	

	pid2 = fork();
	if (pid2 == 0)
	{
		close(fileds[1]);
		dup2(fileds[0], 0);
		close(fileds[0]);
		execve(test2, split_args2, NULL);
	}
	close(fileds[0]);
	close(fileds[1]);
	waitpid(pid2, &code, 0);
	ft_printf("ls terminated with code %d; \n", code);
	ft_printf("File descriptor fileds[1] is: %d, and size %d \n", 
			fcntl(fileds[1], F_GETFD), getdtablesize());
	ft_printf("File descriptor fileds[0] is: %d, and size %d \n",
		   	fcntl(fileds[0], F_GETFD), getdtablesize());
}
