//
// Created by Hadi on 11/14/2019.
//

#ifndef ASN4_BST_H
#define ASN4_BST_H
#include "data.h"
typedef struct {Node *tree_nodes; unsigned int *free_nodes;
    int size; int top; int root;} BStree_struct;
typedef BStree_struct* BStree;
BStree bstree_ini(int size);
void bstree_insert(BStree bst, Key *key, Data data);
void bstree_traversal(BStree bst);
void bstree_free(BStree bst);
void bst_insert(BStree bst, int node_index, Key *key, Data data);
void bst_traversal(int node_index, BStree bst);
#endif //ASN4_BST_H
