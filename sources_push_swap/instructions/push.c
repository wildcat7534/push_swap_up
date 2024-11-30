/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:38:32 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/30 07:05:28 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	push(t_node **stack_out, t_node **stack_in)
{
	t_node	*change;

	change = *stack_out;
	*stack_out = change->next;
	change->next = *stack_in;
	*stack_in = change;
}

void	pa(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct)
{
	if (!*stack_b)
		return ;
	push(stack_b, stack_a);
	ft_lst_instruc(instruct, "pa");
}

void	pb(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct)
{
	if (!*stack_a)
		return ;
	push(stack_a, stack_b);
	ft_lst_instruc(instruct, "pb");
}
