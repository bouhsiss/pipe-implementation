/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:15:29 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/02/07 15:15:31 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (c1[i] && c2[i] && i < n - 1 && c1[i] == c2[i])
		i++;
	return (c1[i] - c2[i]);
}

static char	*ft_strcat(char	*dest, char	*src)
{
	int	i;
	int	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (dest);
}

static char	*ft_strcpy(char	*dest, char	*src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t		total;
	char		*str;
	char		*c1;
	char		*c2;

	if (!s1 || !s2)
		return (0);
	c1 = (char *)s1;
	c2 = (char *)s2;
	total = ft_strlen(c1) + ft_strlen(c2);
	str = (char *)malloc((total + 1) * sizeof(char));
	if (!(str))
		return (NULL);
	ft_strcpy(str, c1);
	ft_strcat(str, c2);
	free(s1);
	return (str);
}
