/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:18:34 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/20 17:41:37 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}

int	ft_strchrint(const char *s, int c)
{
	unsigned char	j;
	unsigned int	i;

	j = (unsigned char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != j)
		i++;
	if (s[i] == j)
		return (i);
	return (-1);
}

char	*ft_strndup(char *src, int maxind, int minind)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = maxind - minind;
	if (size == 0)
	{
		dup = malloc(1);
		if (!dup)
			return (NULL);
		dup[0] = '\0';
		return (dup);
	}
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (i < size)
	{
		dup[i] = src[i + minind];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strndup_free(char *src, int maxind, int minind)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = maxind - minind;
	if (size == 0)
	{
		free(src);
		return (NULL);
	}
	dup = malloc((size + 1) * sizeof(char));
	if (!dup)
		return (free(src), NULL);
	while (i < size)
	{
		dup[i] = src[i + minind];
		i++;
	}
	if (src)
		free(src);
	dup[i] = '\0';
	return (dup);
}
