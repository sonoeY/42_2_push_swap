/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:22:54 by soyamagu          #+#    #+#             */
/*   Updated: 2026/03/24 00:36:27 by soyamagu         ###   ########.fr       */
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

