/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouhsis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:15:37 by hbouhsis          #+#    #+#             */
/*   Updated: 2022/02/07 15:15:39 by hbouhsis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pipex.h"

int	wcount(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || !(s[i + 1])))
			count++;
		i++;
	}
	return (count);
}

int	wrlen(char const *s, char c, int t)
{
	int	i;

	i = 0;
	while (s[t] != c && s[t] != 0)
	{
		t++;
		i++;
	}
	return (i);
}

char	*copy(int t, char const *s, char c)
{
	int		j;
	int		len ;
	char	*str;

	j = 0;
	len = wrlen(s, c, t);
	str = (char *)malloc(sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	while (j < len && s[t] != c)
	{
		str[j] = (char)s[t];
		j++;
		t++;
	}
	str[j] = '\0';
	return (str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		t;
	char	**str;

	i = 0;
	t = 0;
	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (wcount(s, c) + 1));
	if (!str)
		return (NULL);
	while (i < wcount(s, c))
	{
		while (s[t] == c)
			t++;
		str[i] = copy(t, s, c);
		t += wrlen(s, c, t);
		i++;
	}
	str[i] = 0;
	return (str);
}
