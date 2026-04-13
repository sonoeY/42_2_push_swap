/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:23:06 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/13 15:38:27 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_tokens(char **tokens);
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
			ft_lstadd_front(stack_a, new_node);
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

static void	*free_all(char **tokens, t_list **lst)
{
	free_tokens(tokens);
	if (lst)
		free_lst(lst);
	return (NULL);
}
