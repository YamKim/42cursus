#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	ret;

	ret = 0;
	if (str == NULL)
		return (ret);
	while (*(str++))
		++ret;
	return (ret);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ret;
	size_t	len_src;

	ret = 0;
	if (src == NULL)
		return (ret);
	len_src = ft_strlen(src);
	if (dest == NULL || size == 0)
		return (len_src);
	while (ret < len_src && ret < size - 1)
	{
		dest[ret] = src[ret];
		++ret;
	}
	dest[ret] = '\0';
	return (len_src);
}

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len;

	len = ft_strlen((char *)s);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			idx;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char*)s1;
	us2 = (unsigned char*)s2;
	idx = 0;
	while ((us1[idx] || us2[idx]) && idx < n)
	{
		if (us1[idx] != us2[idx])
			break ;
		++idx;
	}
	return (idx == n ? 0 : (int)(us1[idx] - us2[idx]));
}
