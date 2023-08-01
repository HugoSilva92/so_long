/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huolivei <huolivei <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 01:15:40 by huolivei          #+#    #+#             */
/*   Updated: 2023/01/30 16:02:45 by huolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != (char)c)
		i++;
	if ((char)c == str[i])
		return ((char *)str + i);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	size_t	i;
	size_t	i1;

	i = ft_strlen(str) + 1;
	i1 = 0;
	dest = malloc(i * sizeof(char));
	if (!dest)
		return (NULL);
	while (i1 < i)
	{
		dest[i1] = str[i1];
		i1++;
	}
	return (dest);
}
