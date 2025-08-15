/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 17:24:41 by iduman            #+#    #+#             */
/*   Updated: 2025/08/15 21:29:44 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sep(char c, const char *charset)
{
	return (ft_strchr(charset, c) != NULL);
}

static size_t	word_counter(const char *s, const char *charset)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!is_sep(*s, charset) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_sep(*s, charset))
			in_word = 0;
		s++;
	}
	return (count);
}

static int	check_memory(char **result, size_t word)
{
	if (!result[word])
	{
		while (word > 0)
			free(result[--word]);
		free(result);
		return (1);
	}
	return (0);
}

static char	**setter(char **result, const char *s, const char *charset)
{
	size_t	i;
	size_t	word;
	size_t	start;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (!is_sep(s[i], charset))
		{
			start = i;
			while (s[i] && !is_sep(s[i], charset))
				i++;
			result[word] = ft_substr(s, start, i - start);
			if (check_memory(result, word))
				return (NULL);
			word++;
		}
		else
			i++;
	}
	result[word] = NULL;
	return (result);
}

char	**ft_split_charset(const char *s, const char *charset)
{
	char	**result;
	size_t	word_count;

	if (!s || !charset)
		return (NULL);
	word_count = word_counter(s, charset);
	result = (char **)ft_calloc((word_count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	return (setter(result, s, charset));
}
