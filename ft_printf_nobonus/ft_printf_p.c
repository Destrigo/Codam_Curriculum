/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:46:03 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/18 14:41:56 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	counter(size_t c)
{
	int	res;

	res = 0;
	if (c == 0)
		return (1);
	while (c > 0)
	{
		res++;
		c = c / 16;
	}
	return (res);
}

static void	ft_hexputnbr_fd(size_t c, int fd)
{
	if (c > 0)
	{
		ft_hexputnbr_fd(c / 16, fd);
		if (c % 16 < 10)
			ft_putchar_fd((c % 16) + '0', fd);
		else
			ft_putchar_fd((c % 16) + 'a' - 10, fd);
	}
}

int	ft_printf_p(void *p)
{
	size_t	address;

	address = (size_t)p;
	if (!address)
		return (write(1, "(nil)", 5));
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	ft_hexputnbr_fd(address, 1);
	return (2 + counter(address));
}
