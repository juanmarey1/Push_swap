/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrey-roj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:16:54 by jrey-roj          #+#    #+#             */
/*   Updated: 2024/08/26 15:16:56 by jrey-roj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	find_closest_number_to_b(int num_b, t_list *list_a)
{
	int	min_diff;
	int	num_diff;
	int	diff;

	while (num_b > (list_a->content))
		list_a = list_a->next;
	num_diff = (list_a->content);
	min_diff = list_a->content - num_b;
	while (list_a != NULL)
	{
		if (num_b < (list_a->content))
		{
			diff = list_a->content - num_b;
			if (diff < min_diff)
			{
				num_diff = (list_a->content);
				min_diff = diff;
			}
		}
		list_a = list_a->next;
	}
	return (num_diff);
}

int	find_smaller_a_num(t_list *lista)
{
	int	smaller_num;

	if (lista->content < lista->next->content)
		smaller_num = (lista->content);
	else
		smaller_num = (lista->next->content);
	lista = lista->next;
	while (lista->next != NULL)
	{
		if (smaller_num > lista->next->content)
			smaller_num = (lista->next->content);
		lista = lista->next;
	}
	return (smaller_num);
}

int	find_closest_num_back(int num_b, t_list *list_a)
{
	t_list	*copy_list_a;
	int		num_a;

	copy_list_a = list_a;
	while (list_a->next != NULL)
	{
		if (num_b > (list_a->content))
			list_a = list_a->next;
		else
			break ;
		if (list_a->next == NULL)
		{
			if (num_b > (list_a->content))
			{
				num_a = find_smaller_a_num(copy_list_a);
				return (num_a);
			}
		}
	}
	num_a = find_closest_number_to_b(num_b, copy_list_a);
	return (num_a);
}

void	back_to_a(t_stack *stack)
{
	t_list	*list_a;
	t_list	*list_b;
	int		number_a;
	int		i;

	list_a = *stack->stack_a;
	list_b = *stack->stack_b;
	number_a = find_closest_num_back(list_b->content, list_a);
	i = 1;
	while (list_a->content != number_a)
	{
		i++;
		list_a = list_a->next;
	}
	optimal_b_to_a(stack, i);
	push_back_to_a(stack);
}
