/*
DESCRIPTION
	The strchr() function returns a pointer to the first occurrence of the
	character c in the string s.
RETURN VALUE
	The strchr() function returns a pointer to the matched
	character or NULL if the character is not found. The terminating null
	byte is considered part of the string, so that if c is specified as '\0',
	these functions return a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
