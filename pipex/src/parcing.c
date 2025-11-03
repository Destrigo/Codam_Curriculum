/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 04:33:11 by mtaranti          #+#    #+#             */
/*   Updated: 2025/11/03 05:26:00 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**parcing_path(char **envp)
{
	char **paths;

	paths = ft_split(get_path_envp(envp), ':');
	if (!paths)
		return (NULL);
	return (paths);
}

char	**parce_command(char *cmd_input)
{
	char **parced_command;

	parced_command = ft_split(cmd_input, ' ');
	return (parced_command);
}

char	*find_command(char **paths, char *cmd_input)
{
	int		i;
	char	*tmp;
	char	*full_path;
	char	**cmd;

	cmd = parce_command(cmd_input);
	full_path = NULL;
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(full_path, F_OK) == 0)
			return (free_array(cmd), free_array(paths), full_path);
		free(full_path);
		i++;
	}
	return (free_array(cmd), free_array(paths), full_path);
}
