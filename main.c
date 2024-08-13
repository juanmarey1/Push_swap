#include "inc/push_swap.h"

void    struct_init(t_stack *stack)
{
    stack->args = NULL;
    stack->stack_a = NULL;
    stack->stack_b = NULL;
    stack->atoi_error = 0;
    stack->moves = 0;
    stack->a_nums = 0;
    stack->b_nums = 0;
}

void    args_control(int argc, char **argv, t_stack *stack)
{
    if (argc < 2 || argc > 501)
        ft_error(ARGS_ERROR);
    if (argc == 2)
        check_args_int_1(argv, stack);
    else
        check_args_int_2(argc, argv, stack);
    check_args_max_int(stack);
}

void    push_2_numbers(t_stack  *stack)
{
    push_b(stack);
    push_b(stack);
    stack->a_nums = stack->a_nums - 2;
    stack->b_nums = stack->b_nums + 2;
    while (stack->a_nums > 3)
    {
        stack->number_in_list_a = find_cost(&stack);
        printf("%s\n", stack->number_in_list_a);
    }
}

int main(int argc, char *argv[])
{
    t_stack stack;

    struct_init(&stack);
    args_control(argc, argv, &stack);
    create_list(&stack);
    if (stack.a_nums > 3)
        push_2_numbers(&stack);
    // else condition for 3 or less
}