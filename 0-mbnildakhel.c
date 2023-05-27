#include "shell.h"

/**
 * _myexit - Bach tkhroj men shell
 * @nft: Structure
 * Return: Tkhroj blexit status li m3ti
*/
int _myexit(info_t *nft)
{
	int chkExit;

	if (nft->argv[1]) /* Ila kan chi argument dyal khrouj */
	{
		chkExit = _erratoi(nft->argv[1]);
		if (chkExit == -1)
		{
			nft->status = 2;
			print_error(nft, "Illegal number: ");
			_eputs(nft->argv[1]);
			_eputchar('\n');
			return (1);
		}
		nft->err_num = _erratoi(nft->argv[1]);
		return (-2);
	}
	nft->err_num = -1;

	return (-2);
}

/**
 * _mycd - Ka tbedel directory lifiha 7alian
 * @nft: Structure
 * Return: Dima katraja3 0
*/
int _mycd(info_t *nft)
{
	char *str, *directory, buffer[1024];
	int dirRet;

	str = getcwd(buffer, 1024);
	if (!str)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!nft->argv[1])
	{
		directory = _getenv(nft, "HOME=");
		if (!directory)
			dirRet = chdir((directory = _getenv(nft, "PWD=")) ? directory : "/");
		else
			dirRet = chdir(directory);
	}
	else if (_strcmp(nft->argv[1], "-") == 0)
	{
		if (!_getenv(nft, "OLDPWD="))
		{
			_puts(str);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(nft, "OLDPWD=")), _putchar('\n');
		dirRet = chdir((directory = _getenv(nft, "OLDPWD=")) ? directory : "/");
	}
	else
		dirRet = chdir(nft->argv[1]);
	if (dirRet == -1)
	{
		print_error(nft, "can't cd to ");
		_eputs(nft->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(nft, "OLDPWD", _getenv(nft, "PWD="));
		_setenv(nft, "PWD", getcwd(buffer, 1024));
	}

	return (0);
}

/**
 * _myhelp - Ka t3awn
 * @nft: Structure
 * Return: Dima 0
*/
int _myhelp(info_t *nft)
{
	char **argArray;

	argArray = nft->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argArray);

	return (0);
}

