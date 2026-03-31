/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:23:18 by soyamagu          #+#    #+#             */
/*   Updated: 2026/03/31 20:37:53 by sonoe            ###   ########.fr       */
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
// # include "libft/ft_printf.h"ß

int			count_tokens(char **s, int arg_total);
long long	*make_array(char **arg_value, int arg_total);
long long	ft_atol_ps(const char *nptr);
bool		is_sign(char c);
bool		is_space(char c);
#endif
