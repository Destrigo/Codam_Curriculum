/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:51:17 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 18:21:32 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getsize(long int n)
{
	int	counter;

	counter = 0;
	if (n < 1)
	{
		counter++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char		*res;
	long int	i;
	int			size;

	i = n;
	size = getsize(n);
	res = ft_calloc(sizeof(char), (size + 1));
	if (!res)
		return (NULL);
	if (i < 0)
		i = i * -1;
	if (i == 0)
	{
		res[0] = 48;
		return (res);
	}
	while (size--)
	{
		res[size] = i % 10 + '0';
		i = i / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}
