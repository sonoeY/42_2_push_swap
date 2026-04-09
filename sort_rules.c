/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:00:00 by sonoe             #+#    #+#             */
/*   Updated: 2026/04/09 18:15:04 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_node(t_list **lst)
{
	t_list	*first;
	t_list	*sec;
	t_list  *trd;

	first = *lst;
	sec = (*lst)->next;
	if (!*lst || !(*lst)->next)
		return ;
	if (!(*lst)->next->next)
		first->next = NULL;
	else
	{
		trd = sec->next;
		first->next = trd;
		trd->pre = first;
	}
	sec->pre = NULL;
	sec->next = first;
	first->pre = sec;
	*lst = sec;
	return ;
}

void push_node(t_list **lst_from, t_list **lst_to)
{
	t_list	*a_head;

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
	if (!*lst_to)
		a_head->next = NULL;
	else
	{
		a_head->next = *lst_to;
		(*lst_to)->pre = a_head;
	}
	*lst_to = a_head;
	return ;
}

void rotate_up(t_list **lst)
{
	t_list	*curr;
	t_list	*tmp;

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

void rotate_down(t_list **lst)
{
	t_list	*curr;
	t_list	*tmp;

	if (!*lst || !(*lst)->next)
		return ;
	curr = *lst;
	while (curr->next)
		curr = curr->next;
	tmp = curr;
	curr->pre->next = NULL;
	tmp->pre = NULL;
	ft_listadd_front(lst, tmp);
	return ;
}
