#include "shell.h"

/**
 * get_environ - Ka traja3 string array copy dyal environ dyalna
 * @nft: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Dima 0
*/
char **get_environ(info_t *nft)
{
	if (!nft->environ || nft->env_changed)
	{
		nft->environ = list_to_strings(nft->env);
		nft->env_changed = 0;
	}

	return (nft->environ);
}

/**
 * _unsetenv - Ka t7ayd environment variable
 * @nft: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @enviroVar: lstring enviro enviroVar property
 * Return: 1 on delete, 0 otherwise
*/
int _unsetenv(info_t *nft, char *enviroVar)
{
	list_t *node = nft->env;
	size_t size = 0;
	char *p;

	if (!node || !enviroVar)
		return (0);

	while (node)
	{
		p = starts_with(node->str, enviroVar);
		if (p && *p == '=')
		{
			nft->env_changed = delete_node_at_index(&(nft->env), size);
			size = 0;
			node = nft->env;
			continue;
		}
		node = node->next;
		size++;
	}

	return (nft->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @nft: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @enviroVar: lstring enviro enviroVar property
 * @val: lstring env enviroVar val
 *  Return: Dima 0
*/
int _setenv(info_t *nft, char *enviroVar, char *val)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!enviroVar || !val)
		return (0);

	buf = malloc(_strlen(enviroVar) + _strlen(val) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, enviroVar);
	_strcat(buf, "=");
	_strcat(buf, val);
	node = nft->env;
	while (node)
	{
		p = starts_with(node->str, enviroVar);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			nft->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(nft->env), buf, 0);
	free(buf);
	nft->env_changed = 1;

	return (0);
}

