/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iduman <iduman@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 18:34:32 by iduman            #+#    #+#             */
/*   Updated: 2025/07/18 18:37:30 by iduman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    *memintset(void *ptr, int c)
{
    unsigned char *p;
    int i;

    i = 3;
    p = (unsigned char *)(&c);
    if (ptr == NULL)
        return (NULL);
    if (p == NULL)
        return (NULL);
    while (i--) 
    {
        ((unsigned char *)ptr)[i] = p[i];
    }
    return (ptr);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	n;
	n = nmemb * size;
	int i;

	i = 0;
	ptr = malloc(n);
	if (ptr == NULL)
	{
		return (NULL);
	}
	while (n--)
		((unsigned char *)ptr)[i++] = '\0';
	return ((void *)ptr);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(long int n)
{
    if (n < 0)
    {
        ft_putstr("-");
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar((n % 10) + '0');
}