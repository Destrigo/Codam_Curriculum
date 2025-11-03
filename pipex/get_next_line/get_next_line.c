/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:15:22 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/23 10:10:09 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	k;
	size_t	tmp;

	i = ft_strlen(s1);
	k = ft_strlen(s2);
	res = malloc(sizeof(char) * (i + k + 1));
	if (!res && s1)
		return (free(s1), NULL);
	if (!res)
		return (NULL);
	tmp = -1;
	while (++tmp < i)
		res[tmp] = s1[tmp];
	tmp = -1;
	while (++tmp < k)
		res[i + tmp] = s2[tmp];
	if (s1)
		free(s1);
	res[i + k] = '\0';
	return (res);
}

char	*helper(char *buffer, int i, int fd)
{
	char		*fix;
	int			checker;

	fix = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!fix && buffer)
		return (free(buffer), buffer = NULL, NULL);
	if (!fix)
		return (NULL);
	checker = 1;
	while (i == -1 && checker > 0)
	{
		checker = read(fd, fix, BUFFER_SIZE);
		if (checker < 0 && buffer)
			return (free(fix), free(buffer), NULL);
		if (checker < 0 && !buffer)
			return (free(fix), NULL);
		fix[checker] = '\0';
		buffer = ft_strjoin_free(buffer, fix);
		i = ft_strchrint(fix, '\n');
		if (checker == 0)
			break ;
	}
	free(fix);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*next_line;
	static char	*buffer;
	int			i;

	if (fd < 0)
		return (NULL);
	i = -1;
	buffer = helper(buffer, i, fd);
	if (buffer)
		i = ft_strchrint(buffer, '\n');
	if (!buffer || !*buffer)
		return (free(buffer), buffer = NULL, NULL);
	if (i == (-1))
		i = ft_strlen(buffer) - 1;
	next_line = ft_strndup(buffer, i + 1, 0);
	buffer = ft_strndup_free(buffer, ft_strlen(buffer), i + 1);
	if (!buffer || !*buffer)
		return (free(buffer), buffer = NULL, next_line);
	return (next_line);
}

// #include <fcntl.h>
// #include <stdio.h>
// int main(void)
// {
// 	int fd;
//  char *res;
// 	//test 1
// 	fd = open("files/empty", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/41_no_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/41_with_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/42_no_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/42_with_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/43_no_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/43_with_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/multiple_nlx5", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/multiple_line_no_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/multiple_line_with_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/alternate_line_nl_no_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/alternate_line_nl_with_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/big_line_no_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	fd = open("files/big_line_with_nl", O_RDWR);
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("%s", (res = get_next_line(fd)));
// 	printf("\n\n");
// 	close(fd);
// 	free(res);
// 	return 0;
// }