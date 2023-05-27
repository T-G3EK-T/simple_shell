#include "shell.h"

/**
 * _myenv - Ka tprinti environment l7alia
 * @nft: Structure
 * Return: Dima ka traja3 0
*/
int _myenv(info_t *nft)
{
	print_list_str(nft->env);

	return (0);
}

/**
 * _getenv - Ka takhod lvalue dyal env variable
 * @nft: Structure
 * @smia: Const charactere
 * Return: Ka traja3 lvalue
*/
char *_getenv(info_t *nft, const char *smia)
{
	list_t *node = nft->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, smia);
		if (p && *p)
			return (p);
		node = node->next;
	}

	return (NULL);
}

/**
 * _mysetenv - Katinitializi ola ka tmodify wa7ed lenvironment variable
 * @nft: Structure
 * Return: Dima ka traje3 0
*/
int _mysetenv(info_t *nft)
{
	if (nft->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(nft, nft->argv[1], nft->argv[2]))
		return (0);

	return (1);
}

/**
 * _myunsetenv - Kat7ayed environment variable
 * @nft: Structure
 * Return: Dima ka traje3 0
*/
int _myunsetenv(info_t *nft)
{
	int i;

	if (nft->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= nft->argc; i++)
		_unsetenv(nft, nft->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates enviro linked list
 * @nft: Structure
 * Return: Dima ka traje3 0
*/
int populate_env_list(info_t *nft)
{
	list_t *node = NULL;
	size_t size;

	for (size = 0; environ[size]; size++)
		add_node_end(&node, environ[size], 0);
	nft->env = node;

	return (0);
}

    