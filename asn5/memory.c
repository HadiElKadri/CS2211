#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
/**
 * Author: Hadi El-Kadri
 */

//Initialize bst and memory array
static unsigned char *memory;
static BStree bst;

// Input: 'size': size of unsigned char array
// Effect: initializes an unsigned char array of size elements and initializes a bst
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}

// Input: 'size': number of bytes to be allocated
// Effect: Returns a pointer to the first byte allocated
void *simu_malloc(unsigned int size) {

    //Find a key in the bst with enough bytes to accommodate the input size + 4 bytes to write the size
    int *key = bstree_data_search(bst, size + 4);

    //If there is no key in the bst with enough return null
    if (key == NULL) return NULL;

    //Get the exact amount of bytes at the found key
    int *data = bstree_search(bst,*key);
    //Initialize variables to = the dereference pointers
    int k = *key;
    int d = *data;
    //Delete the node with the key from the bst
    bstree_delete(bst, *key);
    //Allocate the bytes into the appropriate index of the memory array
    *(unsigned int*)(&memory[k]) = size;
    //Check to see if any unused bytes are left over, if so insert new key and the amount back into bst
    if(d - (size + 4) > 0){
        bstree_insert(bst, (k + 4 + size), (d - (size + 4)));
    }
    //Return a pointer to the first byte allocated
    return &memory[k + 4];
}

// Input: '*ptr': pointer to allocated memory to be freed
// Effect: The allocated memory pointed by ptr will be put back as free memory
void simu_free(void *ptr) {

    //Get the index of the memory's location
    int index = (unsigned char*)ptr - memory;
    //Get key
    int key = index - 4;
    //Get the data that is stored in the first 4 bytes
    int newsize = *(unsigned int*)(ptr - 4);
    //Insert the key and the data back into the bst
    bstree_insert(bst,key, newsize);
}

// Input:
// Effect: Prints all the free blocks of memory
void mem_print(void) {
    bstree_traversal(bst);
}

// Input:
// Effect: Frees memory used for bst and the array
void mem_free(void) {
    bstree_free(bst);
    free(memory);
}
