/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:41:04 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/30 05:31:08 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	swap(t_node	**stack)
{
	t_node	*first;
	t_node	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack, t_lst_instruct **instruct)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap(stack);
	ft_lst_instruc(instruct, "sa");
}

void	sb(t_node **stack, t_lst_instruct **instruct)
{
	if (!*stack || !(*stack)->next)
		return ;
	swap(stack);
	ft_lst_instruc(instruct, "sb");
}

void	ss(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct)
{
	sa(stack_a, instruct);
	sb(stack_b, instruct);
}

