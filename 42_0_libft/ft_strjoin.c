/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:20:09 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/14 16:20:51 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc((s1_len + s2_len) + 1);
	if (s3 == NULL)
		return (NULL);
	ft_memcpy(s3, s1, s1_len);
	ft_memcpy(s3 + s1_len, s2, s2_len);
	s3[s1_len + s2_len] = '\0';
	return (s3);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s1[] = "Japan";
// 	char	s2[] = "ese";

// 	printf("newstr = %s\n", ft_strjoin(s1, s2));
// 	return (0);
// }
