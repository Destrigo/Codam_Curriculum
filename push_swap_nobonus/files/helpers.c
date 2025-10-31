/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:10:50 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/30 12:14:52 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_if_sort(t_stack *stack_a)
{
	int		tp1;
	int		tp2;

	tp1 = 0;
	tp2 = 0;
	while (stack_a->next)
	{
		tp1 = stack_a->content;
		tp2 = stack_a->next->content;
		if (tp1 > tp2)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

int	is_int(char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\r' || *str == '\v'
		|| *str == '\f' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (!*str)
		return (1);
	while (ft_isdigit(*str) == 1)
		str++;
	if (*str != '\0')
		return (1);
	return (0);
}

int	checker_input(int args, char *argv[], t_stack *stack_a)
{
	long long	i;
	int			hash[1024];

	i = 0;
	while (++i < args)
	{
		if (is_int(argv[i]) == 1 || (ft_atoi(argv[i]) > INT_MAX
				|| ft_atoi(argv[i]) < (-INT_MAX - 1)))
			return (1);
	}
	i = 0;
	while (i < args - 1)
	{
		hash[i] = stack_a->content;
		stack_a = stack_a->next;
		i++;
	}
	sort_hash(hash, args);
	while (--i > 0)
	{
		if (hash[i] == hash[i - 1])
			return (1);
	}
	return (0);
}

void	sort_hash(int hash[], int args)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	tmp = 0;
	while (i < (args))
	{
		j = i + 1;
		while (j < (args - 1))
		{
			if (hash[i] > hash[j])
			{
				tmp = hash[i];
				hash[i] = hash[j];
				hash[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}
