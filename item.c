#include "item.h"
#include <stdlib.h>
#include <stdio.h>

ITEM *item_new(int key, int value)
{
	ITEM *new_item = (ITEM *) malloc(sizeof(ITEM));
	if (new_item == NULL) {
		fprintf(stderr, "ERROR: not enough memory\n");
		return NULL;
	}

	new_item->key = key;
	new_item->value = value;
	return new_item;
}

void item_free(ITEM **item)
{
	if (item == NULL || *item == NULL) {
		fprintf(stderr, "ERROR: null pointer at item_free\n");
		return;
	}

	free(*item);
	*item = NULL;
}

void item_print(ITEM *item)
{
	if (item == NULL) {
		fprintf(stderr, "ERROR: null pointer at item_print.\n");
		return;
	}

	printf("key: %d\tvalue: %d\n", item->key, item->value);
}
