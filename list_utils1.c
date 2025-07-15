/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 10:50:52 by iduman            #+#    #+#             */
/*   Updated: 2025/07/15 12:51:22 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*mylst;

	if (!lst)
		return (NULL);
	mylst = lst;
	while (1)
	{
		if (!mylst->next)
			return (mylst);
		mylst = mylst->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/**
 * @brief swaper
 * 'a' for "sa"
 * 'b' for "as"
 * 'a'+'b' for "sa as"
 */
void	swap(t_list **head, int i)
{
    t_list *tmp;

    if(ft_lstsize(*head) < 2)
        return ;
    tmp = (*head)->next;
    (*head)->next = tmp->next;
    tmp->next = *head;
    *head = tmp;
    if (i == 'a')
        ft_putstr("sa\n");
    if (i == 'b')
        ft_putstr("as\n");
    if (i == 'a' + 'b')
        ft_putstr("sa as\n");
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
void	putter(t_list **giver_list, t_list **taker_list, int i)
{
    t_list *holder1;
    t_list *holder2;

    if(ft_lstsize(*giver_list) == 0)
        return ;
    holder1 = (*giver_list)->next;
    (*giver_list)->next = *taker_list;
    *taker_list = *giver_list;
    *giver_list = holder1;
    if (i == 'a')
        ft_putstr("pa\n");
    if (i == 'b')
        ft_putstr("pb\n");
}