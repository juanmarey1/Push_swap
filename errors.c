#include "inc/push_swap.h"

void    ft_double_free(char **double_str)
{
    int i;

    i = 0;
    while (double_str[i])
    {
        free(double_str[i]);
        i++;
    }
    free(double_str);
}

void    ft_error(char *str)
{
    ft_putstr_fd("Error\n", 2);
    ft_putstr_fd(str, 2);
    ft_putstr_fd("\n", 2);
    exit (1);
}