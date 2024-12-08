/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:54:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 18:42:35 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_print_list(t_lst_instruct **instruct)
{
	t_lst_instruct	*current;

	current = *instruct;
	while (current)
	{
		ft_printf("%s\n", current->instruction);
		current = current->next;
	}
	free_lst_instruct(*instruct);
}
