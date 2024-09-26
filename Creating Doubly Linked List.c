// Header Files
#include <stdio.h>
#include <stdlib.h>

// Defining the structure of the NODE of the Doubly Linked List
typedef struct NODE
{
    int data;                    // Data to store in the node
    struct NODE* next;          // Pointer to the next node
    struct NODE* previous;      // Pointer to the previous node
} node;

// Function Prototypes
node* doublyLinkedList(int n);          // Function to create the Doubly Linked List
void display_Left_To_Right(node* ptr);  // Function to display the list from left to right
void display_Right_To_Left(node* ptr);  // Function to display the list from right to left

// Function to create the Doubly Linked List
node* doublyLinkedList(int n)
{
    node *head = NULL;          // Head pointer for the linked list
    node *temp = NULL;          // Temporary pointer for creating nodes
    node *p = NULL;             // Pointer to connect nodes

    for(int i = 0; i < n; i++)
    {
        temp = (node*)malloc(sizeof(node)); // Allocate memory for a new node
        if (temp == NULL)          // Check for memory allocation failure
        {
            printf("Memory allocation failed!\n");
            exit(1);              // Exit if memory allocation fails
        }

        printf("\nEnter Data: ");
        scanf("%d", &temp->data); // Read user input
        temp->next = NULL;         // Initialize next pointer of the new node
        temp->previous = NULL;     // Initialize previous pointer of the new node

        if(head == NULL)
        {
            head = temp;           // The first node becomes the head
        }
        else
        {
            p = head;
            while(p->next != NULL) // Traverse to the last node
            {
                p = p->next;
            }
            p->next = temp;        // Link the new node at the end
            temp->previous = p;    // Link the previous pointer of the new node
        }
    }
    return head;                   // Return the head of the linked list
}

// Function to display the linked list from left to right
void display_Left_To_Right(node* ptr)
{
    printf("\nLinked List (Left to Right): ");
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data); // Print the data of the current node
        ptr = ptr->next;             // Move to the next node
    }
    printf("NULL\n");                // End of the linked list
}

// Function to display the linked list from right to left
void display_Right_To_Left(node* ptr)
{
    // Move to the last node
    while(ptr != NULL && ptr->next != NULL)
    {
        ptr = ptr->next;             // Move to the next node
    }

    printf("\nLinked List (Right to Left): ");
    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data); // Print the data of the current node
        ptr = ptr->previous;         // Move to the previous node
    }
    printf("NULL\n");                // End of the linked list
}

// Main function
int main()
{
    node* HEAD = NULL;                 // Head pointer for the linked list
    HEAD = doublyLinkedList(10);       // Create a doubly linked list with 10 nodes
    display_Left_To_Right(HEAD);       // Display the linked list from left to right
    display_Right_To_Left(HEAD);       // Display the linked list from right to left

    // Freeing memory for the linked list
    node* current = HEAD;              // Pointer for traversing the list
    node* next;                        // Pointer for keeping track of the next node
    while (current != NULL)            // Loop through the list
    {
        next = current->next;          // Store the next node
        free(current);                 // Free the current node
        current = next;                // Move to the next node
    }

    printf("\nMemory freed successfully.........!!!\n");
    return 0;                          // Successful termination of the program
}
