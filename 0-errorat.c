#include "shell.h"

/**
 * _eputs - Ka tktb wa7ed linput string
 * @trs: String
 * Return: Ka traja3 void function
*/
void _eputs(char *trs)
{
	int i = 0;

	if (!trs)
		return;
	while (trs[i] != '\0')
	{
		_eputchar(trs[i]);
		i++;
	}
}

/**
 * _eputchar - Tktb lcharacter ch to stderr
 * @ch: Character
 * Return: Ka traja3 1 ila kan success, chi 7aja khra ka traja3 -1
*/
int _eputchar(char ch)
{
	static int i;
	static char buuf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buuf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buuf[i++] = ch;

	return (1);
}

/**
 * _putfd - Ka tktb lcharacter ch ldossi li m3ti
 * @ch: Character
 * @dossi: Integer
 * Return: Ka trj3 1 ila kan success, chi 7aja khra katrj3 -1
*/
int _putfd(char ch, int dossi)
{
	static int i;
	static char buuf[WRITE_BUF_SIZE];

	if (ch == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(dossi, buuf, i);
		i = 0;
	}
	if (ch != BUF_FLUSH)
		buuf[i++] = ch;

	return (1);
}

/**
 * _putsfd - Tba3 an input string
 * @trs: String
 * @dossi: Integer
 * Return: Ka trj3 number of chars put
*/
int _putsfd(char *trs, int dossi)
{
	int i = 0;

	if (!trs)
		return (0);
	while (*trs)
	{
		i += _putfd(*trs++, dossi);
	}

	return (i);
}

