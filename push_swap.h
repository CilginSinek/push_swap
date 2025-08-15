/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:45:56 by iduman            #+#    #+#             */
/*   Updated: 2025/08/15 23:11:58 by iduman           ###   ########.fr       */
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

char	**ft_split_charset(const char *s, const char *charset);
void	*ft_memdup(const void *src, size_t n);
void	ft_free_split(char **arr);
int		ft_health_helper(char **split, long **numbers,
			long int *cap, long int *count);
long	ft_atol(const char *str);

void	swap(t_list **head, int i);
void	swap_s(t_list **head_a, t_list **head_b);
void	put(t_list **giver_list, t_list **taker_list, int i);
void	rrotater(t_list **head, int i);
void	rrotater_s(t_list **head_a, t_list **head_b);
void	rotater(t_list **head, int i);
void	rotater_s(t_list **head_a, t_list **head_b);
int		is_sorted(t_list *stack);
void	sort_three(t_list **head);

void	sort_five(t_list **head_a, t_list **head_b);
void	list_functions(t_list **head_a, t_list **head_b);

#endif