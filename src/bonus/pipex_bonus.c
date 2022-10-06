/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:03:37 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/06 19:13:39 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/pipex_bonus.h"

void	free_bundle(struct paths *path)
{
	if (path->args)
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
	if (path->arg[0] == 0)
		ft_printf("%s: : command not found\n", argv[0]);
	if (!(counter->heredoc == 1))
		check_infile_error(file, path, counter, argv);
	check_if_argc_is_last(counter, file, path, argv);
}

void	init_and_process_files(struct files *file, char **argv, int argc,
		struct counters *counter)
{
	check_arg_count(argc, argv);
	init_counters(counter, argc);
	init_files(file);
	check_for_heredoc(argv, file, counter);
	if (counter->heredoc == 1)
		file->outfile = open(argv[argc - 1],
				O_WRONLY | O_APPEND | O_CREAT, 0644);
	else
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
	while (counter.i < argc - 1)
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
	while ((waitpid(pid, 0, 0)) > 0)
		;
	close_fds(file.fileds[0], file.fileds[1]);
	close_fds(file.infile, file.outfile);
	free_split(path.split);
	while(1);
}
