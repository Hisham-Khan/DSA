#include "LinkedList/LinkedList.h"

static int LinkedList_TestSuite(void);

int main()
{
    printf("=== Linked List Test Suite ===\n\n");
    LinkedList_TestSuite();
    return 0;
}

static int LinkedList_TestSuite(void)
{
    // Test 1: Initialize List
    printf("Test 1: Initialize List\n");
    if (LinkedList_InitializeList(10) == 0)
        printf("✓ List initialized with data 10\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 2: Create Node at Start
    printf("Test 2: Create Node at Start\n");
    (void)LinkedList_CreateNodeAtStart(5);
    printf("✓ Added 5 at start\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 3: Create Node at End
    printf("Test 3: Create Node at End\n");
    (void)LinkedList_CreateNodeAtEnd(15);
    (void)LinkedList_CreateNodeAtEnd(20);
    (void)LinkedList_CreateNodeAtEnd(25);
    printf("✓ Added 15, 20, 25 at end\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 4: Search for existing element
    printf("Test 4: Search for existing element (20)\n");
    if (LinkedList_SearchList(20) == 0)
        printf("✓ Found 20 in the list\n");
    else
        printf("✗ Failed to find 20\n");
    printf("\n");

    // Test 5: Search for non-existing element
    printf("Test 5: Search for non-existing element (100)\n");
    if (LinkedList_SearchList(100) == -1)
        printf("✓ Correctly reported 100 not found\n");
    else
        printf("✗ Incorrectly found 100\n");
    printf("\n");

    // Test 6: Insert Node after specific key
    printf("Test 6: Insert Node (30 after 15)\n");
    if (LinkedList_InsertNode(15, 30) == 0)
        printf("✓ Inserted 30 after 15\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 7: Insert Node after non-existing key
    printf("Test 7: Insert Node after non-existing key (40 after 999)\n");
    if (LinkedList_InsertNode(999, 40) == -1)
        printf("✓ Correctly failed to insert after non-existing key\n");
    printf("\n");

    // Test 8: Delete head node
    printf("Test 8: Delete head node (5)\n");
    if (LinkedList_DeleteNode(5) == 0)
        printf("✓ Deleted head node 5\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 9: Delete middle node
    printf("Test 9: Delete middle node (30)\n");
    if (LinkedList_DeleteNode(30) == 0)
        printf("✓ Deleted middle node 30\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 10: Delete tail node
    printf("Test 10: Delete tail node (25)\n");
    if (LinkedList_DeleteNode(25) == 0)
        printf("✓ Deleted tail node 25\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 11: Delete non-existing node
    printf("Test 11: Delete non-existing node (999)\n");
    if (LinkedList_DeleteNode(999) == -1)
        printf("✓ Correctly failed to delete non-existing node\n");
    printf("\n");

    // Test 12: Display current list
    printf("Test 12: Final List State\n");
    LinkedList_DisplayList();
    printf("\n");

    // Test 13: Destroy List
    printf("Test 13: Destroy List\n");
    LinkedList_DestroyList();
    printf("✓ List destroyed successfully\n");
    printf("\n");

    // Test 14: Operations on empty list
    printf("Test 14: Operations on empty list\n");
    printf("Delete from empty list: ");
    (void)LinkedList_DeleteNode(10);
    printf("Insert in empty list: ");
    (void)LinkedList_InsertNode(10, 20);
    printf("Display empty list: ");
    LinkedList_DisplayList();
    printf("\n");

    printf("=== All Tests Completed ===\n");
    return 0;
}