//
// Created by romain on 26/05/18.
//

#include "util.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

char **charset_split(char const *str, size_t len, char const *delimiter) {
    if (!str) return NULL;

    char cpy[len + 1];
    strncpy(cpy, str, len);
    cpy[len] = 0;

    char *saved;
    ssize_t i = 0;
    char **tab = malloc(sizeof(char *) * 2);

    for (char *token = strtok_r(cpy, delimiter, &saved); token; token = strtok_r(NULL, delimiter, &saved), i++) {
        if (i)
            tab = realloc(tab, sizeof(char *) * (i + 2));
        tab[i] = strdup(token);
    }
    tab[i] = NULL;
    return tab;
}

bool charset_ends_with(char const *str, size_t len, char const *needle) {
    size_t nsize = strlen(needle);
    if (len < nsize)
        return false;

    do {
        len -= 1;
        if (strncmp(str + len, needle, nsize) != 0) {
            bool found_one = false;
            for (int i = 0; i < nsize; ++i)
                if (str[len] == needle[i])
                    found_one = true;
            if (!found_one)
                return false;
        } else
            return true;
    } while (len >= 0);

    return false;
}

size_t str_array_length(char **array) {
    size_t i = 0;
    for (; array && array[i]; i++);
    return i;
}

void str_free_array(char **array) {
    if (!array) return;
    for (int i = 0; array[i]; ++i)
        free(array[i]);
    free(array);
}

bool parse_int(char const *str, int64_t *ptr)
{
    char *end;

    *ptr = strtoul(str, &end, 0);
    return end == str + strlen(str);
}

bool parse_uint(char const *str, uint32_t *ptr)
{
    char *end;

    *ptr = (uint32_t) strtoul(str, &end, 0);
    return end == str + strlen(str);
}


char *to_string(int i) {
    static char str[100];
    sprintf(str, "%d", i);
    char *allocated = malloc(sizeof(char) * strlen(str));
    strcpy(allocated, str);
    return allocated;
}
