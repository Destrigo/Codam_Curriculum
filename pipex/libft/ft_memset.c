/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:47:29 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 18:20:55 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*buf;

	buf = s;
	while (n > 0)
	{
		(*(unsigned char *)buf) = (unsigned char)c;
		n--;
		buf++;
	}
	return (s);
}
