/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:45:56 by iduman            #+#    #+#             */
/*   Updated: 2025/07/18 19:00:05 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include "Libft/libft.h"
# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN -2147483648
# endif

void	*ft_memdup(const void *src, size_t n);
void	ft_free_split(char **arr);
void	*ft_realloc(void *ptr, size_t new_size);
int		ft_health_helper(char **split, long **numbers, long int *cap, long int *count);
long	ft_atol(const char *str);
#endif