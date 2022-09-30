/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:35:05 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 18:39:50 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	check_path_and_arg(struct paths *path,
		struct counters *counter, char **argv)
{
	if ((!path->arg && counter->i != 2) && counter->i < counter->argc - 2)
	{
		if (!path->arg)
			ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
		if (counter->i == counter->argc -1)
			exit(1);
	}
}

void	check_arg_count(int argc)
{
	if (argc < 5 || argc == 1 || argc > 5)
	{
		write(1, "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile] \n", 50);
		exit(1);
	}
}

void	check_infile_error(struct files *file,
		struct paths *path, struct counters *counter, char **argv)
{
	if ((file->infile < 0 && counter->i == 2) || (!path->arg
			&& counter->i < counter->argc - 1))
	{
		if (!(file->infile < 0 && counter->i == 2))
			ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
		close(file->fileds[1]);
		dup2(file->fileds[0], 0);
		exit(1);
	}
}

void	check_pipe_exists(struct files *file)
{
	if (file->fileds[0] != -1)
	{
		dup2(file->fileds[0], 0);
		close(file->fileds[0]);
		close(file->fileds[1]);
	}
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
			exit(1);
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
