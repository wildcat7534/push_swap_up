/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmassol <cmassol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 22:49:32 by cmassol           #+#    #+#             */
/*   Updated: 2024/12/08 19:21:01 by cmassol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0 && *str1 != '\0' && *str2 != '\0' && *str1 == *str2)
	{
		str1++;
		str2++;
		n--;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
