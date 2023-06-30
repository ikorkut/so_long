#include "libft.h"

static size_t	get_digits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	const char	*digits;

	digits = "0123456789";
	len = get_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[--len] = digits[n % 10];
		else
			str[--len] = digits[n % 10 * -1];
		n /= 10;
	}
	return (str);
}
