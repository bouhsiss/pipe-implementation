#include"pipex.h"

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char		*c1;
	unsigned char		*c2;
	size_t				i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (c1[i] && c2[i] && i < n - 1 && c1[i] == c2[i])
		i++;
	return (c1[i] - c2[i]);
}


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