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