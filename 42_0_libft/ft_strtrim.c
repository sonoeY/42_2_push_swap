/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:20:44 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/13 17:49:45 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iskeyword(const char c, char const *keyword)
{
	int	i;

	i = 0;
	while (keyword[i] != '\0')
	{
		if (keyword[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim_s;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && (iskeyword(s1[start], set) == 1))
		start++;
	while (end > start && (iskeyword(s1[end - 1], set) == 1))
		end--;
	trim_s = malloc((end - start) + 1);
	if (trim_s == NULL)
		return (NULL);
	i = 0;
	while ((start + i) < end)
	{
		trim_s[i] = s1[start + i];
		i++;
	}
	trim_s[i] = '\0';
	return (trim_s);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[59] = "33kkkkk3gkkpo3k5k5k5kkkk3";
// 	//char	*s = NULL;
// 	//char	*set = NULL;

// 	printf("trim_s = %s\n", ft_strtrim(s, "3k"));
// 	return (0);
// }
