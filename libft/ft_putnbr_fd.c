/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:56:05 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/12 19:28:12 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	nb;
	char		num;

	nb = n;
	if (nb == 0)
		write(fd, "0", 1);
	else if (nb > 0)
	{
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		num = nb % 10 + '0';
		write(fd, &num, 1);
	}
	else if (nb < 0)
	{
		write(fd, "-", 1);
		nb = nb * -1;
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		num = nb % 10 + '0';
		write(fd, &num, 1);
	}
}

// int	main(void)
// {
// 	ft_putnbr_fd(-5, 1);
// }
