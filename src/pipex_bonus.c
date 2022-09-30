/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 00:30:04 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int		i;
	files	file;
	paths	path;	
	pid_t	pid;
	char	*error;

	if (argc < 5 || argc == 1)
	{
		write(1, "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile] \n", 50);
		exit(1);
	}
	i = 2;
	init_files(&file);
	file.testfile = open("test", O_RDONLY);
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		initialize_pipe(file.fileds);
		pid = fork();
		if (pid == 0)
			here_function(argv[2], file.fileds);
		waitpid(pid, 0, 0);
		i = 3;
	}
	else
	{
		file.infile = open(argv[1], O_RDONLY);
		if (file.infile < 0)
		{
			error = strerror(errno);
			ft_printf("%s: %s: %s\n", argv[0], argv[1], error);
		}
		else
			dup2(file.infile, 0);
	}
	file.outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	initialize_paths(envp, &path);
	while (i < argc)
	{
		path.args = ft_split(*(argv + i), ' ');
		path.arg = (*path.functionPointer)(path.split, path.args[0]);
		if (file.fileds[0] != -1)
		{
			dup2(file.fileds[0], 0);
			close(file.fileds[0]);
			close(file.fileds[1]);
		}
		initialize_pipe(file.fileds);
		if ((!path.arg && i != 2) && i < argc - 1)
		{
			if (!path.arg)
				ft_printf("%s: %s: command not found\n", argv[0], path.args[0]);
		}
		else
			pid = fork();
		if (pid == 0)
		{
			printf("-----------------------------\n");
			printf("Argc is: %d.\n", argc);
			printf("i is: %d.\n", i);
			printf("Argc - 1 is: %d.\n", argc - 1);
			printf("arg is: %s.\n", path.args[0]);
			if ((file.infile < 0 && i == 2) || !path.arg)
			{
				if (!path.arg && i < argc -2)
					ft_printf("%s: %s: command not found\n",
						argv[0], path.args[0]);
				close(file.fileds[1]);
				dup2(file.fileds[0], 0);
				exit(1);
			}
			else if (i == argc - 2)
			{
				if (access(argv[argc - 1], W_OK))
				{
					error = strerror(errno);
					ft_printf("%s: %s: %s\n", argv[0], argv[argc - 1], error);
				}
				else
				{
					dup2(file.outfile, 1);
					close(file.fileds[1]);
					close(file.fileds[0]);
					execve(path.arg, path.args, NULL);
				}
			}
			else
			{
				dup2(file.fileds[1], 1);
				close(file.fileds[0]);
				execve(path.arg, path.args, NULL);
			}
		}
		i++;
	}
	close(file.fileds[0]);
	close(file.fileds[1]);
	pid = wait(NULL);
	while ((pid) > 0)
		;
}
