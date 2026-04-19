/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:23:06 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/19 20:35:43 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char			**split_check_arg(char *arg);
static int			append_tokens(char **tokens, t_list **lst);
static void			free_tokens(char **tokens);
static void			*cleanup_error(char **tokens, t_list **lst);

t_list	*parse_args(char **args, int tokens_total, t_list **stack_a)
{
	size_t		tokens_i;
	char		**tokens;
	int			result;

	tokens_i = 0;
	while (tokens_i < (size_t)tokens_total)
	{
		tokens = split_check_arg(args[tokens_i]);
		if (!tokens)
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
	char		**tokens;

	tokens = ft_split(arg, SPACE);
	if (!tokens)
		return (NULL);
	if (!check_char_num(tokens))
	{
		free_tokens(tokens);
		return (NULL);
	}
	return (tokens);
}

static int	append_tokens(char **tokens, t_list **lst)
{
	long long	num;
	t_list		*new_node;
	size_t		i;

	i = 0;
	while(tokens[i])
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

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}


static void	*cleanup_error(char **tokens, t_list **lst)
{
	free_tokens(tokens);
	if (lst)
	free_lsts(lst);
	return (NULL);
}
