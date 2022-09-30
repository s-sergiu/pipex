/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:36:48 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 02:37:18 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	check_infile_error(struct files *file,
		struct paths *path, int i, char **argv)
{
	if ((file->infile < 0 && i == 2) || !path->arg)
	{
		ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
		close(file->fileds[1]);
		dup2(file->fileds[0], 0);
		exit(1);
	}
}

void	process_files(struct files *file, char **argv, int argc)
{
	char	*error;

	file->infile = open(argv[1], O_RDONLY);
	file->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (file->infile < 0)
	{
		error = strerror(errno);
		ft_printf("%s: %s: %s\n", argv[0], argv[1], error);
	}
	else
		dup2(file->infile, 0);
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

void	initialize_args(char **argv, int i, struct paths *path)
{
	path->args = ft_split(*(argv + i), ' ');
	path->arg = (*path->function_pointer)(path->split, path->args[0]);
}
