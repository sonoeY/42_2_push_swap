/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:19:21 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/16 17:30:28 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

// void	print_index_forward(t_list *head)
// {
// 	while (head)
// 	{
// 		printf("%d\n", head->index);
// 		head = head->next;
// 	}
// 	return ;
// }

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (print_error(2));
	stack_a = parse_args(argv + 1, argc - 1, &stack_a);
	if (!stack_a)
		return (print_error(2));
	compress_data(&stack_a);
	size_a = ft_lstsize(stack_a);
	if ((ft_lstsize(stack_a) != 1) && (!is_sorted(stack_a)))
		sort_lst(&stack_a, &stack_b, size_a);
	//printf("================\n");
	//print_index_forward(stack_a);
	free_lst(&stack_a);
	return (0);
}
