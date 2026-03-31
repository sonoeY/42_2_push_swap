/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_convert_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:41:14 by soyamagu          #+#    #+#             */
/*   Updated: 2026/03/16 11:07:44 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// #include <stdio.h>
// #include <stdlib.h>

// int	main(int argc, char **argv)
// {
// 	//char	temp[] = "\t\v\f\r\n \f-2147483648";

// 	if (argc == 2)
// 	{
// 		printf("res: %lld\n", ft_atol(argv[1]));
// 	}
// 	printf("argc error");
// 	return (0);
// }
