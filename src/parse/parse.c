/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:23:06 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/24 19:53:51 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char			**split_check_arg(char *arg);
static int			append_tokens(char **tokens, t_node **lst);
static void			free_tokens(char **tokens);
static void			*cleanup_error(char **tokens, t_node **lst);

t_node	*parse_args(char **args, size_t tokens_total, t_node **stack_a)
{
	size_t		tokens_i;
	char		**tokens;
	int			result;

	if (!args)
		return (NULL);
	tokens_i = 0;
	while (tokens_i < tokens_total)
	{
		tokens = split_check_arg(args[tokens_i]);
		if (!tokens || !tokens[0])
			return (cleanup_error(tokens, stack_a));
		result = append_tokens(tokens, stack_a);
		if (result < 0)
			return (cleanup_error(tokens, stack_a));
		free_tokens(tokens);
		tokens_i++;
	}
	if (check_dup(*stack_a))
	{
		free_lsts(stack_a);
		return (NULL);
	}
	return (*stack_a);
}

static char	**split_check_arg(char *arg)
{
	char	**tokens;
	size_t	i;

	tokens = ft_split(arg, SPACE);
	if (!tokens)
		return (NULL);
	i = 0;
	while (tokens[i])
	{
		if (!check_digit(tokens[i]))
		{
			free_tokens(tokens);
			return (NULL);
		}
		i++;
	}
	return (tokens);
}

static int	append_tokens(char **tokens, t_node **lst)
{
	long long	num;
	t_node		*new_node;
	size_t		i;

	i = 0;
	while (tokens[i])
	{
		num = ft_atol_ps(tokens[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (-1);
		new_node = gen_node(num);
		if (!new_node)
			return (-1);
		ft_lstadd_last(lst, new_node);
		i++;
	}
	return (0);
}

static void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	*cleanup_error(char **tokens, t_node **lst)
{
	if (tokens)
		free_tokens(tokens);
	if (lst)
		free_lsts(lst);
	return (NULL);
}
