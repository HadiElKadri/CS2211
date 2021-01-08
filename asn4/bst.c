//
// Created by Hadi on 11/14/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Input: ’size’: size of an array
// Output: a pointer of type BStree,
// i.e. a pointer to an allocated memory of BStree_struct type
// Effect: dynamically allocate memory of type BStree_struct
// allocate memory for a Node array of size+1 for member tree_nodes
// allocate memory for an unsigned int array of size+1 for member free_nodes
// set member size to ’size’;
// set entry free_nodes[i] to i
// set member top to 1;
// set member root to 0;
BStree bstree_ini(int size) {
    BStree bst = (BStree_struct *) malloc(sizeof(BStree_struct));
    bst->tree_nodes = (Node *) malloc(((size + 1) * sizeof(Node)));
    bst->free_nodes = (unsigned int *) malloc((size + 1) * sizeof(int));
    for(int i = 0; i <= size; i ++){
        bst->free_nodes[i] = i;
    }
    bst->size = size;
    bst->top = 1;
    bst->root = 0;
    return bst;
}
// Input: ’bst’: a binary search tree
// ’key’: a pointer to Key
// ’data’: an integer
// Effect: ’data’ with ’key’ is inserted into ’bst’
// if ’key’ is already in ’bst’, do nothing
void bstree_insert(BStree bst, Key *key, Data data) {
    //Calls the helper method insert to insert the key and data into bst
    bst_insert(bst, 1, key, data);
}
// Input: ’bst’: a binary search tree
// Effect: print all the nodes in bst using in order traversal
void bstree_traversal(BStree bst) {
    bst_traversal(1,bst);

}
// Input: ’bst’: a binary search tree
// Effect: all dynamic memory used by bst are freed
void bstree_free(BStree bst) {

    // Frees the tree_nodes array
    free(bst->tree_nodes);

    // Frees the free_nodes array
    free(bst->free_nodes);

    // Frees the entire binary search tree bst
    free(bst);

    // Iterates through tree_nodes array
    for(int i = 0; i < bst->size; i++){

        // Checks the nodes that contain information only
        if(bst->free_nodes[i] != 1){

            // Frees the keys name at each index i in the tree_nodes array that has a key name
            free(bst->tree_nodes[i].key->name);
        }

        // Frees nodes key in the array[index i]
        free(bst->tree_nodes[i].key);
    }
}

void bst_insert(BStree bst, int node_index, Key *key, Data data) {
    //Checks to see if the given index is out of bounds
    if (node_index < 0 || node_index > bst->size)
    {
        printf("Array out of bounds error. \n");
        return;
    }

    if (bst->free_nodes[node_index] == 1) {
        //Gives the node key and data
        bst->tree_nodes[node_index].key = key;
        bst->tree_nodes[node_index].data = data;

        // Index set to 0 as a new node is has taken the space
        bst->free_nodes[node_index] = 0;
    }
    else {
        if (key_comp(key, bst->tree_nodes[node_index].key) < 0 ) {
            bst_insert(bst, bst->tree_nodes[node_index].left, key, data);
        }
        else if (key_comp(key, bst->tree_nodes[node_index].key) > 0 ){
            bst_insert(bst, bst->tree_nodes[node_index].right, key, data);
        }
        else if (key_comp(key, (bst->tree_nodes[node_index].key)) == 0){
            return;
        }
        }
    }

void bst_traversal(int node_index, BStree bst)
{
    //Checks if the array is out of bounds and returns nothing if it is
    if (node_index > (bst->size) || node_index < 0 || bst->free_nodes[node_index] == 1); return;

    //Recursively call traversal to in order traverse the left side of the bst
    bst_traversal(2 * node_index, bst);

    //Prints the key and node from the index using the print_node function
    print_node(bst->tree_nodes[node_index]);

    //Recursively call traversal to in order traverse the right side of the bst
    bst_traversal(2 * node_index + 1, bst);
}


