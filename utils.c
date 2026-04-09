/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonoe <sonoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:22:54 by soyamagu          #+#    #+#             */
/*   Updated: 2026/04/09 18:20:48 by sonoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

long long	ft_atol_ps(const char *nptr)
{
	long	num;
	long	sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	// while (ft_isspace(nptr[i]) == 1)
	// 	i++;
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

void ft_lstadd_front(t_list **lst, t_list *new)
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

int	exit_error(int fd)
{
	write(fd, "Error\n", 6);
	return (1);
}
