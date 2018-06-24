/*
** EPITECH PROJECT, 2018
** linked_list
** File description:
** linked_list.c
*/

#include "linked_list.h"
#include "stderr.h"
#include <stdlib.h>
#include <stdio.h>

static void check_nullity(list_t *list) {
	if (list) return;
	raise_errnum("list_check_null", EFAULT);
}

static void check_data_nullity(ptr_t data) {
	if (data) return;
	raise_error(ERROR_NULL);
}

list_t *list_new(void) {
	list_t *list = malloc(sizeof(list_t));

	if (!list)
		raise_errnum("list_new", ENOMEM);
	list->size = 0;
	list->begin = NULL;
	list->end = NULL;
	return list;
}

void list_add(list_t *list, ptr_t data) {
	check_nullity(list);
	check_data_nullity(data);

	iter_t *new = malloc(sizeof(iter_t));
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

void list_remove(list_t *list, ptr_t data) {
	check_nullity(list);
	check_data_nullity(data);

	for (iter_t *it = list->begin, *prev = NULL; it; prev = it,
		it = it->next) {
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

ptr_t list_at(list_t *list, size_t index) {
	check_nullity(list);
	if (index >= list->size)
		goto error;
	else if (index == 0)
		return list->begin->data;
	else if (index == list->size - 1)
		return list->end->data;

	iter_t *it = iter_begin(list);
	for (size_t i = 0; i < index; ++i)
		iter_next(it);
	return it->data;

error:
	raise_error(ERROR_OUTOFBOUND, index, list->size);
}

ptr_t list_pop(list_t *list) {
	check_nullity(list);
	if (list->size == 0)
		return NULL;
	iter_t *pop = iter_begin(list);
	list->begin = pop->next;
	ptr_t data = pop->data;
	free(pop);
	list->size--;
	return (data);
}

void list_clear(list_t *list, free_callback_t free_it) {
	check_nullity(list);
	iter_t *it = list->begin;
	iter_t *next;

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

void list_insert(list_t *list, ptr_t data, predicate_t predicate) {
	check_nullity(list);
	check_data_nullity(data);

	iter_t *before = NULL;
	iter_t *current = NULL;
	for (iter_t *it = iter_begin(list); it; before = it, iter_next(it)) {
		if (predicate(it->data)) {
			current = it;
			break;
		}
	}
	if (!list->size || current == NULL || current == list->end) {
		list_add(list, data);
		return;
	}
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

bool list_exists(list_t *list, ptr_t data) {
	check_nullity(list);
	check_data_nullity(data);
	for (iter_t *it = iter_begin(list); it; iter_next(it))
		if (it->data == data)
			return true;
	return false;
}
