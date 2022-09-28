/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:45:35 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/27 23:01:34 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct {
	int infile;
	int outfile;
	int	testfile;
	int fileds[2];
} files;

typedef struct {
	char **args;
	char **split;
	char *arg;
	char *(*functionPointer) (char **, char *);
} paths;

void		init_files(files *file);
void		initialize_pipe(int *fileds);
char		*extract_path(char **string, char *cmd);
int			find_path(char **string);
void		initialize_paths(char **envp, paths *path);
char		**ft_split(char const *s, char c);
int			ft_printf(const char *format, ...);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
