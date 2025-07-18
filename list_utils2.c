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

/**
 * @brief rrotater
 * 'a' for "ra"
 * 'b' for "rb"
 * 'a'+'b' for "ra rb"
 */
void    rrotater(t_list **head, int i)
{
    t_list *tmp;
    void *content_holder;

    tmp = ft_lstlast(*head);
    content_holder = tmp->content;
    free(tmp);
    tmp = NULL;
    tmp = ft_lstnew(content_holder);
    ft_lstadd_front(head, tmp);
    if (i == 'a')
        ft_putstr("ra\n");
    if (i == 'b')
        ft_putstr("rb\n");
    if (i == 'a' + 'b')
        ft_putstr("ra rb\n");
}

void rrotater_s(t_list **head_a, t_list **head_b)
{
    rrotater(head_a, 0);
    rrotater(head_b, 'a' + 'b');

}

void router(t_list **head, int i)
{
    t_list *tmp;

    tmp = *head;
    ft_lstadd_back(head, tmp);
    *head = (*head)->next;
    tmp->next = NULL;
    if (i == 'a')
        ft_putstr("ra\n");
    if (i == 'b')
        ft_putstr("rb\n");
    if (i == 'a' + 'b')
        ft_putstr("ra rb\n");
}

void router_s(t_list **head_a, t_list **head_b)
{
    router(head_a, 0);
    router(head_b, 'a' + 'b');
}

void	ft_lstiter(t_list *lst, void (*f)(size_t))
{
	t_list	*mylst;

	if (!lst || !f)
		return ;
	mylst = lst;
	while (1)
	{
		f(mylst->index);
		if (mylst->next == NULL)
			return ;
		mylst = mylst->next;
	}
}
