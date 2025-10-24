/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:05:40 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/21 11:22:29 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	ft_newputnbr_fd(unsigned int n, int fd)
{
	if (n > 0)
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

static int	counter(unsigned int c)
{
	int	res;

	res = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		res++;
		c = c / 10;
	}
	return (res);
}

int	ft_printf_u(unsigned int c)
{
	if (c == 0)
		return (write(1, "0", 1));
	ft_newputnbr_fd(c, 1);
	return (counter(c));
}
