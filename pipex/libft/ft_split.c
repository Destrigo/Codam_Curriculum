/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:50:08 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/20 13:56:47 by mtaranti         ###   ########.fr       */
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

static void	ft_putdexes(char *str, char c, char **array, int z)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		start = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		array[z] = ft_strndup(str, i, start);
		z++;
		while (str[i] == c && str[i] != '\0')
			i++;
	}
}

static int	numstr(char *str, char c)
{
	int	counter;

	counter = 0;
	while (*str == c)
		str++;
	while (*str != '\0')
	{
		if (*str == c)
			counter++;
		while (*str == c)
			str++;
		str++;
	}
	return (counter);
}

static void	checkiffailed(int size, char **array)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (i < size)
	{
		if (array[i] == NULL)
			counter++;
		i++;
	}
	if (counter != 0)
	{
		while (size >= 0)
		{
			free(array[size]);
			size--;
		}
		free(array);
	}
}

char	**ft_split(const char *str, char c)
{
	char	**array;
	char	*str2;
	int		size;

	str2 = (char *)str;
	size = numstr(str2, c);
	array = malloc(sizeof(char *) * (1 + size));
	if (!array)
		return (NULL);
	if (size == 0)
	{
		array[0] = NULL;
		return (array);
	}
	ft_putdexes(str2, c, array, 0);
	array[size] = NULL;
	checkiffailed(size, array);
	return (array);
}
