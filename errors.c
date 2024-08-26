/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:31:23 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 15:31:25 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	ft_double_free(char **double_str)
{
	int	i;

	i = 0;
	while (double_str[i])
	{
		free(double_str[i]);
		i++;
	}
	free(double_str);
	double_str = NULL;
}

void	ft_free_stack(t_list **list)
{
	t_list	*list_head;

	while (*list)
	{
		list_head = *list;
		*list = (*list)->next;
		list_head->content = 0;
		free(list_head);
	}
	free(list);
	list = NULL;
}

void	ft_error(t_stack *stack)
{
	if (stack->args)
		ft_double_free(stack->args);
	if (stack->stack_a)
		ft_free_stack(stack->stack_a);
	if (stack->stack_b)
		ft_free_stack(stack->stack_b);
	ft_putstr_fd("Error\n", 2);
	exit (1);
}

void	ft_end_program(t_stack *stack)
{
	if (stack->stack_a)
		ft_free_stack(stack->stack_a);
	if (stack->stack_b)
		ft_free_stack(stack->stack_b);
}
