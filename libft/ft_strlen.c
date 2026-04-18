/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:45:59 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/08 19:07:49 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	str1[] = "summerrrrrrrrrrrrrrrrrrrrrrrrrrr";
// 	char	str2[] = "summerrrrrrrrrrrrrrrrrrrrrrrrrrr";

// 	printf("ft_strlen = %zu\n", ft_strlen(str1));
// 	printf("strlen = %lu\n", strlen(str2));
// 	return (0);
// }
