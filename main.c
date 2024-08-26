/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:43:34 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 15:43:35 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	struct_init(t_stack *stack)
{
	stack->args = NULL;
	stack->stack_a = NULL;
	stack->stack_b = NULL;
	stack->atoi_error = 0;
	stack->a_nums = 0;
	stack->b_nums = 0;
	stack->movements = 0;
}

void	args_control(int argc, char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] == ' ')
			i++;
		if (argv[1][i] == '\0')
			ft_error(stack);
		if (argv[1][0] == '\0')
			ft_error(stack);
		check_args_argc_is_2(argv, stack);
	}
	else
		check_args_argc_not_2(argc, argv, stack);
	check_args_max_int(stack);
	check_no_rep_num(stack->args, stack);
}

int	check_if_ordered(t_stack *stack)
{
	t_list	*list_a;

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

void	algorithm(t_stack *stack)
{
	stack->stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack->stack_b)
		ft_error(stack);
	*stack->stack_b = NULL;
	push_b(stack);
	push_b(stack);
	stack->a_nums = stack->a_nums - 2;
	stack->b_nums = stack->b_nums + 2;
	while (stack->a_nums > 3)
	{
		find_cost(stack);
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

int	main(int argc, char *argv[])
{
	t_stack	stack;

	struct_init(&stack);
	if (argc < 2)
		return (0);
	args_control(argc, argv, &stack);
	create_list(&stack);
	if (check_if_ordered(&stack) == 1)
	{
		ft_end_program(&stack);
		return (0);
	}
	if (stack.a_nums == 2)
		swap_a(&stack);
	else if (stack.a_nums == 3)
		sort_3_nums(&stack);
	else if (stack.a_nums == 4)
		sort_4_nums(&stack);
	else
		algorithm(&stack);
	ft_end_program(&stack);
	return (0);
}
