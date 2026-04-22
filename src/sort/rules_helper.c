/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:00:00 by sonoe             #+#    #+#             */
/*   Updated: 2026/04/22 08:43:24 by soyamagu         ###   ########.fr       */
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
	return ;
}

void	push_node(t_node **lst_from, t_node **lst_to)
{
	t_node	*a_head;

	if (!*lst_from)
		return ;
	a_head = *lst_from;
	a_head->pre = NULL;
	if (!a_head->next)
		*lst_from = NULL;
	else
	{
		*lst_from = a_head->next;
		(*lst_from)->pre = NULL;
	}
	a_head->next = NULL;
	ft_lstadd_front(lst_to, a_head);
	return ;
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
	return ;
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
	return ;
}
