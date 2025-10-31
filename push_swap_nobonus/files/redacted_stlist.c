/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redacted_stlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtaranti <mtaranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:22:47 by mtaranti          #+#    #+#             */
/*   Updated: 2025/10/28 13:00:56 by mtaranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear_redacted(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while ((*lst) != NULL)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void	ft_lstdelone_redacted(t_stack *lst)
// {
// 	if (!lst)
// 		return ;
// 	lst->next = NULL;
// 	free(lst);
// }

void	ft_lstadd_back_redacted(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (lst || new)
	{
		if (!*lst)
			(*lst = new);
		else
		{
			tmp = *lst;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}

t_stack	*ft_lstnew_redacted(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->index_num = -1;
	new->next = NULL;
	return (new);
}
