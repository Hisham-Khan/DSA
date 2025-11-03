#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Node structure for singly linked list
 * @data: Integer value stored in the node
 * @next: Pointer to the next node in the list
 */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* Global pointer to the head of the linked list */
static Node *__head = NULL;

/**
 * LinkedList_InitializeList - Initialize the linked list with the first node
 * @data: Value to store in the first node
 * 
 * Creates the first node of the list and sets it as the head.
 * Prevents re-initialization if the list already exists.
 * 
 * Return: 0 on success, -1 if already initialized, -2 on memory allocation failure
 */
int LinkedList_InitializeList(int data)
{
    /* Check if list is already initialized */
    if (__head != NULL)
    {
        printf("List is already initialized\n");
        return -1;
    }
    
    /* Allocate memory for the first node */
    __head = (Node *)malloc(sizeof(Node));

    /* Check if memory allocation was successful */
    if(__head == NULL)
    {
        printf("Memory allocation failed\n");
        return -2;
    }

    /* Initialize the node with data and NULL next pointer */
    __head->data = data;
    __head->next = NULL;
    printf("List initialized with data %d at address %p\n", __head->data, (void *)__head);

    return 0;
}

/**
 * LinkedList_CreateNodeAtStart - Insert a new node at the beginning of the list
 * @data: Value to store in the new node
 * 
 * Creates a new node and inserts it at the start of the list by updating
 * the head pointer.
 * 
 * Return: 0 on success, -2 on memory allocation failure
 */
int LinkedList_CreateNodeAtStart(int data)
{
    /* Allocate memory for the new node */
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return -2;
    }
    
    /* Set the new node's data and link it to the current head */
    newNode->data = data;
    newNode->next = __head;
    
    /* Update head to point to the new node */
    __head = newNode;
    return 0;
}

/**
 * LinkedList_CreateNodeAtEnd - Insert a new node at the end of the list
 * @data: Value to store in the new node
 * 
 * Creates a new node and inserts it at the end of the list by traversing
 * to the last node and updating its next pointer.
 * 
 * Return: 0 on success, -2 on memory allocation failure
 */
int LinkedList_CreateNodeAtEnd(int data)
{
    Node *current = __head;
    
    /* Allocate memory for the new node */
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return -2;
    }

    /* Initialize the new node */
    newNode->data = data;
    newNode->next = NULL;

    /* If list is empty, make the new node the head */
    if (__head == NULL)
    {
        __head = newNode;
        return 0;
    }

    /* Traverse to the last node */
    while (current->next != NULL)
    {
        current = current->next;
    }

    /* Link the last node to the new node */
    current->next = newNode;
    return 0;
}

/**
 * LinkedList_SearchList - Search for a node with the given key
 * @key: Value to search for in the list
 * 
 * Traverses the list from head to tail looking for a node with
 * matching data value.
 * 
 * Return: 0 if found, -1 if not found
 */
int LinkedList_SearchList(int key)
{
    Node *current = __head;
    
    /* Traverse the list */
    while (current != NULL)
    {
        /* Check if current node contains the key */
        if (current->data == key)
        {
            return 0; /* Found */
        }
        current = current->next;
    }
    
    return -1; /* Not found */
}

/**
 * LinkedList_DeleteNode - Delete the first node with the given key
 * @key: Value of the node to delete
 * 
 * Searches for the first node with the given key and removes it from
 * the list by updating pointers. Frees the memory of the deleted node.
 * 
 * Return: 0 on success, -1 if list is empty or key not found
 */
int LinkedList_DeleteNode(int key)
{
    Node *previous = NULL;
    Node *current = __head;

    /* Check if list is empty */
    if (__head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    /* Special case: deleting the head node */
    if (current != NULL && current->data == key)
    {
        __head = current->next;
        free(current);
        return 0;
    }

    /* Traverse the list to find the node to delete */
    while (current != NULL && current->data != key)
    {
        previous = current;
        current = current->next;
    }

    /* Key not found */
    if (current == NULL)
    {
        printf("Key %d not found\n", key);
        return -1;
    }

    /* Unlink the node from the list and free it */
    previous->next = current->next;
    free(current);

    return 0;
}

/**
 * LinkedList_InsertNode - Insert a new node after the node with the given key
 * @key: Value of the node after which to insert
 * @data: Value to store in the new node
 * 
 * Searches for a node with the given key and inserts a new node
 * immediately after it.
 * 
 * Return: 0 on success, -1 if list is empty or key not found, -2 on memory allocation failure
 */
int LinkedList_InsertNode(int key, int data)
{
    Node *current = __head;
    Node* newNode;

    /* Check if list is empty */
    if (__head == NULL)
    {
        printf("List is empty\n");
        return -1;
    }

    /* Traverse the list to find the node with the given key */
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }

    /* Key not found */
    if (current == NULL)
    {
        printf("Key %d not found\n", key);
        return -1;
    }

    /* Allocate memory for the new node */
    newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return -2;
    }
    newNode->data = data;

    /* Insert the new node after the found node */
    newNode->next = current->next;
    current->next = newNode;

    return 0;  
}

/**
 * LinkedList_DisplayList - Display all nodes in the list
 * 
 * Traverses the list from head to tail and prints each node's data
 * in the format: data1 -> data2 -> ... -> NULL
 */
void LinkedList_DisplayList(void)
{
    Node *current = __head;
    
    /* Traverse and print each node */
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * LinkedList_DestroyList - Free all nodes and reset the list
 * 
 * Traverses the list and frees each node to prevent memory leaks.
 * Sets the head pointer to NULL after destroying all nodes.
 */
void LinkedList_DestroyList(void)
{
    Node *current = __head;
    Node *next;
    
    /* Traverse and free each node */
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    
    /* Reset head pointer */
    __head = NULL;
    printf("List destroyed\n");
}
