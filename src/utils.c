/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:23:34 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 02:04:22 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	init_files(struct files *file)
{
	file->testfile = -1;
	file->infile = -1;
	file->outfile = -1;
	file->fileds[1] = -1;
	file->fileds[0] = -1;
}

int	find_path(char **string)
{
	int	index;

	index = 1;
	while (string[++index] != 0)
	{
		if (!ft_strncmp(string[index], "PATH=", 5))
			return (index);
	}
	return (0);
}

char	*extract_path(char **string, char *cmd)
{
	int		index;
	char	*path;
	char	*temp;

	index = -1;
	if (access(cmd, R_OK) == 0)
		return (cmd);
	while (string[++index] != 0)
	{
		path = ft_strjoin(string[index], "/");
		temp = path;
		path = ft_strjoin(path, cmd);
		free(temp);
		if (access(path, R_OK) == 0)
			return (path);
	}
	free(path);
	return (NULL);
}

void	initialize_paths(char **envp, struct paths *path)
{
	path->function_pointer = &extract_path;
	path->split = ft_split(envp[find_path(envp)] + 5, ':');
}
