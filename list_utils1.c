/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:23:46 by iduman            #+#    #+#             */
/*   Updated: 2025/07/15 12:53:46 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_last(t_list **head)
{
	t_list	*here;
	t_list	*prev;

	if (!*head)
		return ;
	if (!(*head)->next)
		*head = NULL;
	else
	{
		here = *head;
		prev = NULL;
		while (here->next != NULL)
		{
			prev = here;
			here = here->next;
		}
		prev->next = NULL;
	}
}

/**
 * @brief rrotater
 * 'a' for "ra"
 * 'b' for "rb"
 * 'a'+'b' for "ra rb"
 */
void	rrotater(t_list **head, int i)
{
	t_list	*tmp;

	tmp = ft_lstlast(*head);
	remove_last(head);
	tmp->next = *head;
	*head = tmp;
	if (i == 'a')
		ft_putstr_fd("rra\n", 1);
	if (i == 'b')
		ft_putstr_fd("rrb\n", 1);
	if (i == 'a' + 'b')
		ft_putstr_fd("rrr\n", 1);
}

void	rrotater_s(t_list **head_a, t_list **head_b)
{
	rrotater(head_a, 0);
	rrotater(head_b, 'a' + 'b');
}

void	rotater(t_list **head, int i)
{
    t_list	*tmp;

    if (!*head || !(*head)->next)
        return ;
    tmp = *head;
    *head = (*head)->next;
    tmp->next = NULL;
    ft_lstadd_back(head, tmp);
	if (i == 'a')
		ft_putstr_fd("ra\n", 1);
	if (i == 'b')
		ft_putstr_fd("rb\n", 1);
	if (i == 'a' + 'b')
		ft_putstr_fd("rr\n", 1);
}

void	rotater_s(t_list **head_a, t_list **head_b)
{
	rotater(head_a, 0);
	rotater(head_b, 'a' + 'b');
}
