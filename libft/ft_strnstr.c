/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:41:11 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/08 20:22:26 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0' && little[j] != '\0')
	{
		if (j > 0 && big[i + j] != little[j])
			j = 0;
		while ((i + j) < len && little[j] != '\0' && big[i + j] == little[j])
			j++;
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

// #include <bsd/string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	const char	*largestring = "lorem ipsum dolor sit amet";
// 	//const char	*smallstring = "ipsum";
// 	char		*ptr1;
// 	char		*ptr2;

// 	//ptr1 = strnstr(largestring, "em ip", 5);
// 	ptr2 = ft_strnstr(largestring, "em ip", 5);
// 	printf("   strnstr: %s\nft_strnstr: %s\n", ptr1, ptr2);
// 	return (0);
// }
