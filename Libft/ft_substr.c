
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	buf = (char *)malloc(sizeof(char) * len + 1);
	if (!buf)
		return (0);
	ft_strlcpy(buf, s + start, len + 1);
	return (buf);
}
