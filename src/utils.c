/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:22:54 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/22 08:43:24 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

int	ft_lstsize(t_node *lst)
{
	t_node	*curr;
	int		i;

	i = 0;
	if (!lst)
		return (i);
	curr = lst;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (!lst || !new)
		return ;
	new->pre = NULL;
	if (!*lst)
		new->next = NULL;
	else
	{
		new->next = *lst;
		(*lst)->pre = new;
	}
	*lst = new;
	return ;
}

void	ft_lstadd_last(t_node **lst, t_node *new)
{
	t_node	*curr;

	if (!lst || !new)
		return ;
	curr = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while (curr -> next)
			curr = curr-> next;
		curr->next = new;
		new->pre = curr;
		new->next = NULL;
	}
}

void	free_lsts(t_node **lst)
{
	t_node	*curr;
	t_node	*next;

	if (!lst || !*lst)
		return ;
	curr = *lst;
	while (curr)
	{
		next = curr-> next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}
