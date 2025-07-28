/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 13:36:20 by iduman            #+#    #+#             */
/*   Updated: 2025/07/28 17:50:02 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*mylist;
	t_list		tmp;

	if (!lst || !*lst || !del)
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
