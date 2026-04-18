/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:08:56 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/14 17:47:42 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dup_s = malloc(len + 1);
	if (dup_s == NULL)
		return (NULL);
	while (i < len)
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[i] = '\0';
	return (dup_s);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "DO";
// 	char	*s1;
// 	char	*s2;

// 	s1 = strdup(s);
// 	s2 = ft_strdup(s);

// 	printf("s1 = %s\ns2 = %s\n", s1, s2);
// 	free(s1);
// 	free(s2);
// }
