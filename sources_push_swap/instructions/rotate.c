/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:40:06 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/01 03:13:00 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*change;
	t_node	*current;

	change = *stack;
	current = *stack;
	*stack = change->next;
	while (current->next != NULL)
		current = current->next;
	current->next = change;
	change->next = NULL;
}
void	ra(t_node **stack, t_lst_instruct **instruct)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate(stack);
	ft_lst_instruc(instruct, "ra");
}

void	rb(t_node **stack, t_lst_instruct **instruct)
{
	if (!*stack || !(*stack)->next)
		return ;
	rotate(stack);
	ft_lst_instruc(instruct, "rb");
}

void	rr(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct)
{
	ra(stack_a, instruct);
	rb(stack_b, instruct);
}
