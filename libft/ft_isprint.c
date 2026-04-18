/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 21:45:40 by soyamagu          #+#    #+#             */
/*   Updated: 2025/10/20 15:36:55 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}
// #include <ctype.h>
// #include <stdio.h>

// int	main(void)
// {
// 	printf("ft_isprint = %d\n",ft_isprint('='));
// 	printf("isprint = %d\n",isprint('='));
// 	return (0);
// }

// -(value) も文字として認識される
// int	main(int argc, char	**argv)
// {
// 	if (argc != '\0' && argc == 2)
// 	{
// 		printf("ft_isprint = %d\n",ft_isprint(*argv[1]));
// 		printf("isprint = %d\n", isprint(*argv[1]));
// 	}
// 	return (0);
// }
