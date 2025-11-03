/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 04:03:22 by mtaranti          #+#    #+#             */
/*   Updated: 2025/11/03 05:17:41 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void child_one(int f1, int *pp, char** cmd1, char **envp)
{
	char *path;
	char **parced_cmd;
	char **paths;

	paths = parching_paths(envp);
	parced_cmd = parce_command(cmd1[3]);
	path = find_command(paths, cmd1[3]);
	dup2(f1, STDIN_FILENO);
	dup2(pp[1], STDOUT_FILENO);
	close(pp[0]);
    close(pp[1]);
    close(f1);
	if (execve(path, cmd1, envp) == -1)
	{
		free_array(paths);
		free(path);
		free_array(parced_cmd);
		return ;
	}
	free_array(paths);
	free(path);
	free_array(parced_cmd);
}

void child_two(int f2, int *pp, char** cmd2, char **envp)
{
	char *path;
	char **parced_cmd;
	char **paths;

	paths = parching_paths(envp);
	parced_cmd = parce_command(cmd2[4]);
	path = find_command(paths, cmd2[4]);
	dup2(pp[1], STDIN_FILENO);
	dup2(f2, STDOUT_FILENO);
	close(pp[1]);
    close(pp[0]);
    close(f2);
	if (execve(path, cmd2, envp) == -1)
	{
		free_array(paths);
		free(path);
		free_array(parced_cmd);
		return ;
	}
	free_array(paths);
	free(path);
	free_array(parced_cmd);
}
