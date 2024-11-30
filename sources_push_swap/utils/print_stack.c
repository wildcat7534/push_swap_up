/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:54:42 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/06 04:13:44 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	print_stack(t_node **stack_a)
{
	t_node	*current;

	current = *stack_a;
	while (current)
	{
		ft_printf("Stack num: %d index : %d \n", current->nb, current->index);
		current = current->next;
	}
}
