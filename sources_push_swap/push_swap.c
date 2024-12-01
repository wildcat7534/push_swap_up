/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/01 03:15:03 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_lst_instruct	*instruct = NULL;
	int		size;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (make_node(&a, ac, av, &size))
		return (free_nodes(a), (write(2, "Error\n", 6)), 1);
	if (is_sorted_node(&a))
		return (free_nodes(a), 0);
	ft_sort(&a, &b, &instruct);
	ft_check_list(&instruct);
	ft_print_list(&instruct);
	free_nodes(a);
	free_nodes(b);
	return (0);
}
