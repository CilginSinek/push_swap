/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortbig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 22:57:06 by iduman            #+#    #+#             */
/*   Updated: 2025/08/16 02:33:01 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_num)
{
	int	bits;

	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_sort(t_list **head_a, t_list **head_b)
{
	int	max_bits;
	int	num;
	int	i;
	int	j;
	int	size_a;

	i = 0;
	max_bits = get_max_bits(ft_lstsize(*head_a) - 1);
	while (i < max_bits)
	{
		j = 0;
		size_a = ft_lstsize(*head_a);
		while (j < size_a)
		{
			num = (*head_a)->index;
			if (((num >> i) & 1) == 0)
				put(head_a, head_b, 'b');
			else
				rotater(head_a, 'a');
			j++;
		}
		while (*head_b)
			put(head_b, head_a, 'a');
		i++;
	}
}

void	list_functions(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) < 4)
	{
		if (ft_lstsize(*head_a) == 2)
			swap(head_a, 'a');
		else if (ft_lstsize(*head_a) == 3)
			sort_three(head_a);
		return ;
	}
	else if (ft_lstsize(*head_a) < 6)
		sort_five(head_a, head_b);
	else
		radix_sort(head_a, head_b);
}
