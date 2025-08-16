/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortlittle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:19:15 by iduman            #+#    #+#             */
/*   Updated: 2025/08/16 14:18:48 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	where_min(t_list *head)
{
	int		pos;
	int		min_pos;
	int		min;
	t_list	*current;

	min = head->index;
	min_pos = 0;
	pos = 0;
	current = head;
	while (current)
	{
		if (current->index < min)
		{
			min = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

static void	replacer(t_list **head_a, int pos)
{
	int	size;

	size = ft_lstsize(*head_a);
	if (pos <= size / 2)
		while (pos-- > 0)
			rotater(head_a, 'a');
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrotater(head_a, 'a');
	}
}

static void	push_min_to_b(t_list **head_a, t_list **head_b)
{
	replacer(head_a, where_min(*head_a));
	put(head_a, head_b, 'b');
}

void	sort_five(t_list **head_a, t_list **head_b)
{
	while (ft_lstsize(*head_a) > 3)
		push_min_to_b(head_a, head_b);
	sort_three(head_a);
	while (*head_b)
		put(head_b, head_a, 'a');
}
