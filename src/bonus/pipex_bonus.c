/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 14:43:59 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/pipex.h"

void	free_bundle(struct paths *path)
{
	free_split(path->args);
	if (path->arg != 0)
		free(path->arg);
}

void	close_fds(int fileds1, int fileds2)
{
	close(fileds1);
	close(fileds2);
}

void	child_loop(struct files *file, struct counters *counter,
		struct paths *path, char **argv)
{
	check_infile_error(file, path, counter, argv);
	check_if_argc_is_last(counter, file, path, argv);
}

void	init_and_process_files(struct files *file, char **argv, int argc,
		struct counters *counter)
{
	check_arg_count(argc);
	init_counters(counter, argc);
	init_files(file);
	check_for_heredoc(argv, file, counter);
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
		initialize_args(argv, counter.i, &path, argc);
		check_path_and_arg(&path, &counter, argv);
		check_pipe_exists(&file);
		init_pipe(&file);
		pid = fork();
		if (pid == 0)
			child_loop(&file, &counter, &path, argv);
		if (counter.i++ != argc - 1)
			free_bundle(&path);
	}
	close_fds(file.fileds[0], file.fileds[1]);
	while ((wait(NULL)) > 0)
		;
	free_split(path.split);
}
