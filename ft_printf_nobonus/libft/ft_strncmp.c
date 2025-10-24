/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:53:29 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 16:39:09 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				counter;
	size_t			i;

	counter = 0;
	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		while (i < n)
		{
			counter = (s1[i] - s2[i]);
			if (counter != 0)
				return (counter);
			i++;
		}
		i++;
	}
	return (counter);
}
