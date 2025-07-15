/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:52:13 by iduman            #+#    #+#             */
/*   Updated: 2025/07/15 10:58:57 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new_list)
		return ((t_list *) NULL);
	new_list->content = content;
	new_list->next = NULL;
	return (new_list);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*mylst;

	if (!lst)
		return (0);
	i = 0;
	mylst = lst;
	while (1)
	{
		if (!mylst->next)
			return (i + 1);
		i++;
		mylst = mylst->next;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*mylist;
	t_list		tmp;

	if (!*lst || !del)
		return ;
	mylist = *lst;
	while (1)
	{
		tmp = *mylist;
		del(mylist->content);
		free(mylist);
		if (!tmp.next)
		{
			*lst = NULL;
			return ;
		}
		mylist = tmp.next;
	}
}
