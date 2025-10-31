/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 17:20:03 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/27 21:38:47 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if (!*stack_a)
		return ;
	tmp_a = (*stack_a)->next;
	tmp_b = *stack_b;
	*stack_b = *stack_a;
	(*stack_b)->next = tmp_b;
	*stack_a = tmp_a;
	write(1, "pb\n", 3);
}
