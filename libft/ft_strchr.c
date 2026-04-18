/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 21:02:05 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/07 15:28:32 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while ((const unsigned char)s[i] != '\0')
	{
		if ((const unsigned char)s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((const unsigned char)s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char 	*src = "teste";

// 	// printf ("origin : result = %p, correct = %p\n", strchr("", 0), &src[1]);
// 	// printf ("ft : result = %p, correct = %p\n", ft_strchr("", 0), &src[1]);
// 	printf ("result: %p\n", strchr(src, 'e'));
// 	printf ("ft_result: %p\n", ft_strchr(src, 'e'));
// 	return (0);
// }
