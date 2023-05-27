#include "shell.h"

/**
 * clear_info - ka tinitializi info_t struct
 * @nft: struct addrissa
*/
void clear_info(info_t *nft)
{
	nft->arg = NULL;
	nft->argv = NULL;
	nft->path = NULL;
	nft->argc = 0;
}

/**
 * set_info - ka tinitializi info_t struct
 * @nft: struct addrissa
 * @av: argument vector
*/
void set_info(info_t *nft, char **av)
{
	int i = 0;

	nft->fname = av[0];
	if (nft->arg)
	{
		nft->argv = strtow(nft->arg, " \t");
		if (!nft->argv)
		{
			nft->argv = malloc(sizeof(char *) * 2);
			if (nft->argv)
			{
				nft->argv[0] = _strdup(nft->arg);
				nft->argv[1] = NULL;
			}
		}
		for (i = 0; nft->argv && nft->argv[i]; i++)
			;
		nft->argc = i;

		replace_alias(nft);
		replace_vars(nft);
	}
}

/**
 * free_info - katkhwi info_t struct fields
 * @nft: struct address
 * @kolchi: s7i7 ila tkhwaw ga3 lfields
*/
void free_info(info_t *nft, int kolchi)
{
	ffree(nft->argv);
	nft->argv = NULL;
	nft->path = NULL;
	if (kolchi)
	{
		if (!nft->cmd_buf)
			free(nft->arg);
		if (nft->env)
			free_list(&(nft->env));
		if (nft->history)
			free_list(&(nft->history));
		if (nft->alias)
			free_list(&(nft->alias));
		ffree(nft->environ);
			nft->environ = NULL;
		bfree((void **)nft->cmd_buf);
		if (nft->readfd > 2)
			close(nft->readfd);
		_putchar(BUF_FLUSH);
	}
}

