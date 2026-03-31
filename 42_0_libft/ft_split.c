/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soyamagu <soyamagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:21:00 by soyamagu          #+#    #+#             */
/*   Updated: 2025/11/13 12:53:00 by soyamagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_terms(char const *s, char c)
{
	size_t	i;
	size_t	term;
	int		is_c;

	i = 0;
	term = 0;
	is_c = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (is_c == 0)
			{
				is_c = 1;
				term++;
			}
		}
		else if (s[i] == c && is_c == 1)
			is_c = 0;
		i++;
	}
	return (term);
}

static char	*make_term(const char *str, unsigned int str_i, char c)
{
	char			*term;
	size_t			len;

	len = 0;
	while (str[str_i] == c)
		str_i++;
	while (str[str_i + len] != '\0' && str[str_i + len] != c)
		len++;
	term = ft_substr(str, str_i, len);
	return (term);
}

static size_t	start_p(const char *s, size_t str_i, char c)
{
	while (s[str_i] != '\0')
	{
		str_i++;
		if (str_i > 0 && s[str_i - 1] != c && s[str_i] == c)
			return (str_i);
	}
	return (0);
}

static char	**free_all(char	**result)
{
	size_t	i;

	i = 0;
	while (result[i] != NULL)
	{
		free (result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_i;
	size_t	str_i;
	size_t	n;
	char	**result;

	if (s == NULL)
		return (NULL);
	n = count_terms(s, c);
	result = malloc(sizeof(char *) * (n + 1));
	if (result == NULL)
		return (NULL);
	word_i = 0;
	str_i = 0;
	while (word_i < n)
	{
		result[word_i] = make_term(s, str_i, c);
		if (result[word_i] == NULL)
			return (free_all(result));
		str_i = start_p(s, str_i, c);
		word_i++;
	}
	result[word_i] = NULL;
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	s[] = "        00000        4567543234567yfxd hjgvhbjn ";
// 	char	**res = ft_split(s, ' ');
// 	int 	i = 0;

// 	printf("     s: %s\n", s);
// 	if (res == NULL)
// 		return (1);
// 	while (res[i] != NULL)
// 	{
// 		printf("res[%d]: %s\n", i, res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (0);
// }
