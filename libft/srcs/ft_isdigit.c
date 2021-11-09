/*
DESCRIPTION
	isdigit() checks for a digit (0 through 9).
RETURN VALUE
	The values returned are nonzero if the character c falls into the
	tested class, and zero if not.
*/

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}
