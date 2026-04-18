/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:21:15 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/13 17:47:27 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		len++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

static char	*digit_maker(char *s_nb, long nb, size_t len)
{
	s_nb[len] = '\0';
	if (nb < 0)
	{
		nb = nb * -1;
		while (len >= 1)
		{
			s_nb[len - 1] = (nb % 10) + '0';
			nb = nb / 10;
			len--;
		}
		s_nb[0] = '-';
		return (s_nb);
	}
	while (len > 0)
	{
		s_nb[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (s_nb);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*s_nb;
	size_t	len;

	nb = n;
	if (nb == 0)
		return (ft_strdup("0"));
	else
	{
		len = len_nb(nb);
		s_nb = malloc(len + 1);
		if (s_nb == NULL)
			return (NULL);
		return (digit_maker(s_nb, nb, len));
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("result: %s\n", ft_itoa(-1234567));
// 	// len_nb (1234567);
// 	return (0);
// }
