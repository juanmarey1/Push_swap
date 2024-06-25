#include "inc/push_swap.h"

void    check_args_int_1(char **argv, t_stack_a *stack_a) //If it comes with commas
{
    int i;
    int j;

    i = -1;
    stack_a->args = ft_split(argv[1], ' ');
    while (stack_a->args[++i])
    {
        j = 0;
        if ((stack_a->args[i][j] == '-' && (stack_a->args[i][j + 1] >= '0' && stack_a->args[i][j + 1] <= '9'))
                || (stack_a->args[i][j] >= '0' && stack_a->args[i][j] <= '9'))
            j++;
        else
            ft_error(NOT_NUM_ARGS);
        while (stack_a->args[i][j])
        {
            if (!(stack_a->args[i][j] >= '0' && stack_a->args[i][j] <= '9'))
                ft_error(NOT_NUM_ARGS);
            j++;
        }
    }
}

char    **ft_doublestrcpy(int argc, char **argv)
{
    int i;
    char    **double_str;

    double_str = (char **)malloc(sizeof(char *) * argc);
    if (!double_str)
        ft_error(MALLOC_ERR);
    i = 1;
    while (argv[i])
    {
        double_str[i - 1] = ft_strdup(argv[i]);
        if (!double_str[i - 1])
        {
            ft_double_free(double_str);
            ft_error(MALLOC_ERR);
        }
        i++;
    }
    double_str[i - 1] = NULL;
    return (double_str);
}

void	check_args_int_2(int argc, char **argv, t_stack_a *stack_a)
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
            ft_error(NOT_NUM_ARGS);
        while (argv[i][j])
        {
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                ft_error(NOT_NUM_ARGS);
            j++;
        }
    }
    stack_a->args = ft_doublestrcpy(argc, argv);
}

void    check_no_rep_num(char **double_str)
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
                ft_double_free(double_str);
                ft_error(ARGS_REPEAT);
            }
            else
                j++;
        }
        j = stay + 2;
    }
}

void    check_args_max_int(t_stack_a *stack_a)
{
    int i;

    i = 0;
    while (stack_a->args[i])
    {
        if (ft_atoi(stack_a->args[i]) > MAX_NUM ||
                ft_atoi(stack_a->args[i] < MIN_NUM))
        {
            ft_double_free(stack_a->args);
            ft_error(INV_NUM_ARGS);
        }
        else
            i++;
    }
    check_no_rep_num(stack_a->args);
}