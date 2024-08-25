#include "inc/push_swap.h"

void    check_args_argc_is_2(char **argv, t_stack *stack)
{// If numbers are between "" (checks that they are int)
    int i;
    int j;

    i = -1;
    stack->args = ft_split(argv[1], ' ');
    while (stack->args[++i])
    {
        j = 0;
        if ((stack->args[i][j] == '-' && (stack->args[i][j + 1] >= '0' && stack->args[i][j + 1] <= '9'))
                || (stack->args[i][j] >= '0' && stack->args[i][j] <= '9'))
            j++;
        else
            ft_error(NOT_NUM_ARGS, stack);
        while (stack->args[i][j])
        {
            if (!(stack->args[i][j] >= '0' && stack->args[i][j] <= '9'))
                ft_error(NOT_NUM_ARGS, stack);
            j++;
        }
    }
}

char    **ft_doublestrcpy(int argc, char **argv, t_stack *stack)
{
    int i;
    char    **double_str;

    double_str = (char **)malloc(sizeof(char *) * argc);
    if (!double_str)
        ft_error(MALLOC_ERR, stack);
    i = 1;
    while (argv[i])
    {
        double_str[i - 1] = ft_strdup(argv[i]);
        if (!double_str[i - 1])
        {
            ft_double_free(double_str, stack);
            ft_error(MALLOC_ERR, stack);
        }
        i++;
    }
    double_str[i - 1] = NULL;
    return (double_str);
}

void	check_args_argc_not_2(int argc, char **argv, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
    {
        j = 0;
        if ((argv[i][j] == '-' && (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
                || (argv[i][j] >= '0' && argv[i][j] <= '9'))
            j++;
        else
            ft_error(NOT_NUM_ARGS, stack);
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                ft_error(NOT_NUM_ARGS, stack);
            j++;
        }
    }
    stack->args = ft_doublestrcpy(argc, argv, stack);
}

void    check_no_rep_num(char **double_str, t_stack *stack)
{
    int len;
    int j;
    int stay;

    len = 0;
    while (double_str[len])
        len++;
    j = 1;
    while (--len > 0)
    {
        stay = j - 1;
        while (double_str[j])
        {
            if (ft_atoi(double_str[stay]) == ft_atoi(double_str[j]))
            {
                ft_double_free(double_str, stack);
                ft_error(ARGS_REPEAT, stack);
            }
            else
                j++;
        }
        j = stay + 2;
    }
}

void    check_args_max_int(t_stack *stack)
{
    int i;

    i = 0;
    while (stack->args[i])
    {
        if (ft_atoi_long(stack->args[i], stack) == 0 && stack->atoi_error == 1)
        {
            ft_double_free(stack->args, stack);
            ft_error(INV_NUM_ARGS, stack);
        }
        else
            i++;
    }
    check_no_rep_num(stack->args, stack);
}