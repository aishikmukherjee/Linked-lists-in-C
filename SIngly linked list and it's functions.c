#include <stdio.h>
#include <stdlib.h>

// Creating structure for a node in the linked list
typedef struct NODE {
    int data;                   // Data to store in the node
    struct NODE* next;         // Pointer to the next node
} node;

// Function Prototypes
void display(node* ptr);
node* create(int n);
void shots(node* head);
node* AddToPosition(node* ptr);
node* DeleteToPosition(node* ptr);

// Function to display the linked list
void display(node* ptr) {
    if (ptr == NULL) {
        printf("\nThe Linked List is empty....!!!");
    } else {
        printf("\nLinked List: ");
        while (ptr != NULL) {
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// Function to create a linked list with n nodes
node* create(int n) {
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    for (int i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node)); // Allocate memory for a new node
        if (temp == NULL) {                 // Check for memory allocation failure
            printf("Memory allocation failed!\n");
            exit(1);                        // Exit if memory allocation fails
        }
        printf("\nEnter Data: ");
        scanf("%d", &temp->data); // Read user input
        temp->next = NULL;         // Initialize the next pointer

        if (head == NULL) {
            head = temp;           // The first node becomes the head
        } else {
            p = head;
            while (p->next != NULL) {
                p = p->next;       // Traverse to the last node
            }
            p->next = temp;       // Link the new node at the end
        }
    }
    return head;                   // Return the head of the linked list
}

// Main function
int main() {
    int num;
    printf("\nEnter number of Nodes you want to create: ");
    scanf("%d", &num);

    node* HEAD = create(num);     // Create the linked list
    shots(HEAD);                   // Call function to perform actions on the list

    // Freeing memory for the linked list
    node* current = HEAD;          // Pointer for traversing the list
    node* next;                   // Pointer for keeping track of the next node
    while (current != NULL) {      // Loop through the list
        next = current->next;      // Store the next node
        free(current);             // Free the current node
        current = next;            // Move to the next node
    }

    printf("\nMemory freed successfully....!!!\n");
    return 0;                      // Successful termination of the program
}

// Function to perform actions (add/delete) on the linked list
void shots(node* head) {
    int choice;
    display(head);                // Display the linked list
    printf("\nPress 1 to Add data");
    printf("\nPress 2 to Delete Data");
    printf("\nPress 0 to Stop the program and free the memory");
    printf("\nEnter Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 0: {
            printf("\nProgram Killed...... and Memory Freed!!!");
            break; // No need to free here, as it's already handled in main
        }
        case 1: {
            head = AddToPosition(head);  // Add a node to the linked list
            display(head);                // Display updated list
            break;
        }
        case 2: {
            head = DeleteToPosition(head); // Delete a node from the linked list
            display(head);                 // Display updated list
            break;
        }
        default: {
            printf("\nWrong Input.... Program Killed.......!!!");
        }
    }

    // Recursively call shots to allow further actions
    if (choice != 0) {
        shots(head);                  // Continue allowing actions on the list
    }
}

// Function to add a node at a specific position
node* AddToPosition(node* ptr) {
    int pos, data, limit = 0;
    node* copy1 = ptr;

    // Calculate the current size of the linked list
    while (copy1 != NULL) {
        limit++;
        copy1 = copy1->next;
    }

    printf("\nEnter Data you want to insert: ");
    scanf("%d", &data);
    printf("\nEnter position (0 <= position <= %d) where you want to enter the data: ", limit);
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 0 || pos > limit) {
        printf("\nInvalid Input for position....!!!\n");
        return ptr; // Return unchanged list
    }

    node* newNode = (node*)malloc(sizeof(node)); // Allocate memory for the new node
    if (newNode == NULL) { // Check for memory allocation failure
        printf("Memory allocation failed!\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = data;

    // If inserting at the beginning
    if (pos == 0) {
        newNode->next = ptr; // Point new node to current head
        return newNode;      // New node is now the head
    }

    // Traverse to the correct position
    node* current = ptr;
    for (int i = 0; i < pos - 1; i++) {
        current = current->next; // Move to the node before the insertion point
    }
    newNode->next = current->next; // Link new node to the next node
    current->next = newNode; // Link previous node to the new node
    return ptr; // Return the unchanged head of the list
}

// Function to delete a node from a specific position
node* DeleteToPosition(node* ptr) {
    int pos, limit = 0;
    node* copy = ptr;

    // Calculate the current size of the linked list
    while (copy != NULL) {
        limit++;
        copy = copy->next;
    }

    printf("\nEnter Position (0 <= POSITION < %d) from where you want to delete the data: ", limit);
    scanf("%d", &pos);

    // Check for valid position
    if (pos < 0 || pos >= limit) {
        printf("\nInvalid position for deletion..!!!\n");
        return ptr; // Return unchanged list
    }

    node* current = ptr; // Pointer to traverse the list
    // If deleting the head node
    if (pos == 0) {
        ptr = current->next; // Move head to the next node
        free(current); // Free the old head
        return ptr; // Return new head
    }

    // Traverse to the node before the position to delete
    for (int i = 0; i < pos - 1; i++) {
        current = current->next;
    }

    node* toDelete = current->next; // Node to be deleted
    current->next = toDelete->next; // Bypass the node to be deleted
    free(toDelete); // Free the deleted node
    return ptr; // Return unchanged head of the list
}
