#include "inc/push_swap.h"

int find_bigger_b_num(t_list *listb)
{
    int bigger_num;

    if (listb->content > listb->next->content)
        bigger_num = (listb->content);
    else
        bigger_num = (listb->next->content);
    listb = listb->next;
    while (listb->next != NULL)
    {
        if (bigger_num < listb->next->content)
            bigger_num = (listb->next->content);
        listb = listb->next;
    }
    return (bigger_num);
}

int find_closest_number(int num_a, t_list *list_b)
{
    int     num_b;
    t_list  *copy_list_b;

    copy_list_b = list_b;
    while (list_b->next != NULL)
    {
        if (num_a < (list_b->content))
            list_b = list_b->next;
        else
            break ;
        if (list_b->next == NULL)
        {
            if (num_a < (list_b->content))
            {
                num_b = find_bigger_b_num(copy_list_b);
                return(num_b);
            }
        }
    }
    num_b = find_closest_number_to_a(num_a, copy_list_b);
    return (num_b);
}

int find_true_moves(t_stack *stack)
{
    if (stack->which_case == 1)
    {
        if (stack->up_a >= stack->up_b)
            return (stack->up_a);
        else
            return (stack->up_b);
    }
    else if (stack->which_case == 2)
    {
        if (stack->down_a >= stack->down_b)
            return (stack->down_a);
        else
            return (stack->down_b);
    }
    else if (stack->which_case == 3)
        return (stack->up_a + stack->down_b);
    else
        return (stack->down_a + stack->up_b);
}

int find_cost_of_number(t_stack *stack, int num)
{
    int     i;
    int     j;
    int     num_a;
    int     num_b;
    t_list  *list_a;
    t_list  *list_b;

    i = 0;
    j = 1;
    list_b = *stack->stack_b;
    list_a = *stack->stack_a;
    while (++i < num)
        list_a = list_a->next;
    num_a = (list_a->content);
    num_b = find_closest_number(num_a, list_b);
    while ((list_b->content) != num_b)
    {
        j++;
        list_b = list_b->next;
    }
    i = find_opt_moves_a(stack, i);
    j = find_opt_moves_b(stack, j);
    j = find_true_moves(stack);
    return (j + 1);
}

int find_cost(t_stack *stack)
{
    int     *numbers_cost;
    int     i;
    int     most_eff_cost;

    i = 0;
    numbers_cost = (int*)malloc(sizeof(int) * (stack->a_nums + 1));
    if (!numbers_cost)
        return (0);
    while (i < stack->a_nums)
    {
        numbers_cost[i] = find_cost_of_number(stack, i + 1);
        i++;
    }
    numbers_cost[i] = 0;
    i = 0;
    most_eff_cost = numbers_cost[i];
    while (numbers_cost[i] != 0)
    {
        if (numbers_cost[i] < most_eff_cost)
            most_eff_cost = numbers_cost[i];
        i++;
    }
    i = 0;
    while (numbers_cost[i] != most_eff_cost)
        i++;
    stack->moves = most_eff_cost;
    numbers_cost[i] = find_cost_of_number(stack, i + 1);
    return (i + 1);
}