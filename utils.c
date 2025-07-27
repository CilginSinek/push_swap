/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:17:10 by iduman            #+#    #+#             */
/*   Updated: 2025/07/27 16:49:24 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(long *arr, int count, long val)
{
	while (count--)
	{
		if (arr[count] == val)
			return (1);
	}
	return (0);
}

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*new_ptr;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, new_size);
	free(ptr);
	return (new_ptr);
}

int	ft_health_helper(char **split, long **ns, long int *cap, long int *count)
{
	long	num;
	long	*tmp;

	while (*split)
	{

		if (!is_valid_number(*split))
			return (0);			
		num = ft_atol(*split);
		if (num < INT_MIN || num > INT_MAX)
			return (0);
		if (is_duplicate(*ns, *count, num))
			return (0);
		if (*count >= *cap)
		{
			*cap *= 2;
			tmp = (long *)ft_realloc(*ns, sizeof(long) * (*cap));
			if (!tmp)
				return (0);
			*ns = tmp;
		}
		(*ns)[*count] = num;
		(*count)++;
		split++;
	}
	return (1);
}
