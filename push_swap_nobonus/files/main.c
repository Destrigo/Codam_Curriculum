/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:16:14 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/29 17:20:08 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sorting_algoritm(t_stack **stack_a, int args, t_stack **stack_b)
{
	if (check_if_sort(*stack_a) == 0)
		return ;
	if (args == 3)
		return (sa(&(*stack_a)));
	if (args == 4)
		return (easy_three_sort(&(*stack_a)));
	if (args == 5)
		return (easy_four_sort(&(*stack_a), &(*stack_b)));
	if (args == 6)
		return (easy_five_sort(&(*stack_a), &(*stack_b)));
	normal_sort(&(*stack_a), &(*stack_b), args);
}

int	get_indexes(t_stack *stack_a, int i, int args)
{
	int		*hash;
	t_stack	*dummy;

	i = -1;
	dummy = stack_a;
	hash = malloc(sizeof(int) * (args - 1));
	if (!hash)
		return (1);
	while (++i < (args - 1))
	{
		hash[i] = dummy->content;
		dummy = dummy->next;
	}
	sort_hash(hash, args);
	while (stack_a)
	{
		i = 0;
		while (hash[i] != stack_a->content)
			i++;
		stack_a->index_num = i;
		stack_a = stack_a->next;
	}
	return (free(hash), 0);
}

t_stack	*initialize_stack(t_stack *stack_a,
		int args, char *argv[])
{
	int		i;
	t_stack	*tmp_node;

	i = 1;
	tmp_node = NULL;
	while (i < args)
	{
		tmp_node = ft_lstnew_redacted((int)ft_atoi(argv[i]));
		if (!tmp_node)
			return (ft_lstclear_redacted(&stack_a), NULL);
		ft_lstadd_back_redacted(&stack_a, tmp_node);
		i++;
	}
	if (get_indexes(stack_a, i, args) == 1)
		return (ft_lstclear_redacted(&stack_a), NULL);
	return (stack_a);
}

int	main(int args, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (args == 1)
		return (0);
	if (args > 1024)
		return (write(2, "Error\n", 6), -1);
	stack_a = NULL;
	stack_a = initialize_stack(stack_a, args, argv);
	if (!stack_a)
		return (-1);
	stack_b = NULL;
	if (checker_input(args, argv, stack_a) == 1)
		return (write(2, "Error\n", 6),
			ft_lstclear_redacted(&stack_a), -1);
	sorting_algoritm(&stack_a, args, &stack_b);
	ft_lstclear_redacted(&stack_a);
	ft_lstclear_redacted(&stack_b);
	return (0);
}
