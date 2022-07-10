/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-mora <gde-mora@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:34:59 by gde-mora          #+#    #+#             */
/*   Updated: 2022/07/10 04:40:02 by gde-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	char	*aux_str;

	if (!str)
		return (NULL);
	aux_str = (char *)str;
	while (*aux_str)
	{
		if (*aux_str == (char)c)
			return (aux_str);
		aux_str++;
	}
	if (c == '\0')
		return (aux_str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	while (i + 1 < size && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

static size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	result;

	size_dest = ft_strlen(dest);
	if (size_dest > size)
		return (ft_strlen(src) + size);
	result = size_dest + ft_strlen(src);
	while (*src && size_dest + 1 < size)
	{
		dest[size_dest] = *src++;
		size_dest++;
	}
	dest[size_dest] = '\0';
	return (result);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*nstr;
	size_t	size_nstr;

	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	size_nstr = ft_strlen(s1) + ft_strlen(s2);
	nstr = (char *)malloc(sizeof(char) * (size_nstr + 1));
	if (!nstr)
		return (NULL);
	ft_strlcpy(nstr, s1, ft_strlen(s1) + 1);
	ft_strlcat(nstr, s2, size_nstr + 1);
	free(s1);
	return (nstr);
}
