/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:50:21 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 14:50:23 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	order_list(int i, t_stack *stack)
{
	if (i <= (stack->a_nums + 1) / 2)
	{
		while (i-- > 1)
			rotate_a(stack);
	}
	else
	{
		i = stack->a_nums + 1 - i;
		while (i-- > 0)
			reverse_rotate_a(stack);
	}
}

void	numbers_ordered(t_stack *stack)
{
	t_list	*list_a;
	int		min_num;
	int		i;

	i = 1;
	list_a = *stack->stack_a;
	min_num = list_a->content;
	while (list_a != NULL)
	{
		if (list_a->content < min_num)
			min_num = list_a->content;
		list_a = list_a->next;
	}
	list_a = *stack->stack_a;
	while (list_a->content != min_num)
	{
		list_a = list_a->next;
		i++;
	}
	order_list(i, stack);
}

void	optimal_b_to_a(t_stack *stack, int i)
{
	int	a_nums;

	a_nums = stack->a_nums;
	stack->up_a = 0;
	stack->down_a = 0;
	if (i <= (a_nums + 1) / 2)
	{
		stack->up_a = i - 1;
		stack->down_a = (a_nums - i) + 1;
	}
	else
	{
		stack->down_a = (a_nums - i) + 1;
		stack->up_a = i - 1;
	}
}

void	push_back_to_a(t_stack *stack)
{
	if (stack->up_a <= stack->down_a)
	{
		stack->down_a = 0;
		while (stack->up_a-- > 0)
			rotate_a(stack);
	}
	else if (stack->down_a < stack->up_a)
	{
		stack->up_a = 0;
		while (stack->down_a-- > 0)
			reverse_rotate_a(stack);
	}
	push_a(stack);
}
