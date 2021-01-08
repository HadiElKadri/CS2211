#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"
/**
 * Author Hadi El-Kadri
 */

// Effect: Initiates a linked list
List list_ini(void) {
    //Head is a list node with no data
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) );
	//Set the next node to null
	head->next = NULL;
	return head;
}

// Input: 'list': a linked list, 'key' : a input key to be searched for
// Effect: returns NULL if the key is not in the linked list or a pointer to data of the key if it is in the linked list
Data *list_search(List list, Key key) {
    //If the list is empty or has reached the end return NULL
    if(list == NULL) return NULL;
    //If the key is equal to a key in a node in the list return address of associated data
    if(key_comp(list->key, key) == 0){
        return &(list->data);
    }
    //Recursively search each node in the list
    else return list_search(list->next, key);
}

// Input: 'list': linked list, 'key': key to be added to list, 'data': data to be added in correspondence
// Effect: a node with the input key and data will be added into the linked list at the front if it is not already in it
void list_add(List list, Key key, Data data) {
    // Search the list to see if the key is in it
    if(list_search(list,key) == NULL){
        //If not in the tree create a node to store the key and data in and insert it
        List_node *head = (List_node *) simu_malloc( sizeof(List_node) );
        head->key = key;
        head->data = data;
        head->next = list->next;
        list->next = head;
    }
}

// Input: 'list': linked list, 'key': key to be searched for in the list and deleted
// Effect: The key will be searched for in the linked list and if it is found, will be deleted
void list_delete(List list, Key key) {
    //Make temporary nodes to search through the list
    List_node *current = list;
    List_node *temp = list->next;

    //Check to see if the key is in the list, delete and free memory if it is not
    while(temp != NULL) {
        if (key_comp(temp->key, key) == 0){
            current->next = temp->next;
            simu_free(temp);
            return;
        }
        //Iterate through the list
        current = current->next;
        temp = temp->next;
    }
    }

// Input: 'list': linked list
// Effect: Print the every key with associated data in the linked list
void list_print(List list) {
    //Check to make sure the list is not empty
    if(list->next != NULL){
	    key_print(list->next->key);
            data_print(list->next->data);
            list_print(list->next);
        }
}

// Input: 'list': linked list
// Effect: free memory used in the linked list
void list_free(List list) {
    if (list != NULL) {
        list_free(list->next);
        simu_free(list);
    }
}
