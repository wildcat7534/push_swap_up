/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:13:08 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/01 04:47:25 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker_bonus.h"

void	ft_error_bonus(char *line)
{
	free(line);
	write(2, "Error\n", 6);
	exit(1);
}

void	execute_command(char *line, t_node **a, t_node **b, t_lst_instruct **instruct_bonus)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sa(a, instruct_bonus);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(b, instruct_bonus);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b, instruct_bonus);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(a, b, instruct_bonus);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(a, b, instruct_bonus);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(a, instruct_bonus);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(b, instruct_bonus);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b, instruct_bonus);
	else if (ft_strcmp(line, "rra\n") == 0)
		rra(a, instruct_bonus);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(b, instruct_bonus);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b, instruct_bonus);
	else
		ft_error_bonus(line);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	t_lst_instruct	*instruct_bonus = NULL;
	int		size;
	char	*line;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (1);
	if (make_node(&a, ac, av, &size))
		return ((write(2, "Error\n", 6)), 1);
	line = get_next_line(0);
	while (line)
	{
		execute_command(line, &a, &b, &instruct_bonus);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted_node(&a) && stack_size(&b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_nodes(a);
	free_nodes(b);
	return (0);
}
