#include "push_swap.h"

int ft_abs(int a)
{
    return (a < 0) ? -a : a;
}

void assign_positions(t_list *head)
{
    int pos = 0;
    while (head)
    {
        head->pos = pos++;
        head = head->next;
    }
}

/* Find the target position in A for a given value from B */
int find_target_pos(t_list *head_a, int index_b)
{
    int target = 2147483647;
    int target_pos = 0;
    int pos = 0;

    while (head_a)
    {
        if (head_a->index > index_b && head_a->index < target)
        {
            target = head_a->index;
            target_pos = pos;
        }
        pos++;
        head_a = head_a->next;
    }
    /* if none greater, wrap to smallest */
    if (target == 2147483647)
    {
        target = 2147483647;
        pos = 0;
        while (head_a)
        {
            if (head_a->index < target)
            {
                target = head_a->index;
                target_pos = pos;
            }
            pos++;
            head_a = head_a->next;
        }
    }
    return target_pos;
}

/* Assign target positions in A for all nodes in B */
void assign_target_positions(t_list *head_a, t_list *head_b)
{
    while (head_b)
    {
        head_b->target_pos = find_target_pos(head_a, head_b->index);
        head_b = head_b->next;
    }
}

/* Calculate cost to bring a node to top of stack */
int calc_cost(int pos, int size)
{
    if (pos <= size / 2)
        return pos;
    return (pos - size);
}

/* Calculate cost_a, cost_b for each in B */
void calculate_costs(t_list *head_a, t_list *head_b)
{
    int size_a = ft_lstsize(head_a);
    int size_b = ft_lstsize(head_b);

    while (head_b)
    {
        head_b->cost_b = calc_cost(head_b->pos, size_b);
        head_b->cost_a = calc_cost(head_b->target_pos, size_a);
        head_b->cost_ab = ft_abs(head_b->cost_a) + ft_abs(head_b->cost_b);
        head_b = head_b->next;
    }
}

/* Find node in B with minimal combined cost */

static t_list *find_cheapest(t_list *head_b)
{
    t_list *cheapest = head_b;
    int min_cost = head_b->cost_ab;
    head_b = head_b->next;
    while (head_b)
    {
        if (head_b->cost_ab < min_cost)
        {
            min_cost = head_b->cost_ab;
            cheapest = head_b;
        }
        head_b = head_b->next;
    }
    return cheapest;
}

/* Execute required rotations and push for cheapest node */
void perform_move(t_list **head_a, t_list **head_b, t_list *node)
{
    /* combined rotations when both costs have same sign */
    while (node->cost_b > 0 && node->cost_a > 0)
    {
        rotater_s(head_a, head_b);
        node->cost_b--;
        node->cost_a--;
    }
    while (node->cost_b < 0 && node->cost_a < 0)
    {
        rrotater_s(head_a, head_b);
        node->cost_b++;
        node->cost_a++;
    }

    /* rotate B into position */
    while (node->cost_b > 0)
    {
        rotater(head_b, 'b');
        node->cost_b--;
    }
    while (node->cost_b < 0)
    {
        rrotater(head_b, 'b');
        node->cost_b++;
    }

    /* rotate A into position */
    while (node->cost_a > 0)
    {
        rotater(head_a, 'a');
        node->cost_a--;
    }
    while (node->cost_a < 0)
    {
        rrotater(head_a, 'a');
        node->cost_a++;
    }

    /* finally push from B to A */
    put(head_b, head_a, 'a');
}

/* Main function orchestrating cost-based moves */
void list_functions(t_list **head_a, t_list **head_b)
{
    while (*head_b)
    {
        assign_positions(*head_a);
        assign_positions(*head_b);
        assign_target_positions(*head_a, *head_b);
        calculate_costs(*head_a, *head_b);
        t_list *cheapest = find_cheapest(*head_b);
        perform_move(head_a, head_b, cheapest);
    }
    while(is_sorted(*head_a) == 0)
    {
        rrotater(head_a, 'a');
    }
}
