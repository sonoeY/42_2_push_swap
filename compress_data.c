/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 15:56:12 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/13 19:16:57 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*find_unidx(t_list *lst);
static t_list	*find_min(t_list *lst);

void	compress_data(t_list **lst)
{
	t_list	*lst_min;
	int		size;
	int		i;

	if (!lst)
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

static t_list	*find_unidx(t_list *lst)
{
	t_list	*curr;

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

static t_list	*find_min(t_list *lst)
{
	t_list	*curr;
	t_list	*lst_min;

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
