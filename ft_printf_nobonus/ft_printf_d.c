/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:01:15 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/21 11:17:38 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	counter(int c)
{
	int	res;

	res = 0;
	if (c == 0)
		return (1);
	if (c == -2147483648)
		return (11);
	if (c < 0)
	{
		c = c * (-1);
		res++;
	}
	while (c > 0)
	{
		res++;
		c = c / 10;
	}
	return (res);
}

int	ft_printf_d(int c)
{
	if (c == -2147483648)
		return (write(1, "-2147483648", 11));
	ft_putnbr_fd(c, 1);
	return (counter(c));
}
