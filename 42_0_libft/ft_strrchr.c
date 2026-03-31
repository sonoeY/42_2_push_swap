/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:02:08 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/12 16:28:56 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;

	s_len = ft_strlen(s);
	while (s_len > 0)
	{
		if ((const unsigned char)s[s_len] == (unsigned char)c)
			return ((char *)&s[s_len]);
		s_len--;
	}
	if ((const unsigned char)s[s_len] == (unsigned char)c)
		return ((char *)&s[s_len]);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
//
// int	main(void)
// {
// 	//char	s[17] = "231nnbvcxucvbnmm";
// 	char 	*src = "abbbbbbbb";
//
// 	// printf ("origin : result = %p, correct = %p\n", strrchr(s, 'n'), &s[13]);
// 	// printf ("ft  : result = %p, correct = %p\n", strrchr(s, 'n'), &s[13]);
// 	printf ("origin : result = %p, correct = %p\n", strrchr(src, 'a'), &src[0]);
// 	printf ("ft: result = %p, correct = %p\n", ft_strrchr(src, 'a'), &src[0]);
// 	return (0);
// }
