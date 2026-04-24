/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:19:21 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/25 05:11:36 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = parse_args((argv + 1), (size_t)(argc - 1), &stack_a);
	if (!stack_a)
		return (escape_error(2));
	compress_num(&stack_a);
	size_a = ft_lstsize(stack_a);
	if ((ft_lstsize(stack_a) != 1) && (!is_sorted(stack_a)))
		sort_lsts(&stack_a, &stack_b, size_a);
	free_lsts(&stack_a);
	return (0);
}
