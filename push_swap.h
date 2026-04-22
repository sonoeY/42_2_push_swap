/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:23:18 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/22 09:00:59 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# define SPACE ' '

typedef struct s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	int				data;
	int				index;
}					t_node;

// functions for parse and validations
t_node				*parse_args(char **value, size_t tokens_total,
						t_node **stack_a);
int					count_tokens(char **s, int arg_total);
bool				check_char_num(char *tokens);
bool				check_dup(t_node *lst);
long long			ft_atol_ps(const char *nptr);
t_node				*gen_node(long long num);

// functions define sort rules
void				sa(t_node **stack_a);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a);
void				rra(t_node **stack_a);
void				pa(t_node **stack_b, t_node **stack_a);
void				swap_node(t_node **lst);
void				push_node(t_node **lst_from, t_node **lst_to);
void				rotate_up(t_node **lst);
void				rotate_down(t_node **lst);

// functions help sorting
void				sort_lsts(t_node **stack_a, t_node **stack_b, int size_a);
bool				is_sorted(t_node *lst);
int					check_min(t_node *lst);
int					count_depth(t_node *lst, int num);
void				move_to_b(t_node **stack_a, t_node **stack_b, int num);
int					find_bit_max(int size_a);

// utils
bool				is_sign(char c);
int					ft_lstsize(t_node *lst);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_last(t_node **lst, t_node *new);
void				free_lsts(t_node **lst);

// functions assist main
void				compress_data(t_node **lst);
int					escape_error(int fd);

#endif
