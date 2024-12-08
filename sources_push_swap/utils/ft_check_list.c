/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 04:15:50 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 18:41:45 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_check_list_rb(t_lst_instruct **instruct);
static void	ft_check_list_rra(t_lst_instruct **instruct);
static void	ft_check_list_rrb(t_lst_instruct **instruct);

void	ft_check_list(t_lst_instruct **instruct)
{
	t_lst_instruct	*current;
	t_lst_instruct	*next;

	current = *instruct;
	while (current && current->next)
	{
		next = current->next;
		if (!ft_strcmp(current->instruction, "ra")
			&& !ft_strcmp(next->instruction, "rb"))
		{
			free(current->instruction);
			current->instruction = ft_strdup("rr");
			free(next->instruction);
			current->next = next->next;
			free(next);
			current = *instruct;
		}
		else
			current = current->next;
	}
	ft_check_list_rb(instruct);
}

static void	ft_check_list_rb(t_lst_instruct **instruct)
{
	t_lst_instruct	*current;
	t_lst_instruct	*next;

	current = *instruct;
	while (current && current->next)
	{
		next = current->next;
		if (!ft_strcmp(current->instruction, "rb")
			&& !ft_strcmp(next->instruction, "ra"))
		{
			free(current->instruction);
			current->instruction = ft_strdup("rr");
			free(next->instruction);
			current->next = next->next;
			free(next);
			current = *instruct;
		}
		else
			current = current->next;
	}
	ft_check_list_rra(instruct);
}

static void	ft_check_list_rra(t_lst_instruct **instruct)
{
	t_lst_instruct	*current;
	t_lst_instruct	*next;

	current = *instruct;
	while (current && current->next)
	{
		next = current->next;
		if (!ft_strcmp(current->instruction, "rra")
			&& !ft_strcmp(next->instruction, "rrb"))
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
	ft_check_list_rrb(instruct);
}

static void	ft_check_list_rrb(t_lst_instruct **instruct)
{
	t_lst_instruct	*current;
	t_lst_instruct	*next;

	current = *instruct;
	while (current && current->next)
	{
		next = current->next;
		if (!ft_strcmp(current->instruction, "rrb")
			&& !ft_strcmp(next->instruction, "rra"))
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
