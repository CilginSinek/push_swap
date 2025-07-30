/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:50:52 by iduman            #+#    #+#             */
/*   Updated: 2025/07/18 18:59:36 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief swaper
 * 'a' for "sa"
 * 'b' for "as"
 * 'a'+'b' for "sa as"
 */
void	swap(t_list **head, int i)
{
	t_list	*tmp;

	if (ft_lstsize(*head) < 2)
		return ;
	tmp = (*head)->next;
	(*head)->next = tmp->next;
	tmp->next = *head;
	*head = tmp;
	if (i == 'a')
		ft_putstr_fd("sa\n", 1);
	if (i == 'b')
		ft_putstr_fd("sb\n", 1);
	if (i == 'a' + 'b')
		ft_putstr_fd("ss\n", 1);
}

void	swap_s(t_list **head_a, t_list **head_b)
{
	swap(head_a, 0);
	swap(head_b, 'a' + 'b');
}

/**
 * @brief swaper
 * 'a' for "pa"
 * 'b' for "pb"
 */
void	put(t_list **giver_list, t_list **taker_list, int i)
{
	t_list	*holder1;

	if (ft_lstsize(*giver_list) == 0)
		return ;
	holder1 = (*giver_list)->next;
	(*giver_list)->next = *taker_list;
	*taker_list = *giver_list;
	*giver_list = holder1;
	if (i == 'a')
		ft_putstr_fd("pa\n", 1);
	if (i == 'b')
		ft_putstr_fd("pb\n", 1);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		swap(a, 'a');
	else if (first > second && second > third)
	{
		swap(a, 'a');
		rrotater(a, 'a');
	}
	else if (first > second && second < third && first > third)
		rotater(a, 'a');
	else if (first < second && second > third && first < third)
	{
		swap(a, 'a');
		rotater(a, 'a');
	}
	else if (first < second && second > third && first > third)
		rrotater(a, 'a');
}
