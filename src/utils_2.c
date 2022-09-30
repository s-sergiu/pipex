/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:35:05 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 02:46:24 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	init_pipe(struct files *file)
{
	if (pipe(file->fileds) == -1)
		perror("Pipe");
}

void	check_path_and_arg(struct paths *path,
		struct counters *counter, char **argv)
{
	if ((!path->arg && counter->i != 2) && counter->i < counter->argc - 1)
	{
		if (!path->arg)
			ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
	}
}

void	check_arg_count(int argc)
{
	if (argc < 5 || argc == 1)
	{
		write(1, "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile] \n", 50);
		exit(1);
	}
}

void	init_counters(struct counters *counter, int argc)
{
	counter->i = 2;
	counter->argc = argc;
}

void	check_if_argc_is_last(struct counters *counter,
		struct files *file, struct paths *path, char **argv)
{
	char	*error;

	if (counter->i == counter->argc - 2)
	{
		if (access(argv[counter->argc - 1], W_OK))
		{
			error = strerror(errno);
			ft_printf("%s: %s: %s\n", argv[0], argv[counter->argc - 1], error);
		}
		else
		{
			dup2(file->outfile, 1);
			close(file->fileds[1]);
			close(file->fileds[0]);
			execve(path->arg, path->args, NULL);
		}
	}
	else
	{
		dup2(file->fileds[1], 1);
		close(file->fileds[0]);
		execve(path->arg, path->args, NULL);
	}
}
