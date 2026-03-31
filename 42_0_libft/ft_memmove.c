/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:16:16 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/07 17:28:58 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	if (d <= s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return ((void *)d);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	//char	data[10];
// 	char	src[] = "ABCDEFG";

// 	//printf("data = %s\n", (char *)memmove(src + 2, src, 3));
// 	printf("data = %s\n", (char *)ft_memmove(src + 2, src, 3));
// 	return (0);
// }
