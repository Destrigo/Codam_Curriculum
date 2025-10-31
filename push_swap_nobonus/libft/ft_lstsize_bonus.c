/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 11:10:09 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/17 16:38:20 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 1;
	if (!lst)
		return (0);
	while (lst->next != NULL)
	{
		counter++;
		lst = lst->next;
	}
	return (counter);
}
