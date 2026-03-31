/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:41:14 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/15 20:46:12 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if ((c >= '\t' && c <= '\r') || c == ' ')
		return (1);
	return (0);
}

static int	ft_issign(int c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long	num;
	long	sign;
	size_t	i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]) == 1)
		i++;
	if (ft_issign(nptr[i]) == 1)
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
	return ((int)(sign * num));
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	temp[] = "\t\v\f\r\n \f-2147483648";

// 	printf("temp = %d\n", atoi(temp));
// 	printf("temp = %d\n", ft_atoi(temp));
// 	return (0);
// }
