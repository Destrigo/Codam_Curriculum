/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 10:56:51 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/23 12:01:01 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int	redirector(char strinput, va_list listptr)
{
	if (strinput == 'c')
		return (ft_printf_c(va_arg(listptr, int)));
	else if (strinput == 's')
		return (ft_printf_s(va_arg(listptr, char *)));
	else if (strinput == 'p')
		return (ft_printf_p(va_arg(listptr, void *)));
	else if (strinput == 'd')
		return (ft_printf_d(va_arg(listptr, int)));
	else if (strinput == 'i')
		return (ft_printf_i(va_arg(listptr, int)));
	else if (strinput == 'u')
		return (ft_printf_u(va_arg(listptr, unsigned int)));
	else if (strinput == 'x')
		return (ft_printf_lowx(va_arg(listptr, unsigned int)));
	else if (strinput == 'X')
		return (ft_printf_upx(va_arg(listptr, unsigned int)));
	else if (strinput == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *strinput, ...)
{
	int		counter;
	va_list	listptr;

	counter = 0;
	if (!strinput)
		return (-1);
	va_start(listptr, strinput);
	while (*strinput)
	{
		if (*strinput == '%')
		{
			strinput++;
			counter = counter + redirector(*strinput, listptr);
		}
		else
		{
			ft_putchar_fd(*strinput, 1);
			counter++;
		}
		strinput++;
	}
	va_end(listptr);
	return (counter);
}
