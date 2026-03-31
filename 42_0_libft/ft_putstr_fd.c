/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:57:12 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/15 21:05:19 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (len - i > WRITE_BUFFER_MAX)
	{
		write (fd, &s[i], WRITE_BUFFER_MAX);
		i += WRITE_BUFFER_MAX;
	}
	if (i < len)
		write (fd, &s[i], (len - i));
}

// int	main(void)
// {
// 	ft_putstr_fd ("1234567891011", 1);
// 	return (0);
// }
