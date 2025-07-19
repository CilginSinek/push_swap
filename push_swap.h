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

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

size_t	ft_strlen(const char *s);
void	ft_putstr(char *s);
int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void    *memintset(void *ptr, int c);
void ft_putnbr(long int n);
void ft_putchar(char c);

typedef struct s_list
{
    void *content;
    size_t index;
    size_t pos;
    size_t target_pos;
    size_t cost_b;
    size_t cost_a;
    size_t cost_ab;
    struct s_list *next;
}   t_list;

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(t_list *));


#endif