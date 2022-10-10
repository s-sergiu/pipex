/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 20:45:35 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/10 02:41:52 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_SIZE 1

# include <sys/errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>

typedef struct counters{
	int	i;
	int	argc;
	int	heredoc;
}	t_counters;

typedef struct files{
	int	infile;
	int	outfile;
	int	testfile;
	int	fileds[2];
	int status;
}	t_files;

typedef struct paths{
	char	**args;
	char	**split;
	char	*arg;
	char	*(*function_pointer)(char **, char *);
}	t_paths;

void		free_split(char **split);
void		free_all(struct paths *path);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *str);
int			has_newline(char *buffer);
int			get_newline_pos(char *buffer);
char		*ft_strdup(const char *s1);
char		*pipex_ft_strjoin(char const *s1, char const *s2, int flag);
char		*gnl_ft_strjoin(char const *s1, char const *s2, int flag);
char		*get_next_line(int fd);
void		here_function(char *string, int fileds[]);
void		init_files(struct files *file);
void		process_files(struct files *file, struct counters *counter,
				char **argv, int argc);
char		*extract_path(char **string, char *cmd);
int			find_path(char **string);
void		initialize_paths(char **envp, struct paths *path);
char		**ft_split(char const *s, char c);
int			ft_printf(const char *format, ...);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);
void		check_arg_count(int argc, char **argv);
void		init_counters(struct counters *counter, int argc);
void		initialize_args(char **argv, int counter,
				struct paths *path, int argc);
void		check_pipe_exists(struct files *file);
void		init_pipe(struct files *file);
void		check_path_and_arg(struct paths *path,
				struct counters *counter, char **argv);
void		check_if_argc_is_last(struct counters *counter,
				struct files *file, struct paths *path, char **argv);
void		check_infile_error(struct files *file,
				struct paths *path, struct counters *counter);
void		child_loop(struct files *file, struct counters *counter,
				struct paths *path, char **argv);
void		close_fds(int fileds1, int fileds2);
void		free_bundle(struct paths *path);
void		init_and_process_files(struct files *file, char **argv, int argc,
				struct counters *counter);
void		here_function(char *string, int fileds[]);
void		check_for_heredoc(char **argv, struct files *file,
				struct counters *counter);

#endif
