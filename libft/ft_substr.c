/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 18:49:40 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/13 17:49:14 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		len = (ft_strlen(s) - (size_t)start);
	sub_s = malloc(len + 1);
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_s[i] = s[(size_t)start + i];
		i++;
	}
	sub_s[i] = '\0';
	return (sub_s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	//char	s[11] = "strawberry";
// 	//char	*str = "01234";
// 	char	*res = ft_substr(NULL, 0, 3);

// 	printf ("substr: %s\n", res);
// 	//printf ("sub_len: %ld\n", (ft_strlen(res) + 1));
// 	return (0);
// }
