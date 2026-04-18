/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:02:00 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/12 16:28:39 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && i < n)
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, size);
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (((dst_len + i) < (size - 1)) && src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	dst1[10] = "a";
// 	size_t	size;

// 	size = 7;
// 	printf("want(d + s): %lu\ndst1: %s\ndst1_len: %lu\n", strlcat(dst1,
// 			"lorem ipsum dolor sit amet", size), dst1, strnlen(dst1, size) + 1);
// 	// printf("[ft]\nwant(d + s): %lu\ndst1: %s\ndst1_len: %lu\n",
// 		// ft_strlcat(dst1, "lorem ipsum dolor sit amet", size), dst1,
// 		// strnlen(dst1, size) + 1);
// 	return (0);
// }
