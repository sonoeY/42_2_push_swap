/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 20:31:00 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/15 22:11:03 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_lst(t_list **stack_a, t_list **stack_b, int size_a)
{
	if (!stack_a || (!stack_a && !stack_b))
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
		sort_radix(stack_a, stack_b);
	return ;
}

// void	ft_radix_sort(t_list **stack_a, t_list **stack_b)
// {
// 	max = bit桁
// 	i = 0;
// 	j = 0;
// 	c = 0;
// 	size_a = ft_lst_size(stack_a);

// while (i < max)
// {
// 	c = 0;

// 	while (c < size_a)
// 	{
// 		if (((*stack_a)->data >> i) & 1)
// 			ra;
// 		else
// 			pb;
// 		c++;
// 	}

// 	j = 0;
// 	while (j < size_b)
// 	{
// 		pa;
// 		j++;
// 	}

// 	size_a = ft_lst_size(stack_a);
// 	size_b = ft_lst_size(stack_b);
// 	i++;
// }
// }
