/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:55:02 by sonoe             #+#    #+#             */
/*   Updated: 2026/04/24 23:10:55 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a, t_node **stack_b)
{
	int	ret;

	swap_node(stack_a);
	ret = write(1, "sa\n", 3);
	if (ret < 0)
		exit_error(stack_a, stack_b);
	return ;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	int	ret;

	push_node(stack_b, stack_a);
	ret = write(1, "pa\n", 3);
	if (ret < 0)
		exit_error(stack_a, stack_b);
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	int	ret;

	push_node(stack_a, stack_b);
	ret = write(1, "pb\n", 3);
	if (ret < 0)
		exit_error(stack_a, stack_b);
	return ;
}

void	ra(t_node **stack_a, t_node **stack_b)
{
	int	ret;

	rotate_up(stack_a);
	ret = write(1, "ra\n", 3);
	if (ret < 0)
		exit_error(stack_a, stack_b);
	return ;
}

void	rra(t_node **stack_a, t_node **stack_b)
{
	int	ret;

	rotate_down(stack_a);
	ret = write(1, "rra\n", 4);
	if (ret < 0)
		exit_error(stack_a, stack_b);
	return ;
}
