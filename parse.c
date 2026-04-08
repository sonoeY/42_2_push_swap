/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 20:23:06 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/08 14:31:56 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

bool	is_numeric_token(char *tokens);
bool	is_dup(long long *nums, size_t n);
static void	free_tokens(char **tokens);
static void	*free_return(long long *nums);
static void	*free_all(char **tokens, long long *nums);

/*t_list	*gen_node(long long num)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = (int)num;
	new->pre = NULL;
	new ->next = NULL;
	return (new);
}

void	ft_lstadd_last(t_list **stack_a, t_list *new)
{
	t_list *curr = *stack_a;

	if (!*stack_a)
		*stack_a = new;
	else
	{
		while (curr -> next)
			curr = curr-> next;
		curr->next = new;
		new->pre = curr;
		new->next = NULL;
	}
}

t_list	**parse_args(char **arg_value, int arg_total, t_list **stack_a) //receive stack_a as a param
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
				return (free_all(tokens)); //stack_aはmainでfree;
			num = atol(tokens[j]);
			if (num > INT_MAX || num < INT_MIN)
				return (free_all(tokens));
			new_node = gen_node(num);
			if (!new_node)
				return (free_all(tokens));
			ft_lstadd_last(stack_a, new_node);
			free (new_node);
			j++;
		}
		free_tokens(tokens);
		tokens_i++;
	}
	if (is_dup(stack_a, lst_size)) //lstの数を他関数で計算、その分だけカウント回す
		return (free_return(stack_a));
	return (stack_a);
}

int	main(int argc, char **argv)
{
	int			num_len;
	long long	*num;
	int			num_i = 0;

	if (argc < 2)
	{
		printf("arg error\n");
		return (1);
	}
	else
	{
		num_len = count_tokens(argv + 1, argc - 1);
		printf("%d\n", num_len);
		num = parse_args(argv + 1, argc - 1);
		if (!num)
		{
			printf("parse error\n");
			free(num);
			return (1);
		}
		while (num_i < num_len)
		{
			printf("num[%d]: %lld\n", num_i, num[num_i]);
			num_i++;
		}
		printf("ok\n");
	}
	free(num);
	return (0);
}*/

bool	is_numeric_token(char *tokens)
{
	size_t	i;

	i = 0;
	if (!tokens || !tokens[i])
		return (false);
	while (tokens[i])
	{
		if ((i == 0 && is_sign(tokens[i]))
						&& !ft_isdigit(tokens[i + 1]))
				return (false);
			else if (!(is_sign(tokens[i]) || ft_isdigit(tokens[i])))
				return (false);
		i++;
	}
	return (true);
}


bool	is_dup(long long *nums, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (nums[i] == nums[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
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

static void	*free_return(long long *nums)
{
	free (nums);
	return (NULL);
}

static void	*free_all(char **tokens, long long *nums)
{
	free_tokens(tokens);
	return (free_return(nums));
}


long long	*parse_args(char **arg_value, int arg_total)
{
	long long	*nums;
	size_t		tokens_i;
	char		**tokens;
	size_t		num_i;
	size_t		j;

	nums = make_array(arg_value, arg_total);
	if (!nums)
		return (NULL);
	tokens_i = 0;
	num_i = 0;
	while (tokens_i < (size_t)arg_total)
	{
		tokens = ft_split(arg_value[tokens_i], ' ');
		j = 0;
		if (!tokens || !tokens[j])
			return (free_all(tokens, nums));
		while (tokens[j])
		{
			if (!is_numeric_token(tokens[j]))
				return (free_all(tokens, nums));
			nums[num_i] = atol(tokens[j]);
			if (nums[num_i] > INT_MAX || nums[num_i] < INT_MIN)
				return (free_all(tokens, nums));
			j++;
			num_i++;
		}
		free_tokens(tokens);
		tokens_i++;
	}
	if (is_dup(nums, num_i))
		return (free_return(nums));
	return (nums);
}

int	main(int argc, char **argv)
{
	int			num_len;
	long long	*num;
	int			num_i = 0;

	if (argc < 2)
	{
		printf("arg error\n");
		return (1);
	}
	else
	{
		num_len = count_tokens(argv + 1, argc - 1);
		printf("%d\n", num_len);
		num = parse_args(argv + 1, argc - 1);
		if (!num)
		{
			printf("parse error\n");
			free(num);
			return (1);
		}
		while (num_i < num_len)
		{
			printf("num[%d]: %lld\n", num_i, num[num_i]);
			num_i++;
		}
		printf("ok\n");
	}
	free(num);
	return (0);
}
