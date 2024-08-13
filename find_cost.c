#include "inc/push_swap.h"

int find_bigger_b_num(t_list *listb)
{
    int bigger_num;

    if (ft_atoi(listb->content) > ft_atoi(listb->next->content))
        bigger_num = ft_atoi(listb->content);
    else
        bigger_num = ft_atoi(listb->next->content);
    listb = listb->next;
    while (listb->next != NULL)
    {
        if (bigger_num < ft_atoi(listb->next->content))
            bigger_num = ft_atoi(listb->next->content);
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
        if (num_a < ft_atoi(list_b->content))
            list_b = list_b->next;
        else
            break ;
        if (list_b->next == NULL)
        {
            if (num_a < ft_atoi(list_b->content))
            {
                num_b = find_bigger_b_num(copy_list_b);
                return(num_b);
            }
        }
    }
    num_b = find_closest_number_to_a(num_a, copy_list_b);
    return (num_b);
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
    j = 0;
    list_b = *stack->stack_b;
    list_a = *stack->stack_a;
    while (++i < num)
        list_a = list_a->next;
    num_a = ft_atoi(list_a->content);
    num_b = find_closest_number(num_a, list_b);
    while (ft_atoi(list_b->content) != num_b)
    {
        j++;
        list_b = list_b->next;
    }
    i = find_opt_moves_a(stack, i);
    j = find_opt_moves_b(stack, j);
    return (i + j);
}

int find_cost(t_stack *stack)
{
    int     *numbers_cost;
    int     i;
    int     most_eff_cost;

    i = 0;
    numbers_cost = (int*)malloc(sizeof(int) * (stack->a_nums + 1));
    while (i < stack->a_nums)
    {
        numbers_cost[i] = find_cost_of_number(stack, i + 1);
        i++;
    }
    numbers_cost[i] = NULL;
    i = 0;
    most_eff_cost = numbers_cost[i];
    while (numbers_cost[i++])
    {
        if (numbers_cost[i] < most_eff_cost)
            most_eff_cost = numbers_cost[i];
    }
    i = 0;
    while (numbers_cost[i] != most_eff_cost)
        i++;
    return (i + 1);
}
