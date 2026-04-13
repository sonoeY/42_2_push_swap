/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:19:21 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/13 20:47:04 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// tmp
void	print_forward(t_list *head)
{
	while (head)
	{
		printf("%d\n", head->index);
		head = head->next;
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	// int			num_len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (exit_error(2));
	// num_len = count_tokens(argv + 1, argc - 1);
	// printf("%d\n", num_len);
	stack_a = parse_args(argv + 1, argc - 1, &stack_a);
	if (!stack_a)
		return (exit_error(2));
	compress_data(&stack_a);
	if (ft_lstsize(stack_a) == 1 || is_sorted(stack_a))
	{
		free_lst(&stack_a);
		return (0);
	}
	// sort(nums) & print used operations;
	printf("a===\n");
	print_forward(stack_a);
	printf("b===\n");
	print_forward(stack_b);
	free_lst(&stack_a);
	return (0);
}
