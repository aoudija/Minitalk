/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoudija <aoudija@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 07:54:58 by aoudija           #+#    #+#             */
/*   Updated: 2023/01/06 11:22:48 by aoudija          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == NULL || size == 0)
		return (ft_strlen (src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	d;

	d = ft_strlen(dst);
	i = 0;
	if (n <= d)
		return (n + ft_strlen(src));
	while (*dst)
		dst++;
	while (src[i] && i < n - d - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (d + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*sj;
	int		d;
	int		s;

	if (!s1)
		return (ft_strdup(s2));
	d = ft_strlen(s1);
	s = ft_strlen(s2);
	len = d + s;
	sj = (char *)malloc(len + 1);
	if (sj == NULL)
		return (NULL);
	ft_strlcpy(sj, s1, d + 1);
	ft_strlcat(sj, s2, len + 1);
	return (sj);
}
