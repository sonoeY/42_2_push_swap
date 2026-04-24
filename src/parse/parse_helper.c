/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:12:19 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/25 02:46:04 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_tokens(char **s, int arg_total)
{
	size_t	i;
	size_t	j;
	size_t	tokens;

	i = 0;
	tokens = 0;
	while (i < (size_t)arg_total)
	{
		j = 0;
		while (s[i][j])
		{
			if ((j == 0 && !(s[i][j] == SPACE))
				|| (j > 0 && !(s[i][j] == SPACE) && (s[i][j - 1] == SPACE)))
				tokens++;
			j++;
		}
		i++;
	}
	return (tokens);
}

bool	check_char_num(char *tokens)
{
	size_t	i;

	i = 0;
	if (!tokens)
		return (false);
	while (tokens[i])
	{
		if ((i == 0 && is_sign(tokens[i])) && !ft_isdigit(tokens[i + 1]))
			return (false);
		else if (!(is_sign(tokens[i]) || ft_isdigit(tokens[i])))
			return (false);
		i++;
	}
	return (true);
}

bool	check_overflow(const char *nptr)
{
	long long	num;
	long long	sign;
	long long	d;
	size_t		i;

	num = 0;
	sign = 1;
	i = 0;
	if (is_sign(nptr[i]) == 1)
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] && ft_isdigit(nptr[i]) == 1)
	{
		d = nptr[i] - '0';
		if (((sign == 1) && (num > (INT_MAX - d) / 10))
			|| ((sign == -1) && (num < (INT_MIN + d) / 10)))
			return (true);
		num = (num * 10) + (sign * d);
		i++;
	}
	return (false);
}

t_node	*gen_node(long long num)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->data = (int)num;
	new->index = -1;
	new->pre = NULL;
	new->next = NULL;
	return (new);
}

bool	check_dup(t_node *lst)
{
	t_node	*curr;
	t_node	*cmp;

	curr = lst;
	while (curr)
	{
		cmp = curr->next;
		while (cmp)
		{
			if (curr->data == cmp->data)
				return (true);
			cmp = cmp->next;
		}
		curr = curr->next;
	}
	return (false);
}
