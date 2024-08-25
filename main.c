#include "inc/push_swap.h"

void    struct_init(t_stack *stack)
{// Initiate struct
    stack->args = NULL;
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->atoi_error = 0;
    stack->moves = 0;
    stack->a_nums = 0;
    stack->b_nums = 0;
    stack->movements = 0;
}

void    args_control(int argc, char **argv, t_stack *stack)
{// Check args number and see if they have "" or not
    if (argc < 2 || argc > 501)
        ft_error(ARGS_ERROR, stack);
    if (argc == 2)
        check_args_argc_is_2(argv, stack);
    else
        check_args_argc_not_2(argc, argv, stack);
    check_args_max_int(stack);
}

void    algorithm(t_stack  *stack)
{
    stack->stack_b = (t_list**)malloc(sizeof(t_list*));
    if (!stack->stack_b)
        return ;
    *stack->stack_b = NULL;
    push_b(stack);
    push_b(stack);
    stack->a_nums = stack->a_nums - 2;
    stack->b_nums = stack->b_nums + 2;
    while (stack->a_nums > 3)
    {
        stack->num_list_a = find_cost(stack);
        push_a_to_b(stack);
        stack->a_nums--;
        stack->b_nums++;
    }
    sort_3_nums(stack);
    while (stack->b_nums > 0)
    {
        back_to_a(stack);
        stack->b_nums--;
        stack->a_nums++;
    }
    numbers_ordered(stack);
    *stack->stack_b = NULL;
}

int    check_if_ordered(t_stack *stack)
{
    t_list  *list_a;

    list_a = *stack->stack_a;
    while (list_a->next != NULL)
    {
        if (list_a->content > list_a->next->content)
            return (0);
        else
            list_a = list_a->next;
    }
    return (1);
}

int main(int argc, char *argv[])
{
    t_stack stack;

    struct_init(&stack);
    args_control(argc, argv, &stack);
    create_list(&stack);
    if (check_if_ordered(&stack) == 1)
        return (0);
    if (stack.a_nums > 3 && stack.a_nums != 4)
        algorithm(&stack);
    else if (stack.a_nums == 4)
        sort_4_nums(&stack);
    else if (stack.a_nums == 2)
    {
        if ((*stack.stack_a)->content > (*stack.stack_a)->next->content)
            swap_a(&stack);
    }
    else
        sort_3_nums(&stack);
    ft_end_program(&stack);
    return (0);
}
    // t_list *list_a;
    // list_a = *stack.stack_a;
    // ft_printf("movements: %d\n", stack.movements);
    // ft_printf("//////////////LIST     A/////////////////////\n");
    // while (list_a != NULL)
    // {
    //     ft_printf("%d\n", list_a->content);
    //     list_a = list_a->next;
    // }