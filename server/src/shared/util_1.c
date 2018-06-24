/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Utils
*/

#include "util.h"

bool check_str_needle(char const *str, size_t len,
	char const *needle, size_t nsize)
{
	bool found_one = false;
	int i;

	for (i = 0; i < nsize; ++i) {
		if (str[len] == needle[i])
			found_one = true;
	}
	if (!found_one)
		return (false);
	return (true);
}

bool charset_ends_with(char const *str, size_t len, char const *needle)
{
	size_t nsize = strlen(needle);
	bool value;

	if (len < nsize)
		return false;
	do {
		len -= 1;
		if (strncmp(str + len, needle, nsize) != 0) {
			value = check_str_needle(str, len, needle, nsize);
		} else
			return (true);
		if (value == false)
			return (false);
	} while (len >= 0);
	return (false);
}

size_t str_array_length(char **array)
{
	size_t i = 0;

	for (; array && array[i]; i++);
	return (i);
}

void str_free_array(char **array)
{
	if (!array)
		return;
	for (int i = 0; array[i]; ++i)
		free(array[i]);
	free(array);
}

bool parse_int(char const *str, int64_t *ptr)
{
	char *end;

	*ptr = strtol(str, &end, 0);
	return (end == str + strlen(str));
}