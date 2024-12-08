/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:49:27 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 18:46:08 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	ft_index_sort(t_node **a, t_node **b, int end, t_lst_instruct **ist)
{
	int	start;

	start = 0;
	index_init(a, stack_size((a)));
	while (*a)
	{
		if ((*a)->index <= (start))
		{
			pb(a, b, ist);
			rb(b, ist);
			(start)++;
			(end)++;
		}
		else if ((*a)->index > (start) && (*a)->index < (end))
		{
			pb(a, b, ist);
			(start)++;
			(end)++;
		}
		else if ((*a)->index >= (end))
			ra(a, ist);
	}
	sort_next(a, b, ist);
}

void	sort_next(t_node **a, t_node **b, t_lst_instruct **instruct)
{
	int		half;
	t_node	*checkpoint;

	checkpoint = NULL;
	while (*b)
	{
		checkpoint = find_max_node(b);
		half = first_half_check(b, checkpoint->nb, (stack_size(b) / 2));
		while ((*b)->nb != checkpoint->nb)
		{
			if (half == 1)
				rb(b, instruct);
			else
				rrb(b, instruct);
		}
		pa(a, b, instruct);
	}
}

int	first_half_check(t_node **b, int nb, int half_len)
{
	t_node	*current;

	current = *b;
	while (half_len > 0 && current)
	{
		if (current->nb == nb)
		{
			return (1);
		}
		current = current->next;
		half_len--;
	}
	return (0);
}

t_node	*find_max_node(t_node **stack)
{
	int		max;
	t_node	*max_nbr;
	t_node	*current;

	max = INT_MIN;
	max_nbr = NULL;
	current = *stack;
	while (current != NULL)
	{
		if (current->nb > max)
		{
			max_nbr = current;
			max = current->nb;
		}
		current = current->next;
	}
	return (max_nbr);
}
