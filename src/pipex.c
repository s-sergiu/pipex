/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/11 16:36:21 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	free_bundle(struct paths *path)
{
	if (path->args)
		free_split(path->args);
	if (path->arg)
		free(path->arg);
}

void	close_fds(int fileds1, int fileds2)
{
	if (fileds1 != -1)
		close(fileds1);
	if (fileds2 != -1)
		close(fileds2);
}

void	child_loop(struct files *file, struct counters *counter,
		struct paths *path, char **argv)
{
	check_infile_error(file, path, counter);
	check_if_argc_is_last(counter, file, path, argv);
}

void	init_and_process_files(struct files *file, char **argv, int argc,
		struct counters *counter)
{
	check_arg_count(argc);
	init_counters(counter, argc);
	init_files(file);
	process_files(file, argv);
}

int	main(int argc, char *argv[], char *envp[])
{
	struct counters	counter;
	struct files	file;
	struct paths	path;	
	pid_t			pid;

	counter.envp = envp;
	init_and_process_files(&file, argv, argc, &counter);
	initialize_paths(envp, &path);
	while (counter.i < argc - 1)
	{
		initialize_args(argv, &counter, &path);
		check_path_and_arg(&path, &counter, argv);
		check_pipe_exists(&file);
		init_pipe(&file);
		pid = fork();
		if (pid == 0)
			child_loop(&file, &counter, &path, argv);
		if (counter.i++ != argc - 1)
			free_bundle(&path);
	}
	while ((waitpid(pid, 0, 0)) > 0)
		;
	close_fds(file.fileds[0], file.fileds[1]);
	close_fds(file.infile, file.outfile);
	free_split(path.split);
}
