#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define MAX 10

typedef struct linked_list {
    int data;
    struct linked_list *link;
} *LIST, cptr;

void portable_sleep(int sleepMs)
{
#ifdef _WIN32
    Sleep(sleepMs);
#else
    usleep(sleepMs * 1000);
#endif
}

void clear_console()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void init_list(LIST *A)
{
    *A = NULL;
}

void traversal_display(LIST A)
{
    int index = 0;
    if (A == NULL)
    {
        printf("LIST EMPTY!\n");
    }
    for (LIST temp1 = A; temp1 != NULL; temp1 = temp1->link, index++)
    {
        printf("LIST[%d] is %d\n", index, temp1->data);
    }
}

void insert_beginning(LIST *A, int elem)
{
    LIST temp = (LIST)malloc(sizeof(cptr));
    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    temp->data = elem;
    temp->link = *A;
    *A = temp;
}

void show_commands();
void enter_choice();

int main(int argc, char *argv[])
{
    LIST A;
    init_list(&A);
    show_commands();
    while (1)
    {
        show_commands();
        enter_choice(&A);
    }
    return 0;
}

void show_commands()
{
    clear_console();
    printf("+----------------------------------+\n");
    printf("| Command Menu for Linked List     |\n");
    printf("+----------------------------------+\n");
    printf("| Option | Description             |\n");
    printf("+----------------------------------+\n");
    printf("|   1    | Populate Linked List    |\n");
    printf("|   2    | Traversal and Display   |\n");
    printf("|   3    | Insert at beginning     |\n");
    printf("|   4    | Insert at nth position  |\n");
    printf("|   6    | Exit                    |\n");
    printf("+----------------------------------+\n");
}

void enter_choice(LIST *A)
{
    int choice;
    printf("Command #");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\nYou selected Option 1 : Populate Linked List\n");
        // Add code for Option 1 here
        break;

    case 2:
        printf("\nYou selected Option 2 : Traversal and Display\n");
        traversal_display(*A); // Display the current list
        portable_sleep(2000);  // Sleep for 2 seconds
        break;

    case 3:
        printf("\nYou selected Option 3 : Insert front\n");
        int num;
        printf("How many times do you want to insert : ");
        scanf("%d", &num);
        for (int ndx = 0; ndx < num; ndx++)
        {
            int elem;
            printf("Enter data[%d] : ", ndx);
            scanf("%d", &elem);
            insert_beginning(A, elem);
            portable_sleep(1000);
        }
        break;

    case 4:
        printf("\nYou selected Option 4 : Insert at position\n");
        // Add code for Option 4 here
        break;

    case 6:
        printf("Exiting!\n");
        portable_sleep(2000);
        clear_console();
        exit(0); // Exit the program
        break;

    default:
        printf("\nInvalid choice. Please enter a valid option.\n");
        printf("Re-entering in 3 seconds...\n");
        portable_sleep(3000);
        show_commands();
    }
}
