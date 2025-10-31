/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:39:27 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/28 13:32:08 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp_head;

	tmp = NULL;
	tmp_head = NULL;
	if (!*stack_b)
		return ;
	tmp_head = *stack_b;
	while (((*stack_b)->next)->next != NULL)
		*stack_b = (*stack_b)->next;
	tmp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	tmp->next = tmp_head;
	*stack_b = tmp;
	write(1, "rrb\n", 4);
}
