/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:15:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/01 03:12:53 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

// create list of intstrution to sort the stack
// if instruct ra and rb are in front of each other, replace them by rr
// if instruct rra and rrb are in front of each other, replace them by rrr

void	ft_check_list(t_lst_instruct **instruct)
{
    t_lst_instruct	*current;
    t_lst_instruct	*next;

    current = *instruct;
    while (current && current->next)
    {
        next = current->next;
        if (!ft_strcmp(current->instruction, "ra") && !ft_strcmp(next->instruction, "rb"))
        {
            free(current->instruction);
            current->instruction = ft_strdup("rr");
            free(next->instruction);
            current->next = next->next;
            free(next);
            current = *instruct;
        }
        else if (!ft_strcmp(current->instruction, "rb") && !ft_strcmp(next->instruction, "ra"))
        {
            free(current->instruction);
            current->instruction = ft_strdup("rr");
            free(next->instruction);
            current->next = next->next;
            free(next);
            current = *instruct;
        }
        else if (!ft_strcmp(current->instruction, "rra") && !ft_strcmp(next->instruction, "rrb"))
        {
            free(current->instruction);
            current->instruction = ft_strdup("rrr");
            free(next->instruction);
            current->next = next->next;
            free(next);
            current = *instruct;
        }
        else if (!ft_strcmp(current->instruction, "rrb") && !ft_strcmp(next->instruction, "rra"))
        {
            free(current->instruction);
            current->instruction = ft_strdup("rrr");
            free(next->instruction);
            current->next = next->next;
            free(next);
            current = *instruct;
        }
        else
            current = current->next;
    }
}


