/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:42:29 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 18:49:02 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*current;
	t_node	*first;

	first = *stack;
	current = *stack;
	while (current->next->next != NULL)
		current = current->next;
	*stack = current->next;
	current->next->next = first;
	current->next = NULL;
}

void	rra(t_node **stack, t_lst_instruct **instruct)
{
	if (!*stack || !(*stack)->next)
		return ;
	rev_rotate(stack);
	ft_lst_instruc(instruct, "rra");
}

void	rrb(t_node **stack, t_lst_instruct **instruct)
{
	if (!*stack || !(*stack)->next)
		return ;
	rev_rotate(stack);
	ft_lst_instruc(instruct, "rrb");
}

void	rrr(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct)
{
	rra(stack_a, instruct);
	rrb(stack_b, instruct);
}
