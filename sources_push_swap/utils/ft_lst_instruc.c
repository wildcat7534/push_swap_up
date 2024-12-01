/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_instruc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:43:38 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/01 04:47:52 by cmassol          ###   ########.fr       */
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
    //ft_printf("Before ft_print_list:\n");
    //ft_printf("instruct = %p\n", (void *)instruct);
    //ft_printf("new->instruction = %s\n", new->instruction);
    if (!*instruct)
    {
        *instruct = new;
        return ;
    }
    current = *instruct;
    while (current->next != NULL)
    {
            current = current->next;
    }
    current->next = new;
}
