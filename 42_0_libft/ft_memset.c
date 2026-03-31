/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:46:54 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/12 17:58:58 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char origin[] = "chickenabcde";
// 	char mine[] = "chickenabcde";

// 	memset(origin, 556, sizeof(origin) - 1);
// 	ft_memset(mine, 556, sizeof(mine) - 1);
// 	printf("origin = %s\nmine = %s\n", origin, mine);
// 	return (0);
// }
