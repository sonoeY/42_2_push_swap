/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:56:12 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/22 08:43:24 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_unidx(t_node *lst);
static t_node	*find_min(t_node *lst);

void	compress_data(t_node **lst)
{
	t_node	*lst_min;
	int		size;
	int		i;

	if (!lst || !*lst)
		return ;
	size = ft_lstsize(*lst);
	lst_min = *lst;
	i = 0;
	while (i < size)
	{
		lst_min = find_min(*lst);
		lst_min->index = i;
		i++;
	}
	return ;
}

static t_node	*find_unidx(t_node *lst)
{
	t_node	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr)
	{
		if (curr->index < 0)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

static t_node	*find_min(t_node *lst)
{
	t_node	*curr;
	t_node	*lst_min;

	if (!lst)
		return (NULL);
	curr = find_unidx(lst);
	lst_min = curr;
	while (curr)
	{
		if ((curr->index < 0) && (curr->data < lst_min->data))
			lst_min = curr;
		curr = curr->next;
	}
	return (lst_min);
}
