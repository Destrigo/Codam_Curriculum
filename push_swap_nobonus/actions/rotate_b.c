/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:25:00 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/28 13:31:32 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rb(t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*head;

	tmp = NULL;
	head = NULL;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = (*stack_b)->next;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = tmp;
	tmp->next = NULL;
	*stack_b = head;
	write(1, "rb\n", 3);
}
