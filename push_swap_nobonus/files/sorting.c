/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:23:08 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/30 14:21:35 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//easy_sort
void	easy_three_sort(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
	{
		if ((*stack_a)->next->content > (*stack_a)->next->next->content)
			return (ra(&(*stack_a)), sa(&(*stack_a)));
		else
			return (ra(&(*stack_a)));
	}
	if ((*stack_a)->content > (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		return (sa(&(*stack_a)));
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content > (*stack_a)->next->next->content)
		return (rra(&(*stack_a)));
	if ((*stack_a)->content < (*stack_a)->next->content
		&& (*stack_a)->content < (*stack_a)->next->next->content)
		return (rra(&(*stack_a)), sa(&(*stack_a)));
}

void	easy_four_sort(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->content > (*stack_a)->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->next->content)
		ra(&(*stack_a));
	if (check_if_sort(*stack_a) == 0)
		return ;
	pb(&(*stack_a), &(*stack_b));
	easy_three_sort(&(*stack_a));
	pa(&(*stack_a), &(*stack_b));
}

void	easy_five_sort(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_a)->content > (*stack_a)->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->next->next->content)
	{
		if ((*stack_a)->content > (*stack_a)->next->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->next->content
		|| (*stack_a)->content > (*stack_a)->next->next->next->next->content)
			rra(stack_a);
		else
			ra(&(*stack_a));
	}
	if (check_if_sort(*stack_a) == 0)
		return ;
	pb(&(*stack_a), &(*stack_b));
	easy_four_sort(&(*stack_a), &(*stack_b));
	pa(&(*stack_a), &(*stack_b));
}

//norm_sort
int	res_bits(t_stack *stack_a)
{
	t_stack	*tmp;
	int		max;
	int		max_bits;

	tmp = stack_a;
	max = 0;
	max_bits = 0;
	while (tmp)
	{
		if (tmp->index_num > max)
			max = tmp->index_num;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	normal_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	int		j;
	int		max_bits;

	i = -1;
	max_bits = res_bits(*stack_a);
	while (++i < max_bits)
	{
		j = 0;
		size = stack_size(*stack_a);
		while (j++ < size)
		{
			if (((((*stack_a)->index_num) >> i) & 1) == 1)
				ra(&(*stack_a));
			else
				pb(&(*stack_a), &(*stack_b));
		}
		while ((*stack_b))
			pa(&(*stack_a), &(*stack_b));
	}
}
