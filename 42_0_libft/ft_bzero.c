/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:47:00 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/14 17:52:53 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	origin[] = "chi3en";
// 	char	mine[] = "chi3en";

// 	bzero(origin, sizeof(origin) - 1);
// 	ft_bzero(mine, sizeof(mine) - 1);
// 	printf("origin = %s\nmine = %s\n", origin, mine);
// 	return (0);
// }
