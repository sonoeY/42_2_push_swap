/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:23:06 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/08 16:12:44 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	free_tokens(char **tokens);
static void	free_lst(t_list **lst);
static void	*free_all(char **tokens, t_list **lst);

t_list	*parse_args(char **arg_value, int arg_total, t_list **stack_a)
{
	t_list		*new_node;
	size_t		tokens_i;
	char		**tokens;
	long long	num;
	size_t		j;

	tokens_i = 0;
	while (tokens_i < (size_t)arg_total)
	{
		tokens = ft_split(arg_value[tokens_i], ' ');
		j = 0;
		if (!tokens || !tokens[j])
			return (free_all(tokens, stack_a));
		while (tokens[j])
		{
			if (!is_numeric_token(tokens[j]))
				return (free_all(tokens, stack_a));
			num = atol(tokens[j]);
			if (num > INT_MAX || num < INT_MIN)
				return (free_all(tokens, stack_a));
			new_node = gen_node(num);
			if (!new_node)
				return (free_all(tokens, stack_a));
			ft_lstadd_last(stack_a, new_node);
			j++;
		}
		free_tokens(tokens);
		tokens_i++;
	}
	if (is_dup(*stack_a))
	{
		free_lst(stack_a);
		return (NULL);
	}
	return (*stack_a);
}

//tmp
void print_forward(t_list *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int	main(int argc, char **argv)
{
	int			num_len;
	t_list		*stack_a = NULL;

	if (argc < 2)
	{
		printf("arg error\n");
		return (1);
	}
	else
	{
		num_len = count_tokens(argv + 1, argc - 1);
		printf("%d\n", num_len);
		stack_a = parse_args(argv + 1, argc - 1, &stack_a);
		if (!stack_a)
		{
			printf("parse error\n");
			return (1);
		}
		print_forward(stack_a);
		printf("ok\n");
	}
	return (0);
}

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	free_lst(t_list **lst)
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	while (curr)
	{
		next = curr-> next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

static void	*free_all(char **tokens, t_list **lst)
{
	free_tokens(tokens);
	if (lst)
		free_lst(lst);
	return (NULL);
}
