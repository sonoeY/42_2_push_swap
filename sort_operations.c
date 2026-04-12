/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 21:55:02 by sonoe             #+#    #+#             */
/*   Updated: 2026/04/12 22:19:08 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	swap_node(stack_a);
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_list **stack_b)
{
	swap_node(stack_b);
	write(1, "sb\n", 3);
	return ;
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	push_node(stack_b, stack_a);
	write(1, "pa\n", 3);
	return ;
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push_node(stack_a, stack_b);
	write(1, "pb\n", 3);
	return ;
}

void	ra(t_list **stack_a)
{
	rotate_up(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_list **stack_b)
{
	rotate_up(stack_b);
	write(1, "rb\n", 3);
	return ;
}
