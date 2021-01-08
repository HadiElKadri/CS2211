#include <stdio.h>
#include "bst.h"
#include <string.h>
#include <stdlib.h>
#include "memory.h"
#include "list.h"
#include "datatype.h"
/*
 *Author : Hadi El-Kadri 
 */
int main(){

    //Read in the size of the dynamic memory allocation and deallocation system
    int memory;
    printf("Please enter the amount of memory needed: \n");
    scanf("%d", &memory);

    //Initialize the dynamic memory allocation and deallocation system
    mem_ini(memory);

    //Initialize a linked list
    List linkedlist;
    linkedlist = list_ini();

    int integer;
    printf("Please enter integer numbers one by one. (repeating is allowed) (CNTRL-D to finish): \n");
    while(scanf("%d", &integer) > 0){
        if(list_search(linkedlist, integer) == NULL){
            list_add(linkedlist, integer, 1);
        }

        else{
            int frequency = *list_search(linkedlist, integer);
            list_delete(linkedlist, integer);
            list_add(linkedlist, integer, frequency+1);
        }
    }

    printf("Integer\t\t\tOccurence\n");
    list_print(linkedlist);
    list_free(linkedlist);
    mem_free();
}
