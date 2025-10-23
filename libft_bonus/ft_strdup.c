/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 19:00:07 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 18:20:38 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(src))
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = malloc((ft_strlen((char *)src) + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, (char *)src);
	return (dup);
}
