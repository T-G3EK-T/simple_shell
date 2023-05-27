#include "shell.h"

/**
 * interactive - Ka checki linteractive mode
 * @nft: Pointer of type info_t
 * Return: Ka traja3 1 ila kant interactive mode, 0 la makantch
*/
int interactive(info_t *nft)
{
	return (isatty(STDIN_FILENO) && nft->readfd <= 2);
}

/**
 * is_delim - Ka checki delimeter
 * @ch: Char
 * @trs: String
 * Return: Ka traja3 1 ila kant true, 0 ila kant false
*/
int is_delim(char ch, char *trs)
{
	while (*trs)
		if (*trs++ == ch)
			return (1);

	return (0);
}

/**
 * _isalpha - Ka t9alab 3la lalphabetic character
 * @ch: The character to input
 * Return: Ka traja3 1 ila ch raha alphabetic, 0 chi 7aja khra
*/
int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Ka tconverti string linteger
 * @trs: String
 * Return: Ka traja3 0 ila makan ta chi ra9m fstring, converted number fchi 7ala khra
*/
int _atoi(char *trs)
{
	int i, alama = 1, raya = 0, val;
	unsigned int res = 0;

	for (i = 0; trs[i] != '\0' && raya != 2; i++)
	{
		if (trs[i] == '-')
			alama *= -1;

		if (trs[i] >= '0' && trs[i] <= '9')
		{
			raya = 1;
			res *= 10;
			res += (trs[i] - '0');
		}
		else if (raya == 1)
			raya = 2;
	}

	if (alama == -1)
		val = -res;
	else
		val = res;

	return (val);
}

