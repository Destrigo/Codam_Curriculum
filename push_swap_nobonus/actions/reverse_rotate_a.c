/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:22:02 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/29 16:48:24 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp_head;

	tmp = NULL;
	tmp_head = NULL;
	if (!*stack_a && !(*stack_a)->next)
		return ;
	tmp_head = *stack_a;
	while (((*stack_a)->next)->next != NULL)
		*stack_a = (*stack_a)->next;
	tmp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	tmp->next = tmp_head;
	*stack_a = tmp;
	write(1, "rra\n", 4);
}
