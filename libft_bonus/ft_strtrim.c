/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:32:31 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 18:20:08 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(char *src, int maxind, int minind)
{
	char	*dup;
	int		i;
	int		size;

	i = 0;
	size = maxind - minind;
	dup = malloc((size + 1) * sizeof(char));
	if (dup == 0)
		return (0);
	while (i < size)
	{
		dup[i] = src[i + minind];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static int	checkset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		i;
	int		end;

	i = 0;
	while (checkset(((char *)s1)[i], set) == 1)
		i++;
	end = ft_strlen(s1);
	while (checkset(((char *)s1)[end - 1], set) == 1)
		end--;
	if (end <= i)
		return (res = ft_calloc(1, 1));
	res = ft_strndup((char *)s1, end, i);
	return (res);
}
