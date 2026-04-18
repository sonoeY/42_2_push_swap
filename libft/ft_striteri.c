/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:14:56 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/10 20:37:34 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	while (s != NULL && f != NULL && s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include "libft.h"
// #include <stdio.h>

// static void	ft_toupper_c(unsigned int un, char *c)
// {
// 	(void)un;
// 	if (*c >= 'a' && *c <= 'z')
// 	{
// 		*c -= 32;
// 	}
// }

// int	main(void)
// {
// 	char	str[13] = "don't panic!";
// 	//char	*str = NULL;

// 	ft_striteri(str, ft_toupper_c);
// 	printf ("str: %s", str); //上で実行することで中身が変わるはず
// 	return (0);
// }
