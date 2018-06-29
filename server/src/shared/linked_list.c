/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Linked List
*/

#include "linked_list.h"
#include "stderr.h"

void list_add(list_t *list, ptr_t data)
{
	iter_t *new = malloc(sizeof(iter_t));

	check_nullity(list);
	check_data_nullity(data);
	if (!new)
		raise_errnum("list_add", ENOMEM);
	new->data = data;
	new->next = NULL;
	if (!list->end) {
		list->begin = new;
		list->end = new;
	} else {
		list->end->next = new;
		list->end = new;
	}
	list->size++;
}

void list_remove(list_t *list, ptr_t data)
{
	check_nullity(list);
	check_data_nullity(data);
	for (iter_t *it = list->begin, *prev = NULL;
	it; prev = it, it = it->next) {
		if (it->data != data)
			continue;
		if (it == list->begin)
			list->begin = it->next;
		else
			prev->next = it->next;
		if (it == list->end)
			list->end = prev;
		free(it);
		list->size--;
		break;
	}
}

ptr_t list_at(list_t *list, size_t index)
{
	iter_t *it;
	size_t i = 0;

	check_nullity(list);
	if (index >= list->size) {
		raise_error(ERROR_OUTOFBOUND, index, list->size);
	} else {
		if (index == 0)
			return list->begin->data;
		if (index == list->size - 1)
			return list->end->data;
		it = iter_begin(list);
		for (i = 0; i < index; ++i)
			iter_next(it);
		return (it->data);
	}
}

void list_clear(list_t *list, free_callback_t free_it)
{
	iter_t *next;
	iter_t *it;

	check_nullity(list);
	it = list->begin;
	while (it) {
		next = it->next;
		if (free_it)
			free_it(it->data);
		free(it);
		it = next;
	}
	list->begin = NULL;
	list->end = NULL;
	list->size = 0;
}

void list_insert(list_t *list, ptr_t data, predicate_t predicate)
{
	iter_t *before = NULL;
	iter_t *current = NULL;
	iter_t *it;

	check_nullity(list);
	check_data_nullity(data);
	for (it = iter_begin(list); it; iter_next(it)) {
		if (predicate(it->data)) {
			current = it;
			break;
		}
		before = it;
	}
	if (!list->size || current == NULL) {
		list_add(list, data);
		return;
	}
	set_new(list, current, before, data);
}