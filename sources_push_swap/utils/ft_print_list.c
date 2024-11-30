/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:54:28 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/30 07:43:57 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void    ft_free_list(t_lst_instruct **instruct)
{
    t_lst_instruct	*current;
    t_lst_instruct	*next;

    current = *instruct;
    while (current)
    {
        next = current->next;
        free(current->instruction);
        free(current);
        current = next;
    }
    *instruct = NULL;
}

void	ft_print_list(t_lst_instruct **instruct)
{
    t_lst_instruct	*current;

    current = *instruct;
    ft_printf("test\n");
    ft_printf("instruct = %p\n", instruct);
    ft_printf("current = %p\n", current);
    while (current)
    {
        //ft_printf("%s\n", current->instruction);
        ft_printf("test print\n");
        ft_printf("%s\n", current->instruction);
        current = current->next;
    }
    ft_free_list(instruct);
}
