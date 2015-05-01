#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "item.h"

typedef struct node NODE;
typedef struct avltree AVLTREE;

struct node {
	ITEM *item;
	struct node *lchild;
	struct node *rchild;
};

struct avltree {
	NODE *root;
};

AVLTREE *avltree_new(void);

void avltree_free(AVLTREE **tree);

bool avltree_insert(AVLTREE *tree, ITEM *item);

ITEM *avltree_remove(AVLTREE *tree, int key);

ITEM *avltree_search(AVLTREE *tree, int key);

bool is_empty(AVLTREE *tree);

void print_preorder(AVLTREE *tree);

void print_postorder(AVLTREE *tree);

void print_endorder(AVLTREE *tree);

#endif
