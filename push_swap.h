/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:23:18 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/16 19:01:08 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "42_0_libft/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
// # include "libft/source_libft/libft.h"
// # include "libft/ft_printf.h"

# define BIT_MAX 9
# define SPACE ' '

typedef struct s_list
{
	struct s_list	*pre;
	struct s_list	*next;
	int				data;
	int				index;
}					t_list;

t_list				*parse_args(char **value, int tokens_total,
						t_list **stack_a);
int					count_tokens(char **s, int arg_total);
bool				is_numeric_token(char *tokens);
bool				is_lst_dup(t_list *lst);
long long			ft_atol_ps(const char *nptr);
t_list				*gen_node(long long num);

void				compress_data(t_list **lst);

void				sa(t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rra(t_list **stack_a);
void				pa(t_list **stack_b, t_list **stack_a);
void				swap_node(t_list **lst);
void				push_node(t_list **lst_from, t_list **lst_to);
void				rotate_up(t_list **lst);
void				rotate_down(t_list **lst);

void				sort_lst(t_list **stack_a, t_list **stack_b, int size_a);
void				sort_three(t_list **lst);
void				sort_four(t_list **stack_a, t_list **stack_b);
void				sort_five(t_list **stack_a, t_list **stack_b);
void				sort_radix(t_list **stack_a, t_list **stack_b,
						int size_a);
bool				is_sorted(t_list *lst);
int					check_min(t_list *lst);
int					count_depth(t_list *lst, int num);
void				execute_num(t_list **stack_a, t_list **stack_b, int num);
int					find_bit_max(t_list *lst);

bool				is_sign(char c);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_last(t_list **lst, t_list *new);
void				free_lsts(t_list **lst);
int					print_error(int fd);

#endif
