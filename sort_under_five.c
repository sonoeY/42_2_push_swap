/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 22:07:37 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/15 22:16:42 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//need to identify (f)find_min
void	sort_three(t_list **lst)
{
	int	min;
	int	mid;

	if (!lst || !(*lst)->next || !(*lst)->next->next)
		return ;
	min = find_min(*lst);
	mid = min++;
	if ((*lst)->index == min)
	{
		sa(lst);
		ra(lst);
	}
	else if (((*lst)->index == mid) && ((*lst)->next->index == min))
		sa(lst);
	else if (((*lst)->index == mid) && ((*lst)->next->index != min))
		rra(lst);
	else if (((*lst)->index > mid) && ((*lst)->next->index == min))
		ra(lst);
	else if (((*lst)->index > mid) && ((*lst)->next->index != min))
	{
		sa(lst);
		rra(lst);
	}
	return ;
}

//need to identify (f)find_min
void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (!stack_a)
		return ;
	min = find_min(*stack_a);
	execute_num(stack_a, stack_b, min);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	mid;

	if (!stack_a)
		return ;
	min = find_min(*stack_a);
	mid = min++;
	execute_num(stack_a, stack_b, min);
	execute_num(stack_a, stack_b, mid);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

// helper
static void	execute_num(t_list **stack_a, t_list **stack_b, int num)
{
	int	n;

	if (!stack_a)
		return ;
	n = count_depth(*stack_a, num);
	if (n >= 0 && n <= 2)
	{
		while ((*stack_a)->index == num)
			ra(stack_a);
	}
	else if (n > 2)
	{
		while ((*stack_a)->index == num)
			rra(stack_a);
	}
	return ;
}

static int	count_depth(t_list *lst, int num)
{
	t_list	*curr;
	int		n;

	if (!lst)
		return ;
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
