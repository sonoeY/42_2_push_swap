/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_make_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:12:19 by soyamagu          #+#    #+#             */
/*   Updated: 2026/03/24 02:14:24 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include <stdio.h>

int	count_tokens(char **s, int arg_total)
{
	size_t	i;
	size_t	j;
	size_t	tokens;

	i = 0;
	tokens = 0;
	while (i < (size_t)arg_total)
	{
		j = 0;
		while (s[i][j])
		{
			if ((j == 0 && !is_space(s[i][j]))
				|| (j > 0 && !is_space(s[i][j]) && is_space(s[i][j - 1])))
				tokens++;
			j++;
		}
		i++;
	}
	return (tokens);
}

long long	*make_array(char **arg_value, int arg_total)
{
	long long	*num_array;
	size_t		num_len;

	num_len = count_tokens(arg_value, arg_total);//
	num_array = ft_calloc(sizeof(long long), num_len);
	if (!num_array)
		return (NULL);
	return (num_array);
}


//tester
// int	main(int argc, char **argv)
// {
// 	//char	**nums;
// 	//int	res;

// 	if (argc < 2)
// 		return (0);
// 	// res = is_arg_empty(argv + 1, argc - 1);
// 	// printf("%d\n", res);
// 	// if (is_arg_empty(argv + 1, argc - 1))
// 	// 	write (1, "Error\n", 6);
// 	printf("%d\n", count_tokens(argv + 1, argc - 1));
// 	return (0);
// }
