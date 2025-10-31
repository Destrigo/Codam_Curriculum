/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:24:56 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/27 21:31:57 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*head;

	tmp = NULL;
	head = NULL;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = (*stack_a)->next;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp->next = NULL;
	*stack_a = head;
	write(1, "ra\n", 3);
}
