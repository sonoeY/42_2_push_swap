/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:23:18 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/08 17:04:52 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include "42_0_libft/libft.h"
// # include "libft/source_libft/libft.h"
// # include "libft/ft_printf.h"

typedef struct	s_list
{
    struct s_list	*pre;
    int				data;
    struct s_list	*next;
}					t_list;

t_list      *parse_args(char **arg_value, int arg_total, t_list **stack_a);
int			count_tokens(char **s, int arg_total);
bool		is_numeric_token(char *tokens);
bool		is_dup(t_list *lst);
t_list		*gen_node(long long num);
void		ft_lstadd_last(t_list **lst, t_list *new);

bool		is_sign(char c);
bool		is_space(char c);
long long	ft_atol_ps(const char *nptr);
int	        exit_error(int fd);

#endif
