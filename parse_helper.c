/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:12:19 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/13 18:27:48 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

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
			if ((j == 0 && !is_space(s[i][j]))
				|| (j > 0 && !is_space(s[i][j]) && is_space(s[i][j - 1])))
				tokens++;
			j++;
		}
		i++;
	}
	return (tokens);
}

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

bool	is_dup(t_list *lst)
{
	t_list	*curr;
	t_list	*cmp;

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

long long	ft_atol_ps(const char *nptr)
{
	long	num;
	long	sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	if (is_sign(nptr[i]) == 1)
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(nptr[i]) == 1)
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (sign * num);
}

t_list	*gen_node(long long num)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = (int)num;
	new->index = -1;
	new->pre = NULL;
	new ->next = NULL;
	return (new);
}

// void	ft_lstadd_last(t_list **lst, t_list *new)
// {
// 	t_list *curr;

// 	curr = *lst;
// 	if (!*lst)
// 		*lst = new;
// 	else
// 	{
// 		while (curr -> next)
// 			curr = curr-> next;
// 		curr->next = new;
// 		new->pre = curr;
// 		new->next = NULL;
// 	}
// }
