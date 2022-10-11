/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:24:41 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/11 19:03:52 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pipex.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	free_all(struct paths *path)
{
	if (path->arg)
		free(path->arg);
	if (path->args)
		free_split(path->args);
}

void	close_and_free(struct files *file, struct paths *path)
{
	close_fds(file->fileds[0], file->fileds[1]);
	close_fds(file->infile, file->outfile);
	free_split(path->split);
}
