/*
DESCRIPTION
	If c is an uppercase letter, tolower() returns its lowercase equivalent,
	if a lowercase representation exists in the current locale. Otherwise,
	it returns c.
	If c is neither an unsigned char value nor EOF, the behavior of these
	functions is undefined.
RETURN VALUE
	The value returned is that of the converted letter,
	or c if the conversion was not possible.
*/

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	return (c);
}
