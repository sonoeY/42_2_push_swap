/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:43:58 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/22 09:02:11 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//validation before sorting
bool	is_sorted(t_node *lst)
{
	t_node	*curr;

	curr = lst;
	while (curr->next)
	{
		if ((curr->index) > (curr->next->index))
			return (false);
		curr = curr->next;
	}
	return (true);
}

//check min index from three nodes
int	check_min(t_node *lst)
{
	t_node	*curr;
	int		min;

	curr = lst;
	min = lst->index;
	while (curr)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}

//execute the smallest index in stack_a to stack_b
void	move_to_b(t_node **stack_a, t_node **stack_b, int num)
{
	int	n;

	if (!stack_a || !*stack_a)
		return ;
	n = count_depth(*stack_a, num);
	if (n >= 0 && n <= 2)
	{
		while ((*stack_a)->index != num)
			ra(stack_a);
	}
	else if (n > 2)
	{
		while ((*stack_a)->index != num)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	return ;
}

//check the depth from top node
int	count_depth(t_node *lst, int num)
{
	t_node	*curr;
	int		n;

	if (!lst)
		return (-1);
	curr = lst;
	n = 0;
	while (curr)
	{
		if (curr->index == num)
			return (n);
		n++;
		curr = curr->next;
	}
	return (-1);
}

//check the max number of bit
int	find_bit_max(int size_a)
{
	int	n;
	int	i;

	n = (size_a - 1);
	i = 0;
	while (n >> i)
		i++;
	return (i - 1);
}
