/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:22:54 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/13 22:13:47 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//need to remove (f) for print error

bool	is_sign(char c)
{
	if (c == '+' || c == '-')
		return (true);
	return (false);
}

bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	return (false);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
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

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
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

void	ft_lstadd_last(t_list **lst, t_list *new)
{
	t_list	*curr;

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

void	free_lst(t_list **lst)
{
	t_list	*curr;
	t_list	*next;

	curr = *lst;
	while (curr)
	{
		next = curr-> next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}

int	exit_error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}
