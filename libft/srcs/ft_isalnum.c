/*
DESCRIPTION
	isalnum() checks for an alphanumeric character; it is equivalent to 
	(isalpha(c) || isdigit(c)).
RETURN VALUE
	The values returned are nonzero if the character c falls into the
	tested class, and zero if not.
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
