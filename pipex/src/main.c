/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 00:44:44 by mtaranti          #+#    #+#             */
/*   Updated: 2025/11/03 05:11:43 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    pipex(int f1, int f2, char **argv, char **envp)
{
    int   pp[2];
    int   status;
    pid_t child1;
    pid_t child2;    
	
    if (pipe(pp) == -1)
	    return (-1);
    child1 = fork();
    if (child1 < 0)
        return (perror("Fork: "));
    if (child1 == 0)
        child_one(f1, pp, argv, envp);
    child2 = fork();
    if (child2 < 0)
        return (perror("Fork: "));
    if (child2 == 0)
        child_two(f2, pp, argv, envp);
    close(pp[0]);
    close(pp[1]);
    waitpid(child1, &status, 0);
    waitpid(child2, &status, 0);
}

int  main(int args, char **argv, char **envp)
{
    int		fd1;
    int		fd2;

    if (args != 5)
		return (-1);
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd1 < 0 || fd2 < 0)
        return (-1);
	
    pipex(fd1, fd2, argv, envp);
    return (0);
}