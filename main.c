/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 05:19:21 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/12 21:46:32 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

//tmp
void print_forward(t_list *head)
{
    while (head)
    {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int	main(int argc, char **argv)
{
	// int			num_len;
	t_list		*stack_a = NULL;
	//t_list		*stack_b = NULL;

	if (argc < 2)
		return (exit_error(2));
	// num_len = count_tokens(argv + 1, argc - 1);
	// printf("%d\n", num_len);
	stack_a = parse_args(argv + 1, argc - 1, &stack_a);
	if (!stack_a)
		return (exit_error(2));
	//push_node(&stack_a, &stack_b);
	//swap_node(&stack_a);
	//rotate_up(&stack_a);
	rotate_down(&stack_a);
	printf("a===\n");
	print_forward(stack_a);
	// printf("b===\n");
	// print_forward(stack_b);

	// sort(nums) & print used operations; //write(1, operations, sizeof(len));
	return (0);
}
