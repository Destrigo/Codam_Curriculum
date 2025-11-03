/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:08:01 by mtaranti          #+#    #+#             */
/*   Updated: 2025/11/03 05:20:21 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <sys/wait.h>

void	child_one(int f1, int *pp, char** cmd1, char **envp);
void	child_two(int f2, int *pp, char** cmd2, char **envp);
char	*get_path_envp(char **envp);
void	free_array(char **array);
void    pipex(int f1, int f2, char **argv, char **envp);
int		main(int args, char **argv, char **envp);
char	**parcing_path(char **envp);
char	**parce_command(char *cmd_input);
char	*find_command(char **paths, char *cmd_input);

#endif