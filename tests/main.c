/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:08:44 by ssergiu           #+#    #+#             */
/*   Updated: 2022/09/29 02:50:26 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "../include/pipex.h"

int	ft_atoi(const char *str);

void	run_tests(int number)
{
	pid_t pid;
	int infile;

	if (number == 200)
		write(1, "works\n", 5);
	if (number == 1 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT, 0644);
			ft_printf("\033[1;32mRunning own test #1\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "wc -c", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 1 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 2 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			remove("infile");
			infile = open("infile", O_CREAT | O_TRUNC, 0644);
			remove("outfile");
			ft_printf("\033[1;32mRunning own test #2\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "cat /dev/random", "ls", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 2 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
			ft_printf("\033[1;32mRunning own test #3\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "/bin/ls", "grep pipe", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 3 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
			ft_printf("\033[1;32mRunning own test #4\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "asasd", "ls", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 4 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
			ft_printf("\033[1;32mRunning own test #5\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "grep pipe", "sadasd", "outfile" , NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 5 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
			ft_printf("\033[1;32mRunning own test #6\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "cat /dev/random", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 6 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
			ft_printf("\033[1;32mRunning own test #7\033[0m\n\n");
			execlp("./pipex", "./pipex", "badinfile", "ls", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 7 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
			remove("outfile");
			infile = open("infile", O_CREAT | O_RDWR,  0000);
			ft_printf("\033[1;32mRunning own test #8\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 8 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
			execlp("cat", "cat", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 9 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			infile = open("outfile", O_CREAT | O_RDWR,  0000);
			ft_printf("\033[1;32mRunning own test #9\033[0m\n\n");
			execlp("./pipex", "./pipex", "infile", "ls", "head -c 100", "wc -c", "outfile", NULL);
		}
	}
	waitpid(pid, 0, 0);
	if (number == 9 || number == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_printf("\033[4;35mOutputting result:\033[0m\n\n");
			ft_printf("\033[0;31m------------------\033[0m\n");
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
	}
	return (0);
}
