/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:46:08 by iduman            #+#    #+#             */
/*   Updated: 2025/07/18 19:03:24 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_healty(char const *argv[])
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = 0;
        while (argv[i][j])
        {
            if (!ft_isdigit(argv[i][j]) && argv[i][j] != '+' && argv[i][j] != '-')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

t_list *create_list(char const *argv[])
{
    t_list *head;
    t_list *new_node;
    void *tmp;
    int i;

    head = NULL;
    i = 0;
    while (argv[i])
    {
        tmp = ft_calloc(1, sizeof(int));
        new_node = ft_lstnew(memintset(tmp, ft_atoi(argv[i])));
        if (!new_node)
            return (NULL);
        ft_lstadd_back(&head, new_node);
        i++;
    }
    return (head);
}

/**
 * @brief Bubble sort the list
 */
void indexer(t_list *head)
{
    t_list *current;
    t_list *other;
    size_t myindex;

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

void print_list(t_list *node)
{
    ft_putnbr((node->index));
    ft_putchar('\n');
}

int main(int argc, char const *argv[])
{
    t_list *head_a;

    if (argc < 2)
        return (ft_putstr("Error\n"), 1);
    if (!is_healty(argv + 1))
        return (ft_putstr("Error\n"), 1);
    head_a = create_list(argv + 1);
    if (!head_a)
        return (ft_putstr("Error\n"), 1);

    indexer(head_a);
    ft_lstiter(head_a, &print_list);
    return 0;
}
