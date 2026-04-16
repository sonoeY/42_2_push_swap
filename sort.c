/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:31:00 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/16 17:29:30 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

void	sort_three(t_list **lst);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_radix(t_list **stack_a, t_list **stack_b, int size_a);

void	sort_lst(t_list **stack_a, t_list **stack_b, int size_a)
{
	if (!stack_a || !*stack_a || (!stack_a && !stack_b))
		return ;
	if (size_a == 2)
		sa(stack_a);
	else if (size_a == 3)
		sort_three(stack_a);
	else if (size_a == 4)
		sort_four(stack_a, stack_b);
	else if (size_a == 5)
		sort_five(stack_a, stack_b);
	if (size_a >= 6)
		sort_radix(stack_a, stack_b, size_a);
	return ;
}

void	sort_three(t_list **lst)
{
	int	min;
	int	mid;

	if (!lst || !(*lst)->next || !(*lst)->next->next)
		return ;
	min = check_min(*lst);
	mid = min + 1;
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

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	int	min;

	if (!stack_a || !*stack_a)
		return ;
	min = check_min(*stack_a);
	execute_num(stack_a, stack_b, min);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	pa(stack_b, stack_a);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	min;
	int	mid;

	if (!stack_a || !*stack_a)
		return ;
	min = check_min(*stack_a);
	mid = min + 1;
	execute_num(stack_a, stack_b, min);
	execute_num(stack_a, stack_b, mid);
	if (!is_sorted(*stack_a))
		sort_three(stack_a);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

void	sort_radix(t_list **stack_a, t_list **stack_b, int size_a)
{
	int	max;
	int	i;
	int	size_b;

	max = find_bit_max(*stack_a);
	i = 0;
	while (i <= max)
	{
		while (size_a > 0)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			size_a--;
		}
		size_b = ft_lstsize(*stack_b);
		while (size_b > 0)
		{
			pa(stack_b, stack_a);
			size_b--;
		}
		size_a = ft_lstsize(*stack_a);
		i++;
	}
}
