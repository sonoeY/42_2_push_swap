/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:19:21 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/19 20:34:51 by sonoe            ###   ########.fr       */
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
//[add below to (f)main]
//printf("================\n");
//print_index_forward(stack_a);

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (escape_error(2));
	stack_a = parse_args(argv + 1, argc - 1, &stack_a);
	if (!stack_a)
		return (escape_error(2));
	compress_data(&stack_a);
	size_a = ft_lstsize(stack_a);
	if ((ft_lstsize(stack_a) != 1) && (!is_sorted(stack_a)))
		sort_lst(&stack_a, &stack_b, size_a);
	free_lsts(&stack_a);
	return (0);
}
