#include <stdio.h>

#define SIZE 7

// Definition of Datatype VirtualHeap
typedef struct {
    char elem;
    int link;
} Nodetype;

typedef struct {
    Nodetype Nodes[SIZE];
    int avail; //holds the index of the 1st available node
} VirtualHeap;

// Definition of Datatype List
typedef int List;

// Initialize the VirtualHeap
void initializeVirtualHeap(VirtualHeap* vh) {
    for (int i = 0; i < SIZE - 1; i++) {
        vh->Nodes[i].link = i + 1;
    }
    vh->Nodes[SIZE - 1].link = -1;  // End of the heap
    vh->avail = 0; // The first available node is at index 0
}

// Create a new list with an empty head
List createList(VirtualHeap* vh) {
    List newList = vh->avail;  // The new list points to the first available node
    if (newList != -1) {
        vh->avail = vh->Nodes[vh->avail].link; // Update the available node
        vh->Nodes[newList].link = -1;  // Initialize the list as empty
    }
    return newList;
}

// Insert a new element at the beginning of a list
void insertAtBeginning(VirtualHeap* vh, List list, char data) {
    if (list != -1) {
        int newNode = vh->avail;  // Get a new node from the available nodes
        if (newNode != -1) {
            vh->avail = vh->Nodes[newNode].link; // Update the available node
            vh->Nodes[newNode].elem = data;
            vh->Nodes[newNode].link = vh->Nodes[list].link;
            vh->Nodes[list].link = newNode;
        }
    }
}

// Display the elements of a list
void displayList(VirtualHeap* vh, List list) {
    printf("List %d: ", list);
    int current = vh->Nodes[list].link;
    while (current != -1) {
        printf("%c -> ", vh->Nodes[current].elem);
        current = vh->Nodes[current].link;
    }
    printf("NULL\n");
}

int main() {
    VirtualHeap vh;
    initializeVirtualHeap(&vh);

    List list1 = createList(&vh);
    List list2 = createList(&vh);

    insertAtBeginning(&vh, list1, 'A');
    insertAtBeginning(&vh, list1, 'B');
    insertAtBeginning(&vh, list2, 'X');
    insertAtBeginning(&vh, list2, 'Y');

    displayList(&vh, list1);
    displayList(&vh, list2);

    return 0;
}
