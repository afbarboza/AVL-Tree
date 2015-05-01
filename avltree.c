#include "avltree.h"

static void free_nodes(NODE **node);
static NODE *item_search(NODE *node, int key);

static void traversal_preorder(NODE *node);
static void traversal_endorder(NODE *node);
static void traversal_postorder(NODE *node);

AVLTREE *avltree_new(void)
{
	AVLTREE *tree =(AVLTREE *) malloc(sizeof(AVLTREE));
	if (tree == NULL) {
		fprintf(stderr, "ERROR: not enough memory.\n");
		return NULL;
	}

	tree->root = NULL;
	return tree;
}

void avltree_free(AVLTREE **tree)
{
	free_nodes(&((*tree)->root));
	free(*tree);
	*tree = NULL;
}

bool avltree_insert(AVLTREE *tree, ITEM *item);

ITEM *avltree_remove(AVLTREE *tree, int key);

ITEM *avltree_search(AVLTREE *tree, int key)
{
	if (tree == NULL) {
		fprintf(stderr, "ERROR: null pointer.\n");
		return;
	}

	ITEM *lookup = item_search(tree->root, key);
	return lookup;
}

inline bool is_empty(AVLTREE *tree)
{
	return ((tree->root == NULL) ? true : false);
}

void print_preorder(AVLTREE *tree);

void print_postorder(AVLTREE *tree);

void print_endorder(AVLTREE *tree);

static NODE *item_search(NODE *node, int key)
{
	if (node == NULL) {
		return NULL;	
	} else if (key == node->key) {
		return node;
	} else if (key < node->key) {
		/*search at the left subtree, recursively*/
		return item_search(node->lchild, key);
	} else {
		/*search at the right subtree, recursively*/
		return item_search(node->rchild, key);
	}
}

static void free_nodes(NODE **node)
{
	if (node == NULL || *node == NULL) {
		return;
	}

	free_nodes(&((*node)->lchild));
	free_nodes(&((*node)->rchild));
	free(&((*node)->item));
	free(*node);
	*node = NULL;
	return;
}

static void traversal_preorder(NODE *node)
{
	if (node == NULL)
		return;
	item_print(node->item);
	traversal_preorder(node->lchild);
	traversal_preorder(node->rchild);
}

static void traversal_endorder(NODE *node)
{
	if (node == NULL)
		return;

	traversal_endorder(node->lchild);
	traversal_endorder(node->rchild);
	item_print(node->item);
}

static void traversal_postorder(NODE *node)
{
	if (node == NULL)
		return;
	traversal_postorder(node->lchild);
	item_print(node->item);
	traversal_postorder(node->rchild);
}
