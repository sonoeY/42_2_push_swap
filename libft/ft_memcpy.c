/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:16:03 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/07 17:34:31 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((void *)d);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*data = NULL;
// 	char	src[] = "ABCDEFG";
// 	//char	src[0];

// 	printf("data = %s\n", (char *)memcpy(data, src, 1));
// 	//printf("data = %s\n", (char *)ft_memcpy(data, src, 1));
// 	return (0);
// }
