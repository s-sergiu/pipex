/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/25 01:46:57 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char *argv[], char *envp[])
{
	int i;
	files file;
	paths path;	
	pid_t pid;
	
	if (argc < 5)
		write(1, "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile] \n", 50);

	i = 2;
	init_files(&file);
	file.infile = open(argv[1], O_RDONLY);
	file.outfile = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (file.infile < 0)
		perror(argv[0]);
	else 
		dup2(file.infile, 0);

	initialize_paths(envp, &path);

	while (i < argc)
	{
		path.args = ft_split(*(argv + i), ' ');
		path.arg =(*path.functionPointer)(path.split, path.args[0]);
		if (file.fileds[0] != -1)
		{
			printf("oins: %d\n", i);
			dup2(file.fileds[0], 0);
			close(file.fileds[0]);
			close(file.fileds[1]);
		}
		initialize_pipe(file.fileds);
		pid = fork();
		if (pid == 0) 
		{
			close(file.fileds[0]);
//			printf("----------------------------\n");
//			printf("Argc is: %d.\n", argc);
//			printf("i is: %d.\n", i);
//			printf("Argc - 1 is: %d.\n", argc - 1);
//			printf("arg is: %s.\n", path.args[0]);
			if (i == argc - 2)
			{
				close(file.fileds[0]);
				dup2(file.outfile, 1);
			}
			else
				dup2(file.fileds[1], 1);
			close(file.fileds[1]);
			execve(path.arg, path.args, NULL);
		}
		i++;
	}
	close(file.fileds[0]);
	close(file.fileds[1]);
	while(wait(NULL) < 0)
		;
//	printf("infile is: %d\n", file.infile);
//	printf("outfile is: %d\n", file.outfile);
//	printf("fileds[0] is: %d\n", file.fileds[0]);
//	printf("fileds[1] is: %d\n", file.fileds[1]);
}
