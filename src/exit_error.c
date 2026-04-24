/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 19:03:16 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/24 22:50:08 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	escape_error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}

void	exit_error(t_node **stack_a, t_node **stack_b)
{
	if (stack_a)
		free_lsts(stack_a);
	if (stack_b)
		free_lsts(stack_b);
	exit (1);
}
