/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:56:12 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/25 05:08:28 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*find_min(t_node *lst);

void	compress_num(t_node **lst)
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
}

static t_node	*find_min(t_node *lst)
{
	t_node	*curr;
	t_node	*lst_min;

	if (!lst)
		return (NULL);
	lst_min = NULL;
	curr = lst;
	while (curr)
	{
		if ((curr->index < 0)
			&& (!lst_min || (curr->data < lst_min->data)))
			lst_min = curr;
		curr = curr->next;
	}
	return (lst_min);
}
