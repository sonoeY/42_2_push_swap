/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:23:18 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/26 12:42:09 by soyamagu         ###   ########.fr       */
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

// parse.c, parse_helper.c
t_node				*parse_args(char **value, size_t tokens_total,
						t_node **stack_a);
int					count_tokens(char **s, int arg_total);
bool				check_char_num(char *tokens);
bool				check_dup(t_node *lst);
bool				check_overflow(const char *nptr);
t_node				*gen_node(long long num);

// operations.c, operations_helper.c
void				sa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
void				ra(t_node **stack_a, t_node **stack_b);
void				rra(t_node **stack_a, t_node **stack_b);
void				pa(t_node **stack_b, t_node **stack_a);
void				swap_node(t_node **lst);
void				push_node(t_node **src, t_node **dst);
void				rotate_up(t_node **lst);
void				rotate_down(t_node **lst);

// sort.c, sort_helper.c
void				sort_lsts(t_node **stack_a, t_node **stack_b, int size_a);
bool				is_sorted(t_node *lst);
int					check_min(t_node *lst);
int					count_depth(t_node *lst, int num);
void				move_to_b(t_node **stack_a, t_node **stack_b, int num);
int					find_bit_max(int size_a);

// utils.c
bool				is_sign(int c);
int					ft_lstsize(t_node *lst);
void				ft_lstadd_front(t_node **lst, t_node *new);
void				ft_lstadd_last(t_node **lst, t_node *new);
void				free_lsts(t_node **lst);

// compression.c, exit_error.c
void				compress_num(t_node **lst);
int					escape_error(int fd);
void				exit_error(t_node **stack_a, t_node **stack_b);

#endif
