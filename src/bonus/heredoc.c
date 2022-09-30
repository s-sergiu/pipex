/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:15:54 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/30 16:50:46 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/pipex.h"

void	check_for_heredoc(char **argv, struct files *file,
			struct counters *counter)
{
	pid_t	pid;

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		init_pipe(file);
		counter->heredoc = 1;
		pid = fork();
		if (pid == 0)
			here_function(argv[2], file->fileds);
		waitpid(pid, 0, 0);
		counter->i = 3;
	}
}

void	here_function(char *string, int fileds[])
{
	char	*line;
	int		len;

	len = ft_strlen(string);
	while (1)
	{
		line = get_next_line(0);
		dup2(fileds[1], 1);
		if (!ft_strncmp(line, string, len) && line[len + 1] == 0)
			exit(0);
		ft_putstr_fd(line, fileds[1]);
	}
}
