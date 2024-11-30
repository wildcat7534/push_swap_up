/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_10_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:22:40 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/30 05:33:27 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_sort_10_node(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct)
{
	t_node	*min_node;
	int		min;

	while (stack_size(stack_a) > 3)
	{
		min_node = find_min_node(stack_a);
		min = min_node->nb;
		while ((*stack_a)->nb != min)
		{
			if (get_position_in_stack(stack_a, min) <= stack_size(stack_a) / 2)
				ra(stack_a, instruct);
			else
				rra(stack_a, instruct);
		}
		pb(stack_a, stack_b, instruct);
	}
	ft_sort_three_node(stack_a, instruct);
	while (stack_size(stack_b) > 0)
		pa(stack_a, stack_b, instruct);
}

int	get_position_in_stack(t_node **stack, int value)
{
	t_node	*current;
	int		position;

	position = 0;
	current = *stack;
	while (current && current->nb != value)
	{
		position++;
		current = current->next;
	}
	return (position);
}

t_node	*find_min_node(t_node **stack)
{
	int		min;
	t_node	*min_nbr;
	t_node	*current;

	min = INT_MAX;
	min_nbr = NULL;
	current = *stack;
	while (current != NULL)
	{
		if (current->nb < min)
		{
			min_nbr = current;
			min = current->nb;
		}
		current = current->next;
	}
	return (min_nbr);
}

int	get_index_node(t_node **stack, int nb)
{
	int		index;
	t_node	*current;

	index = 0;
	current = *stack;
	while (current->nb != nb)
	{
		index++;
		current = current->next;
	}
	return (index);
}
