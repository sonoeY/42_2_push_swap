/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:43:58 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/16 14:58:50 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sorted(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr->next)
	{
		if ((curr->index) > (curr->next->index))
			return (false);
		curr = curr->next;
	}
	return (true);
}

int	check_min(t_list *lst)
{
	t_list	*curr;
	int		min;

	curr = lst;
	min = 0;
	while (curr)
	{
		if (curr->index < min)
			min = curr->index;
		curr = curr->next;
	}
	return (min);
}

int	count_depth(t_list *lst, int num)
{
	t_list	*curr;
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

void	execute_num(t_list **stack_a, t_list **stack_b, int num)
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
