/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:23:18 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/13 15:41:18 by soyamagu         ###   ########.fr       */
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

typedef struct s_list
{
	struct s_list	*pre;
	int				data;
	struct s_list	*next;
}					t_list;

t_list				*parse_args(char **arg_value, int arg_total,
						t_list **stack_a);
int					count_tokens(char **s, int arg_total);
bool				is_numeric_token(char *tokens);
bool				is_dup(t_list *lst);
t_list				*gen_node(long long num);

void				swap_node(t_list **lst);
void				push_node(t_list **lst_from, t_list **lst_to);
void				rotate_up(t_list **lst);
void				rotate_down(t_list **lst);

void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				pa(t_list **stack_b, t_list **stack_a);
void				pb(t_list **stack_a, t_list **stack_b);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);

bool				is_sign(char c);
bool				is_space(char c);
long long			ft_atol_ps(const char *nptr);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				free_lst(t_list **lst);
int					exit_error(int fd);

#endif
