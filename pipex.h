#include <sys/errno.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_printf.h"

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
