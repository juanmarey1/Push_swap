#include "inc/push_swap.h"

int	ft_error_atoi(t_stack_a *stack_a)
{
	stack_a->atoi_error = 1;
	return (0);
}

int	ft_atoi_long(const char *str, t_stack_a *stack_a)
{
	long long	longnum;
	int			neg;

	longnum = 0;
	neg = 0;
	while ((*str > 8 && *str < 14) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			neg++;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		longnum = longnum * 10;
		longnum = longnum + (*str - '0');
		str++;
	}
	if ((longnum > (long long int)INT_MAX && neg == 0) ||
            (longnum > (long long)INT_MAX + 1 && neg == 1))
		return (ft_error_atoi(stack_a));
	if (neg == 1)
		return (longnum * -1);
	return (longnum);
}