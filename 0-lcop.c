#include "shell.h"

/**
 * _strncpy - Kat copi string
 * @lwijha: lwijha string li ghada tcopa liha
 * @lmassdar: lmassdar dyal string
 * @n: l3adad dyal characters li ghadi itcopiaw
 * Return: Ka traja3 concatenated string
*/
char *_strncpy(char *lwijha, char *lmassdar, int n)
{
	int i, j;
	char *s = lwijha;

	i = 0;
	while (lmassdar[i] != '\0' && i < n - 1)
	{
		lwijha[i] = lmassdar[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			lwijha[j] = '\0';
			j++;
		}
	}

	return (s);
}

/**
 * _strncat - katjm3 jouj dyal strings
 * @lwijha: string lwla
 * @lmassdar: string tania
 * @n: l3adad dyal lbytes to be maximally used
 * Return: the concatenated string
*/
char *_strncat(char *lwijha, char *lmassdar, int n)
{
	int i, j;
	char *s = lwijha;

	i = 0;
	j = 0;
	while (lwijha[i] != '\0')
		i++;
	while (lmassdar[j] != '\0' && j < n)
	{
		lwijha[i] = lmassdar[j];
		i++;
		j++;
	}
	if (j < n)
		lwijha[i] = '\0';

	return (s);
}

/**
 * _strchr - t7aded blast chi character wesst string
 * @s: the string li ghada tmss7
 * @ch: the character li ghadi n9albo 3lih
 * Return: (s) a pointer to the memory area s
*/
char *_strchr(char *s, char ch)
{
	do {
		if (*s == ch)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

