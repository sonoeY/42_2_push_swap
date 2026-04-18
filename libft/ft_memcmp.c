/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:16:49 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/15 21:36:08 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*unchar_s1;
	const unsigned char	*unchar_s2;

	if (n == 0)
		return (0);
	unchar_s1 = (const unsigned char *)s1;
	unchar_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (unchar_s1[i] != unchar_s2[i])
			return ((int)(unchar_s1[i] - unchar_s2[i]));
		i++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[10];
// 	char	s2[10];

// 	strcpy(s1, "ABC");
// 	strcpy(s2, "ABC");

// 	// char	s1[18] = "ABC\0DEFfghj";
// 	// char	s2[18] = "ABC\0DEFfghj";

// 	printf("   data = %d\n", memcmp(s1, s2, 15));
// 	printf("ft_data = %d\n", ft_memcmp(s1, s2, 15));
// 	return (0);
// }
