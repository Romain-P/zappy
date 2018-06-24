/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Linked List Utils
*/

#include "linked_list.h"
#include "stderr.h"

void check_nullity(list_t *list)
{
	if (list)
		return;
	raise_errnum("list_check_null", EFAULT);
}

void check_data_nullity(ptr_t data)
{
	if (data)
		return;
	raise_error(ERROR_NULL);
}

bool list_exists(list_t *list, ptr_t data)
{
	iter_t *it;

	check_nullity(list);
	check_data_nullity(data);
	for (it = iter_begin(list); it; iter_next(it))
		if (it->data == data)
			return (true);
	return (false);
}

list_t *list_new(void)
{
	list_t *list = malloc(sizeof(list_t));

	if (list == NULL)
		exit(84);
	if (!list)
		raise_errnum("list_new", ENOMEM);
	list->size = 0;
	list->begin = NULL;
	list->end = NULL;
	return (list);
}

void set_new(list_t *list, iter_t *current, iter_t *before, ptr_t data)
{
	iter_t *new = malloc(sizeof(*new));

	if (!new)
		raise_errnum("list_insert", ENOMEM);
	new->data = data;
	new->next = current;
	if (!before)
		list->begin = new;
	else
		before->next = new;
	list->size++;
}