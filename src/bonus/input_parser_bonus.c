/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 02:36:48 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/10 02:46:35 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/pipex_bonus.h"

void	process_files(struct files *file, struct counters *counter,
			char **argv, int argc)
{
	char	*error;

	if (counter->heredoc == 1)
	{
		file->outfile = open(argv[argc - 1],
				O_WRONLY | O_APPEND | O_CREAT, 0644);
	}
	else
	{
		file->infile = open(argv[1], O_RDONLY);
		file->outfile = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (file->infile < 0)
		{
			error = strerror(errno);
			ft_printf("%s: %s: %s\n", argv[0], argv[1], error);
		}
		else
		{
			dup2(file->infile, 0);
			close(file->infile);
		}
	}
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

	index = -1;
	if (cmd[0] == '/')
	{
		if (access(cmd, R_OK) == 0)
		{
			path = pipex_ft_strjoin(cmd, "", 0);
			return (path);
		}
		else
			return (NULL);
	}
	while (string[++index] != 0)
	{
		path = pipex_ft_strjoin(string[index], "/", 0);
		path = pipex_ft_strjoin(path, cmd, 1);
		if (access(path, R_OK) == 0)
			return (path);
		free(path);
	}
	return (NULL);
}

char	*pipex_ft_strjoin(char const *s1, char const *s2, int flag)
{
	char	*str;
	int		i;
	size_t	s1_length;
	size_t	s2_length;

	if (!s1 || !s2)
		return (NULL);
	s1_length = ft_strlen(s1);
	s2_length = ft_strlen(s2);
	i = -1;
	str = malloc(s1_length + s2_length + 1);
	if (!str)
		return (NULL);
	while (++i < (int)s1_length)
		str[i] = s1[i];
	i = -1;
	while (++i < (int)s2_length)
		str[i + s1_length] = s2[i];
	str[i + s1_length] = 0;
	if (flag == 1)
		free((char *)s1);
	return (str);
}
