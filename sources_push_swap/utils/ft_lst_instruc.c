/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_instruc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:43:38 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/30 07:46:29 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_lst_instruc(t_lst_instruct **instruct, char *instruct_str)
{
    t_lst_instruct	*new;
    t_lst_instruct	*current;

    new = malloc(sizeof(t_lst_instruct));
    if (!new)
        ft_error();
    new->instruction = ft_strdup(instruct_str);
    new->next = NULL;
    ft_printf("instruct->instruction = %p\n", (*instruct)->instruction);
    if (!instruct)
    {
        instruct = &new;
        return ;
    }
    current = *instruct;
    while (current)
        current = current->next;
    if (current)
        current->next = new;
}