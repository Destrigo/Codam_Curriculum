/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_upx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 14:21:09 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/19 17:35:08 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	counter(unsigned int c)
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

static void	ft_hexputnbr_fd(unsigned int c, int fd)
{
	if (c > 0)
	{
		ft_hexputnbr_fd(c / 16, fd);
		if (c % 16 < 10)
			ft_putchar_fd((c % 16) + '0', fd);
		else
			ft_putchar_fd((c % 16) + 'A' - 10, fd);
	}
}

int	ft_printf_upx(unsigned int c)
{
	if (c == 0)
		return (write(1, "0", 1));
	ft_hexputnbr_fd(c, 1);
	return (counter(c));
}
