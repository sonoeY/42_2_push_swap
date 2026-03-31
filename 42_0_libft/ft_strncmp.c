/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:41:09 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/15 21:27:25 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}

// //either s1 is larger or smaller, calculation is the same (s1 - s2)
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	// char	str1[] = "\200";
// 	// char	str2[] = "\0";
// 	// char *str1 = "\x12\xff\x65\x12\xbd\xde\xad";
//     // char *str2 = "\x12\x02";
// 	char *big = "abcdef";
//     char *little = "abcdefghijklmnop";

// 	printf("strncmp = %d\n", strncmp(big, little, 10));
// 	printf("ft_strncmp = %d\n", ft_strncmp(big, little, 10));
// 	return (0);
// }
