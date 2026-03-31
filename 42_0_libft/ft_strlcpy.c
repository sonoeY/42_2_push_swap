/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:01:57 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/12 16:28:43 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char dst[11]; // dst_size wakaranai
// 	// char	src[4] = "asda";

// 	// printf("src_len: %lu\ndst: %s\ndst_len: %lu\n", strlcpy(dst,
// 			// "lorem ipsum", 3), dst, strlen(dst) + 1);
// 	printf("[ft]\nsrc_len: %lu\ndst: %s\ndst_len: %lu\n", ft_strlcpy(dst,
// 			"lorem ipsum", 3), dst, ft_strlen(dst) + 1);
// 	return (0);
// }
