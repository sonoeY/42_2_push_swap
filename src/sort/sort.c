/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:31:00 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/26 12:37:08 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_node **stack_a, t_node **stack_b);
static void	sort_four(t_node **stack_a, t_node **stack_b);
static void	sort_five(t_node **stack_a, t_node **stack_b);
static void	sort_radix(t_node **stack_a, t_node **stack_b, int size_a);

void	sort_lsts(t_node **stack_a, t_node **stack_b, int size_a)
{
	if (!stack_a || !*stack_a)
		return ;
	if (size_a == 2)
		sa(stack_a, stack_b);
	else if (size_a == 3)
		sort_three(stack_a, stack_b);
	else if (size_a == 4)
		sort_four(stack_a, stack_b);
	else if (size_a == 5)
		sort_five(stack_a, stack_b);
	else if (size_a >= 6)
		sort_radix(stack_a, stack_b, size_a);
}

static void	sort_three(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	mid;

	if (!stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	min = check_min(*stack_a);
	mid = min + 1;
	if ((*stack_a)->index == min)
	{
		sa(stack_a, stack_b);
		ra(stack_a, stack_b);
	}
	else if (((*stack_a)->index == mid) && ((*stack_a)->next->index == min))
		sa(stack_a, stack_b);
	else if (((*stack_a)->index == mid) && ((*stack_a)->next->index != min))
		rra(stack_a, stack_b);
	else if (((*stack_a)->index > mid) && ((*stack_a)->next->index == min))
		ra(stack_a, stack_b);
	else if (((*stack_a)->index > mid) && ((*stack_a)->next->index != min))
	{
		sa(stack_a, stack_b);
		rra(stack_a, stack_b);
	}
}

static void	sort_four(t_node **stack_a, t_node **stack_b)
{
	int	min;

	if (!stack_a || !*stack_a)
		return ;
	min = check_min(*stack_a);
	move_to_b(stack_a, stack_b, min);
	if (!is_sorted(*stack_a))
		sort_three(stack_a, stack_b);
	pa(stack_b, stack_a);
}

static void	sort_five(t_node **stack_a, t_node **stack_b)
{
	int	min;
	int	mid;

	if (!stack_a || !*stack_a)
		return ;
	min = check_min(*stack_a);
	mid = min + 1;
	move_to_b(stack_a, stack_b, min);
	move_to_b(stack_a, stack_b, mid);
	if (!is_sorted(*stack_a))
		sort_three(stack_a, stack_b);
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}

static void	sort_radix(t_node **stack_a, t_node **stack_b, int size_a)
{
	int	max;
	int	i;
	int	size_b;

	max = find_bit_max(size_a);
	i = 0;
	while (i <= max)
	{
		while (size_a > 0)
		{
			if (((*stack_a)->index >> i & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a, stack_b);
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
