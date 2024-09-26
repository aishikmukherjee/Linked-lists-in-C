#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular linked list
typedef struct NODE {
    int data;
    struct NODE* next;
} node;

// Function Prototypes
node* Circular_LinkedList(int n);
void display(node* ptr);
void freeCircularList(node* head);

node* Circular_LinkedList(int n) {
    node* head = NULL;
    node* temp = NULL;
    node* p = NULL;

    for (int i = 0; i < n; i++) {
        temp = (node*)malloc(sizeof(node)); // Allocate memory for the new node
        if (temp == NULL) { // Check for memory allocation failure
            printf("Memory allocation failed!\n");
            exit(1);
        }
        printf("\nEnter Data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        if (head == NULL) {
            head = temp; // Initialize head
        } else {
            p = head;
            while (p->next != NULL) { // Traverse to the end
                p = p->next;
            }
            p->next = temp; // Link the new node at the end
        }
    }

    // Create the circular link
    if (temp != NULL) {
        temp->next = head; // Link the last node to the head
    }
    return head;
}

// Function to display the circular linked list
void display(node* ptr) {
    if (ptr == NULL) {
        printf("\nThe Circular Linked List is empty....!!!");
        return;
    }

    node* current = ptr;
    printf("\nCircular Linked List: ");
    do {
        printf("%d -> ", current->data); // Display the data
        current = current->next; // Move to the next node
    } while (current != ptr); // Loop until we reach the head again

    printf("(back to head: %d)\n", ptr->data); // Indicate back to head
}

// Function to free the circular linked list
void freeCircularList(node* head) {
    if (head == NULL) return;

    node* current = head;
    node* nextNode;
    do {
        nextNode = current->next; // Store the next node
        free(current); // Free the current node
        current = nextNode; // Move to the next node
    } while (current != head); // Stop when we loop back to head
}

int main() {
    int num;
    printf("Enter number of Nodes you want to create: ");
    scanf("%d", &num);

    node* HEAD = Circular_LinkedList(num); // Create the circular linked list
    display(HEAD); // Display the circular linked list
    freeCircularList(HEAD); // Free the memory allocated for the list

    printf("Memory freed successfully....!!!\n");
    return 0; // Successful termination of the program
}
