/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:46:08 by iduman            #+#    #+#             */
/*   Updated: 2025/07/27 17:04:45 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*create_list(long *numbers, t_list **head)
{
	t_list	*new_node;
	t_list	*current;
	size_t	i;

	if (!numbers || !head)
		return (NULL);
	*head = NULL;
	i = -1;
	while (numbers[++i])
	{
		new_node = ft_lstnew(ft_memdup(numbers + i, sizeof(int)));
		if (!new_node)
			return (ft_lstclear(head, free), NULL);
		if (!*head)
			*head = new_node;
		else
		{
			current = *head;
			while (current->next)
				current = current->next;
			current->next = new_node;
		}
	}
	return (*head);
}

int	is_healthy(const char *argv[], t_list **head)
{
	long		*numbers;
	long int	cap;
	long int	count;
	char		**split;

	cap = 64;
	count = 0;
	numbers = malloc(sizeof(long) * cap);
	if (!numbers)
		return (0);
	while (*argv)
	{
		split = ft_split_charset(*argv, " \t\n\v\f\r");
		if (!split)
			return (free(numbers), ft_free_split(split), 0);
		if (!ft_health_helper(split, &numbers, &cap, &count))
			return (free(numbers), ft_free_split(split), 0);
		ft_free_split(split);
		argv++;
	}
	create_list(numbers, head);
	free(numbers);
	if (!*head)
		return (0);
	return (1);
}

/**
 * @brief Bubble sort the list
 */
void	indexer(t_list *head)
{
	t_list	*current;
	t_list	*other;
	size_t	myindex;

	current = head;
	while (current)
	{
		myindex = 1;
		other = head;
		while (other)
		{
			if (*(int *)(other->content) < *(int *)(current->content))
				myindex++;
			other = other->next;
		}
		current->index = myindex;
		current = current->next;
	}
}

void	print_list(void *content)
{
	ft_putnbr_fd((*(int *)content), 1);
	ft_putchar_fd('\n', 1);
}

int	main(int argc, char const *argv[])
{
	t_list	*head_a;

	if (argc < 2)
		return (ft_putstr_fd("Error\n", 1), 1);
	if (!is_healthy(argv + 1, &head_a))
		return (ft_putstr_fd("Error\n", 1), 1);
	indexer(head_a);
	ft_lstiter(head_a, &print_list);
	ft_lstclear(&head_a, free);
	return (0);
}
