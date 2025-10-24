/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:00:14 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 16:39:12 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (!little || *little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		k = 0;
		while ((i + k) < len && little[k] != '\0' && big[i + k] == little[k])
			k++;
		if (little[k] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
