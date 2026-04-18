/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:17:02 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/08 19:04:26 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*unchar_s;
	unsigned char		unchar_c;

	i = 0;
	unchar_s = s;
	unchar_c = c;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (unchar_s[i] == unchar_c)
			return ((void *)&unchar_s[i]);
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	s[15] = "ABC3qwertyuiop";

// 	//printf("return    = %p\ncorrect   = %p\n", memchr(s1, 'A', 21), &s1[0]);
// 	printf("return    = %p\n", memchr(s, 'A', 21));
// 	printf("ft_return = %p\n", ft_memchr(s, 'A', 21));
// 	return (0);
// }
