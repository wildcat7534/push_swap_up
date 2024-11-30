/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:08:18 by cmassol           #+#    #+#             */
/*   Updated: 2024/11/30 05:47:39 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"

typedef struct s_node
{
	int				nb;
	int				index;
	struct s_node	*next;
}				t_node;
/* typedef struct s_instruct
{
	void	(*f)(t_piles *piles, int print);
}				t_instruct;

typedef struct s_piles
{
	t_node		*a;
	t_node		*b;
	t_instruct	*instruct;
}	 			t_piles;*/

typedef struct s_lst_instruct
{
	char					*instruction;
	struct s_lst_instruct	*next;
}				t_lst_instruct;

//void				w_instruct(t_instruct *instruct, t_piles *piles, int print);

void				ft_lst_instruc(t_lst_instruct **instruct, char *instruct_str);
int					get_position_in_stack(t_node **stack, int value);
t_node				*init_node(int value);
void				add_node_back(t_node **stack, t_node *new_node);
void				ft_free_split(char **split);
void				free_nodes(t_node *stack);
void				ft_error(void);
void				index_init(t_node **stack, int len);
int					stack_size(t_node **stack);
int					parse_arguments(int ac, char **av, int *numbers);
void				print_stack(t_node **stack);
int					first_half_check(t_node **b, int nb, int half_len);
t_node				*find_max_node(t_node **stack);
t_node				*find_min_node(t_node **stack);
int					make_node(t_node **stack, int ac, char **av, int *size);
void				ft_sort(t_node **a, t_node **b, t_lst_instruct **instruct);
void				ft_sort_three_node(t_node **stack_a, t_lst_instruct **instruct);
void				ft_sort_10_node(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct);
void				ft_index_sort(t_node **a, t_node **b, int start, int end, t_lst_instruct **instruct);
void				sort_next(t_node **a, t_node **b, t_lst_instruct **instruct);
int					is_sorted_node(t_node **stack);
int					get_index_node(t_node **stack, int nb);
void				delete_node(t_node **stack, t_node *node_to_delete);
void				pa(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct);
void				pb(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct);
void				sa(t_node **stack, t_lst_instruct **instruct);
void				sb(t_node **stack, t_lst_instruct **instruct);
void				ss(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct);
void				ra(t_node **stack, t_lst_instruct **instruct);
void				rb(t_node **stack, t_lst_instruct **instruct);
void				rr(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct);
void				rra(t_node **stack, t_lst_instruct **instruct);
void				rrb(t_node **stack, t_lst_instruct **instruct);
void				rrr(t_node **stack_a, t_node **stack_b, t_lst_instruct **instruct);
int					has_duplicates(int *array, int size);
void				ft_check_list(t_lst_instruct **instruct);
void				ft_print_list(t_lst_instruct **instruct);

#endif