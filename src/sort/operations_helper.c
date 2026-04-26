/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:00:00 by sonoe             #+#    #+#             */
/*   Updated: 2026/04/26 12:36:37 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_node(t_node **lst)
{
	t_node	*first;
	t_node	*sec;
	t_node	*trd;

	if (!*lst || !(*lst)->next)
		return ;
	first = *lst;
	sec = (*lst)->next;
	trd = sec->next;
	first->next = trd;
	if (trd)
		trd->pre = first;
	sec->pre = NULL;
	sec->next = first;
	first->pre = sec;
	*lst = sec;
}

void	push_node(t_node **src, t_node **dst)
{
	t_node	*head;

	if (!*src)
		return ;
	head = *src;
	head->pre = NULL;
	if (!head->next)
		*src = NULL;
	else
	{
		*src = head->next;
		(*src)->pre = NULL;
	}
	head->next = NULL;
	ft_lstadd_front(dst, head);
}

void	rotate_up(t_node **lst)
{
	t_node	*curr;
	t_node	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	curr = *lst;
	tmp = *lst;
	(*lst) = (*lst)->next;
	(*lst)->pre = NULL;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
	tmp->pre = curr;
	tmp->next = NULL;
}

void	rotate_down(t_node **lst)
{
	t_node	*curr;
	t_node	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	tmp = curr;
	curr->pre->next = NULL;
	tmp->pre = NULL;
	ft_lstadd_front(lst, tmp);
}
