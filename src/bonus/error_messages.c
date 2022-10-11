/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssergiu <ssergiu@student.42heilbronn.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:22:47 by ssergiu           #+#    #+#             */
/*   Updated: 2022/10/11 15:42:40 by ssergiu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	first_error(struct paths *path, struct counters *counter,
			char **argv, int first_command)
{
	if (!path->args && counter->i == first_command)
		ft_printf("%s: : command not found\n", argv[0]);
	else if (!path->arg && counter->i == first_command)
		ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
}

void	last_error(struct paths *path, struct counters *counter,
			char **argv)
{
	if (!path->args && counter->i == counter->argc -2)
		ft_printf("%s: : command not found\n", argv[0]);
	else if (!path->arg && counter->i == counter->argc - 2)
		ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
}

void	middle_error(struct paths *path, char **argv)
{
	if (!path->args)
		ft_printf("%s: : command not found\n", argv[0]);
	else if (!path->arg)
		ft_printf("%s: %s: command not found\n", argv[0], path->args[0]);
}
