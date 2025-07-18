/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:46:08 by iduman            #+#    #+#             */
/*   Updated: 2025/07/18 18:39:03 by iduman           ###   ########.fr       */
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

void indexer(t_list *head)
{
    t_list *current;
    t_list *temp_index;
    size_t index;

    index = 1;
    temp_index = 0;
    current = head;
    temp_index = head;
    if(current == NULL)
        return;
    while (temp_index != NULL)
    {
            while (current->next != NULL)
            {
                current = temp_index;
                index = 0;
                while (current != NULL)
                {
                    if (*(int *)(current->content) < *(int *)(temp_index->content))
                        index++;
                    current = current->next;
                }
                temp_index->index = index;
                temp_index = temp_index->next;
            }
    }
    current = head;
}

int main(int argc, char const *argv[])
{
    t_list *head_a;
    t_list *head_b;

    if (argc < 2)
        return (ft_putstr("Error\n"), 1);
    if (!is_healty(argv + 1))
        return (ft_putstr("Error\n"), 1);
    head_a = create_list(argv + 1);
    if (!head_a)
        return (ft_putstr("Error\n"), 1);
    head_b = NULL;
    indexer(head_a);
    

    
        
    
    return 0;
}
