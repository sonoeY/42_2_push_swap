/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:14:40 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/13 17:50:01 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new_str;
	char	*str;

	if (!s || !f)
		return (NULL);
	new_str = malloc(ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		new_str[i] = f(i, str[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

// #include "libft.h"
// #include <stdio.h>

// static char	ft_tolower_c(unsigned int un, char c)
// {
// 	(void)un;
// 	if (c >= 'A' && c <= 'Z')
// 	{
// 		c += 32;
// 		return (c);
// 	}
// 	return (c);
// }

// int	main(void)
// {
// 	char	str[13] = "DON'T PANIC!";

// 	printf("new: %s\n", ft_strmapi(str, ft_tolower_c));
// 	return (0);
// }
