/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:49:15 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 16:38:47 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	j;
	unsigned int	i;

	j = (unsigned char)c;
	i = 0;
	while (s[i] != '\0' && s[i] != j)
		i++;
	if (s[i] == j)
		return ((char *)s + i);
	return (0);
}
