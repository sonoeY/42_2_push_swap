/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:08:44 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/15 21:00:25 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;

	if (nmemb == 0 || size == 0)
	{
		s = malloc(1);
		if (s == NULL)
			return (NULL);
		ft_memset (s, 0, 1);
		return (s);
	}
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	s = malloc(size * nmemb);
	if (s == NULL)
		return (NULL);
	ft_memset (s, 0, size * nmemb);
	return (s);
}

// #include <string.h>
// #include <stdio.h>
// #include <stdint.h>

// int main(void)
// {
// 	size_t	i;
// 	//int 	*arr;
// 	int 	*ft_arr;
// 	size_t	nmb;

// 	i = 0;
// 	nmb = 0;
// 	//arr = calloc(nmb, 0);
// 	ft_arr = ft_calloc(0, 0);
// 	while (i < nmb)
// 	{
// 		//printf("arr[%zu]    = %d\n", i, arr[i]);
// 		printf("ft_arr[%zu] = %d\n\n", i, ft_arr[i]);
// 		i++;
// 	}
// 	//free (arr);
// 	free (ft_arr);
// 	return (0);
// }
