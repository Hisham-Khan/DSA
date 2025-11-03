#ifndef LINKED_LIST_H
#define LINKED_LIST_H

/**
 * LinkedList_InitializeList - Initialize the linked list with the first node
 * @data: Value to store in the first node
 * 
 * Return: 0 on success, -1 if already initialized, -2 on memory allocation failure
 */
int LinkedList_InitializeList(int data);

/**
 * LinkedList_CreateNodeAtStart - Insert a new node at the beginning of the list
 * @data: Value to store in the new node
 * 
 * Return: 0 on success, -2 on memory allocation failure
 */
int LinkedList_CreateNodeAtStart(int data);

/**
 * LinkedList_CreateNodeAtEnd - Insert a new node at the end of the list
 * @data: Value to store in the new node
 * 
 * Return: 0 on success, -2 on memory allocation failure
 */
int LinkedList_CreateNodeAtEnd(int data);

/**
 * LinkedList_SearchList - Search for a node with the given key
 * @key: Value to search for in the list
 * 
 * Return: 0 if found, -1 if not found
 */
int LinkedList_SearchList(int key);

/**
 * LinkedList_DeleteNode - Delete the first node with the given key
 * @key: Value of the node to delete
 * 
 * Return: 0 on success, -1 if list is empty or key not found
 */
int LinkedList_DeleteNode(int key);

/**
 * LinkedList_InsertNode - Insert a new node after the node with the given key
 * @key: Value of the node after which to insert
 * @data: Value to store in the new node
 * 
 * Return: 0 on success, -1 if list is empty or key not found, -2 on memory allocation failure
 */
int LinkedList_InsertNode(int key, int data);

/**
 * LinkedList_DisplayList - Display all nodes in the list
 * 
 * Prints the list in format: data1 -> data2 -> ... -> NULL
 */
void LinkedList_DisplayList(void);

/**
 * LinkedList_DestroyList - Free all nodes and reset the list
 * 
 * Deallocates memory for all nodes and sets head to NULL
 */
void LinkedList_DestroyList(void);

#endif // LINKED_LIST_H