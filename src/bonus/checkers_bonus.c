/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:35:05 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/10 02:53:19 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/pipex_bonus.h"

/*
 *	If I have access to infile and cmd1 fails, print error;
 * Otherwise if I have access to outfile and cmd2 fails print error;
 */

void	check_path_and_arg(struct paths *path,
		struct counters *counter, char **argv)
{
	int	first_command;

	first_command = 2;
	if (counter->heredoc == 1)
		first_command = 3;
	if (!(access(argv[1], W_OK)))
	{
		if (!path->args && counter->i == first_command)
			ft_printf("%s: : command not found\n", argv[0]);
		else if (!path->arg && counter->i == first_command)
			ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
	}
	if (!(access(argv[counter->argc - 1], W_OK)))
	{
		if (!path->args && counter->i == counter->argc -2)
			ft_printf("%s: : command not found\n", argv[0]);
		else if (!path->arg && counter->i == counter->argc - 2)
			ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
	}
	if (counter->i > first_command && counter->i < counter->argc - 2)
	{
		if (!path->args)
			ft_printf("%s: : command not found\n", argv[0]);
		else if (!path->arg)
			ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);

	}
}

void	check_arg_count(int argc, char **argv)
	{
	if (argc == 1)
	{
		write(1, "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n"
			"Heredoc usage: ./pipex [here_doc] [LIMITER] [cmd]"
			"[cmd1] [file1]\n", 113);
		exit(1);
	}
	if (!strncmp(argv[1], "here_doc", 8) && argc < 6)
	{
		write(1, "Usage: ./pipex [here_doc] [DELIMITER] [cmd]"
			"[cmd1] [file1]\n", 59);
		exit(1);
	}
	else if (argc < 5)
	{
			write(1, "Usage: ./pipex [infile] [cmd1] [cmd2] [outfile] \n", 50);
		exit(1);
	}
}


void	check_infile_error(struct files *file,
		struct paths *path, struct counters *counter)
{
	int	first_command;

	first_command = 2;
	if (counter->heredoc == 1)
		first_command = 3;
	if ((file->infile < 0 && counter->i == first_command) || (!path->arg
			&& counter->i < counter->argc - 2))
	{
		dup2(file->fileds[0], 0);
		close_fds(file->fileds[0], file->fileds[1]);
		close_fds(file->infile, file->outfile);
		free_bundle(path);
		free_split(path->split);
		exit(1);
	}
}

void	check_pipe_exists(struct files *file)
{
	if (file->fileds[0] != -1)
	{
		dup2(file->fileds[0], 0);
		close_fds(file->fileds[0], file->fileds[1]);
	}
} 

/*
 *	If counter is at the cmd2 dups output to outfile or prints error if cannot
 * access outfile. Otherwise dups to STDOUT and execve.
 */

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
			close_fds(file->fileds[0], file->fileds[1]);
			if (path->arg && path->args)
				execve(path->arg, path->args, NULL);
		}
	}
	else
	{
		ft_printf("i is at %d with path arg %s\n", counter->i, path->arg);
		dup2(file->fileds[1], 1);
		close_fds(file->fileds[0], file->fileds[1]);
		if (path->arg && path->args)
			execve(path->arg, path->args, NULL);
	}
}
