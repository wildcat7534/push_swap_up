/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:59:57 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 18:51:31 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_node			*a;
	t_node			*b;
	t_lst_instruct	*ist;
	int				size;

	init_start(&a, &b, &ist);
	if (ac < 2)
		return (1);
	if (make_node(&a, ac, av, &size))
		return (free_nodes(a), (write(2, "Error\n", 6)), 1);
	if (is_sorted_node(&a))
		return (free_nodes(a), 0);
	ft_sort(&a, &b, &ist);
	ft_check_list(&ist);
	ft_print_list(&ist);
	free_nodes(a);
	free_nodes(b);
	return (0);
}
