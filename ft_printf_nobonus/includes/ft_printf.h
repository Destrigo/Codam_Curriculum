/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 11:26:07 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/15 11:26:38 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int	ft_printf(const char *strinput, ...);
int	ft_printf_upx(unsigned int c);
int	ft_printf_u(unsigned int c);
int	ft_printf_s(char *c);
int	ft_printf_p(void *p);
int	ft_printf_lowx(unsigned int c);
int	ft_printf_i(int c);
int	ft_printf_d(int c);
int	ft_printf_c(char c);

#endif