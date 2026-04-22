/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:55:02 by sonoe             #+#    #+#             */
/*   Updated: 2026/04/22 08:44:02 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a)
{
	swap_node(stack_a);
	write(1, "sa\n", 3);
	return ;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push_node(stack_b, stack_a);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push_node(stack_a, stack_b);
	write(1, "pb\n", 3);
	return ;
}

void	ra(t_node **stack_a)
{
	rotate_up(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	rra(t_node **stack_a)
{
	rotate_down(stack_a);
	write(1, "rra\n", 4);
	return ;
}

