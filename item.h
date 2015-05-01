#ifndef ITEM_H
#define ITEM_H

typedef struct item ITEM;
struct item {
	int key;
	int value;
};

ITEM *item_new(int key, int value);

void item_free(ITEM **item);

void item_print(ITEM *item);

#endif
