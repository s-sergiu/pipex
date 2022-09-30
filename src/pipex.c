/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 02:36:53 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	init_and_process_files(struct files *file, char **argv, int argc,
		struct counters *counter)
{
	check_arg_count(argc);
	init_counters(counter, argc);
	init_files(file);
	process_files(file, argv, argc);
}

int	main(int argc, char *argv[], char *envp[])
{
	struct counters	counter;
	struct files	file;
	struct paths	path;	
	pid_t			pid;

	init_and_process_files(&file, argv, argc, &counter);
	initialize_paths(envp, &path);
	while (counter.i < argc)
	{
		initialize_args(argv, counter.i, &path);
		check_pipe_exists(&file);
		init_pipe(&file);
		check_path_and_arg(&path, &counter, argv);
		pid = fork();
		if (pid == 0)
		{
			check_infile_error(&file, &path, counter.i, argv);
			check_if_argc_is_last(&counter, &file, &path, argv);
		}
		counter.i++;
	}
	close(file.fileds[0]);
	close(file.fileds[1]);
	while ((wait(NULL)) > 0)
		;
}
