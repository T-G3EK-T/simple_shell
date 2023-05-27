#include "shell.h"

/**
 * input_buf - buffers chained commandat
 * @nft: parameter struct
 * @buuf: addrissa dyal buffer
 * @toul: addrissa dyal toul var
 * Return: bytes read
*/
ssize_t input_buf(info_t *nft, char **buuf, size_t *toul)
{
	ssize_t r = 0;
	size_t toul_p = 0;

	if (!*toul)
	{
		free(*buuf);
		*buuf = NULL;
		signal(SIGINT, sigintHandler);
		#if USE_GETLINE
				r = getline(buuf, &toul_p, stdin);
		#else
				r = _getline(nft, buuf, &toul_p);
		#endif
		if (r > 0)
		{
			if ((*buuf)[r - 1] == '\n')
			{
				(*buuf)[r - 1] = '\0';
				r--;
			}
			nft->linecount_flag = 1;
			remove_comments(*buuf);
			build_history_list(nft, *buuf, nft->histcount++);
			{
				*toul = r;
				nft->cmd_buf = buuf;
			}
		}
	}

	return (r);
}

/**
 * get_input - takhod star na9iss star jdid
 * @nft: parameter struct
 * Return: bytes read
*/
ssize_t get_input(info_t *nft)
{
	static char *buuf;
	static size_t i, j, toul;
	ssize_t r = 0;
	char **buuf_p = &(nft->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(nft, &buuf, &toul);
	if (r == -1) /* EOF */
		return (-1);
	if (toul)
	{
		j = i;
		p = buuf + i;

		check_chain(nft, buuf, &j, i, toul);
		while (j < toul)
		{
			if (is_chain(nft, buuf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= toul)
		{
			i = toul = 0;
			nft->cmd_buf_type = CMD_NORM;
		}

		*buuf_p = p;

		return (_strlen(p));
	}

	*buuf_p = buuf;

	return (r);
}

/**
 * read_buf - reads a buffer
 * @nft: parameter struct
 * @buf: buffer
 * @i: size
 * Return: r
*/
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;

	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: addrissa dyal pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 * Return: s
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;

	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 * Return: void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

