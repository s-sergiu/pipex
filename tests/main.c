/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:08:44 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/28 04:16:41 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../include/pipex.h"

int	ft_atoi(const char *str);

void	run_tests(int number)
{
	pid_t pid;
	int infile;

	if (number == 1)
		write(1, "works\n", 5);
	if (number == 2 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #2\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "wc -c", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 2 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 3 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #3\n\n");
			execlp("./pipex", "./pipex", "infile", "cat", "/dev/random", "ls", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 3 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 4 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #4\n\n");
			execlp("./pipex", "./pipex", "infile", "/bin/ls", "ls", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 4 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 5 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #5\n\n");
			execlp("./pipex", "./pipex", "infile", "asasd", "ls", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 5 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 6 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #6\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "grep pipe", "sadasd", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 6 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 7 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #7\n\n");
			execlp("./pipex", "./pipex", "infile", "cat /dev/random", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 7 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 8 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			remove("outfile");
			ft_printf("Running test #8\n\n");
			execlp("./pipex", "./pipex", "badinfile", "ls", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 8 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 9 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			remove("outfile");
			infile = open("infile", O_CREAT | O_RDWR,  0000);
			ft_printf("Running test #9\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 9 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 10 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			remove("outfile");
			infile = open("outfile", O_CREAT | O_RDWR,  0000);
			ft_printf("Running test #9\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 10 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("Outputting result: \n\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
}

int	main (int argc, char *argv[])
{
	int number;

	if (argc != 2)
		write(1, "\n", 1);
	else
	{
		number = ft_atoi(argv[1]);
		run_tests(number);	
		write(1, "\n", 1);
		remove("infile");
		remove("outfile");
	}
	return (0);
}
