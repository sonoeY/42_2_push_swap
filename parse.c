/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:23:06 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/16 19:01:34 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void			free_tokens(char **tokens);
static void			free_lsts_return(t_list **lst);
static void			*free_all_return(char **tokens, t_list **lst);

t_list	*parse_args(char **value, int tokens_total, t_list **stack_a)
{
	t_list		*new_node;
	size_t		tokens_i;
	char		**tokens;
	long long	num;
	size_t		j;

	tokens_i = 0;
	while (tokens_i < (size_t)tokens_total)
	{
		tokens = ft_split(value[tokens_i], ' ');
		j = 0;
		if (!tokens || !tokens[j])
			return (free_all_return(tokens, stack_a));
		while (tokens[j])
		{
			if (!is_numeric_token(tokens[j]))
				return (free_all_return(tokens, stack_a));
			num = ft_atol_ps(tokens[j]);
			if (num > INT_MAX || num < INT_MIN)
				return (free_all_return(tokens, stack_a));
			new_node = gen_node(num);
			if (!new_node)
				return (free_all_return(tokens, stack_a));
			ft_lstadd_last(stack_a, new_node);
			j++;
		}
		free_tokens(tokens);
		tokens_i++;
	}
	if (is_lst_dup(*stack_a))
		free_lsts_return(stack_a);
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

static void	free_lsts_return(t_list **lst)
{
	free_lsts(lst);
	return (NULL);
}

static void	*free_all_return(char **tokens, t_list **lst)
{
	free_tokens(tokens);
	if (lst)
		free_lsts(lst);
	return (NULL);
}
