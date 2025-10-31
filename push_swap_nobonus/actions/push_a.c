/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:42:00 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/27 21:42:33 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!*stack_b)
		return ;
	tmp_b = (*stack_b)->next;
	tmp_a = *stack_a;
	*stack_a = *stack_b;
	(*stack_a)->next = tmp_a;
	*stack_b = tmp_b;
	write(1, "pa\n", 3);
}
