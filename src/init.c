/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:23:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/08 22:03:26 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	init_counters(struct counters *counter, int argc)
{
	counter->i = 2;
	counter->argc = argc;
}

void	init_files(struct files *file)
{
	file->testfile = -1;
	file->infile = -1;
	file->outfile = -1;
	file->fileds[1] = -1;
	file->fileds[0] = -1;
}

void	initialize_paths(char **envp, struct paths *path)
{
	path->function_pointer = &extract_path;
	path->split = ft_split(envp[find_path(envp)] + 5, ':');
}

void	initialize_args(char **argv, struct counters *counter,
	   	struct paths *path)
{
	if (argv[counter->i][0] == 0)
	{
		path->args = 0;
		path->arg = 0;
	}
	else
	{
		if (counter->i != counter->argc - 1)
		{
			path->args = ft_split(*(argv + counter->i), ' ');
			path->arg = (*path->function_pointer)(path->split, path->args[0]);
		}
	}
}

void	init_pipe(struct files *file)
{
	if (pipe(file->fileds) == -1)
		perror("Pipe");
}
