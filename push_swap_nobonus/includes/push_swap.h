/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marco <marco@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:08:01 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/29 17:12:07 by marco            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

int		check_if_sort(t_stack *stack_a);
int		is_int(char *str);
int		checker_input(int args, char *argv[], t_stack *stack_a);
void	sort_hash(int *hash, int args);
void	sorting_algoritm(t_stack **stack_a, int args, t_stack **stack_b);
int		get_indexes(t_stack *stack_a, int i, int args);
t_stack	*initialize_stack(t_stack *stack_a,
			int args, char *argv[]);
int		main(int args, char *argv[]);
void	easy_three_sort(t_stack **stack_a);
void	easy_four_sort(t_stack **stack_a, t_stack **stack_b);
void	easy_five_sort(t_stack **stack_a, t_stack **stack_b);
int		res_bits(t_stack *stack_a);
void	normal_sort(t_stack **stack_a, t_stack **stack_b, int size);
int		stack_size(t_stack *stack);
void	sb(t_stack **stack_b);
void	sa(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rra(t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	ft_lstclear_redacted(t_stack **lst);
void	ft_lstdelone_redacted(t_stack *lst);
void	ft_lstadd_back_redacted(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew_redacted(int content);

#endif