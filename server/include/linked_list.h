/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Linked List
*/

#ifndef MYIRC_LIST_H
#define MYIRC_LIST_H

	#include <sys/types.h>
	#include <stdbool.h>

	typedef struct list_s list_t;
	typedef struct iter_s iter_t;
	typedef void *ptr_t;
	typedef void (*free_callback_t)(ptr_t);
	typedef bool (*predicate_t)(void *data);

	#define iter_begin(list_ptr) ((list_ptr)->begin)
	#define iter_next(it_ptr) ((it) = (it)->next)
	#define iter_value(it_ptr) ((it)->data)
	#define list_init (list_t) {NULL, NULL, 0}

	#define ERROR_OUTOFBOUND ("list_at error: index %zu out of bound, list size: %zu\n")
	#define ERROR_NULL ("data_null_check: NULL pointer cant be added or removed from a list\n")

	struct iter_s {
		ptr_t data;
		iter_t *next;
	};

	struct list_s {
		iter_t *begin;
		iter_t *end;
		size_t size;
	};

	list_t *list_new();
	void list_add(list_t *, ptr_t);
	void list_remove(list_t *, ptr_t);
	ptr_t list_at(list_t *, size_t);
	void list_clear(list_t *, free_callback_t);
	void list_insert(list_t *, ptr_t, predicate_t);
#endif
