/*
    Program Name: Linked List - I
    Author: Zyguel Philip E. Cabogoy
    Date: October 9, 2023
    Description: This program introduces the basics of Linked List
				 using C along with explaining its time complexities
	
	This code might be platform independent and runs on both linux
	based and windows based systems
	but if it does not run then make necessary changes! Thanks! :)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Include windows.h if sys is win and unistd.h if linux or unix based;
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

// platform independent sleep function
void portableSleep(int sleepMs)
{
#ifdef _WIN32
    Sleep(sleepMs);
#else
    usleep(sleepMs * 1000);   // usleep takes sleep time in us (1 millionth of a second)
#endif
}


// platform independent clear function
void clearConsole()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Integer input validattion

bool isInputValid()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (c != ' ' && c != '-')
        {
            printf("Error: Invalid input\n");
            return false;
        }
    }
    return true;
}



//Arrays are Contstant time - 0(1)
#define MAX 10

typedef struct linked_list {
	int data; // 4 bytes
	struct linked_list *link; // 4 bytes
}*LIST, cptr;
typedef int List_Size;
// Insertion or Acessing Linked List Time complexity is: O(n)
// The runtime is directly proportional to the size of the input data. 
//Example: iterating through an array.

// Insertion at beginning is 0(1) for Linked List
// Insertion at last is 0(n)


//Linked list requires extra memory for pointer variables;
// 8 x n(number of sizeof(data_type_of_element) = n bytes
// Linked list is more storage efficient than Arrays.
// memory may be available as multiple small blocks

// in arrays it is available as a single large block

// Other interpretation for the defined struct above
/*
struct Node {
	int data; // 4 bytes
	Node* next; // 4 bytes;
}
*/
/* //Challenge of making something similar functions to ArrayLists in Java 
   //  (for my own entertainment but you can also try hehe)
void insert_list(){
	
}*/
void init_List(LIST *A){
	*A = NULL;
}
void traversal_display(LIST A){
	LIST temp1 = A; 
	int index = 0;
/*  	while (temp1 != NULL) {
        printf("LIST[%d] is %d\n", index, temp1->data);
        temp1 = temp1->link;
        index++;
    }*/
	// While the above statement is okay, 
	// some professors prefer a for loop to make it 1-2 lines shorter :)
	if (temp1 == NULL){
		printf("LIST EMPTY!\n");
	}
	for (; temp1 != NULL; temp1 = temp1->link, index++){
		printf("LIST node[%d]->data is %d\n", index, temp1->data);
	}
	
}

void insert_beginning(LIST *A, int elem){
	LIST temp = (LIST)malloc(sizeof(cptr));
	if (temp == NULL)
	{
		fprintf(stderr, "Memory allocation failed. \n");
		exit(-1);
	}else{
	
    	temp->data = elem;
    	temp->link = *A;
    	*A = temp;
	}
}

void insert_at(LIST *A,int pos,int data){
	LIST temp = (LIST) malloc(sizeof(cptr));
	temp->data = data;
	temp->link = NULL;
	if (pos >= 0){
		if(pos == 0){
			temp->link = *A;
			*A = temp;
	
		}else {
			LIST curr = (LIST) malloc(sizeof(cptr));
			curr = *A;
			int ndx;
			for (ndx = 0; ndx < pos - 1 && curr != NULL; curr = curr->link, ndx++);
			if (curr == NULL){
				printf("Invalid pos! Press Enter to continue!");
				getchar();
				free(temp);
				return;
			}
			temp->link = curr->link;
			curr->link = temp;
			
		}
	}
}

void delete_at(LIST *A, int pos){
	LIST temp = *A;
	
	if (*A == NULL){
		printf("Delete not succesful! List is Empty!");
		portableSleep(3000);
	}else if(pos == 0){
		*A = temp->link;
		free(temp);
	}else{
		LIST curr = *A;
	
		int ndx;
		for(ndx = 0; ndx < pos - 1 && curr != NULL; curr = curr->link, ndx++);
		if (curr == NULL || curr->link == NULL){
			printf("Invalid Position!");
		}
		temp = curr->link;
		curr->link = curr->link->link;
		free(temp);
	}
}

void show_commands();
 void enter_choice();
int main (int argc, char *argv[]){
	LIST A;
	init_List(&A); 
	
//	LIST temp = (LIST) malloc(sizeof(cptr)); 
	// cptr is an alias for struct linked_list;
//	temp->data = 2;
//	temp->link = NULL;
//	A = temp;
	traversal_display(A);
	
	while (1)
	{	
		show_commands();
		enter_choice(&A);
	}
	printf("modified ver: \n\n\n");
	
/*	insert_beginning(&A, 5);
    insert_beginning(&A, 10);
    insert_beginning(&A, 15);
	traversal_display(A);
*/	
	// Free allocated memory
 /*	while (A != NULL) {
        LIST temp_free = A;
        A = A->link;
        free(temp_free);
    }*/
	return 0;
	
	

}

//https://youtu.be/B31LgI4Y4DQ?si=zyQOwcC91vnptTIj&t=4395
//https://youtu.be/B31LgI4Y4DQ?si=CutTHJC6_8uUJtac&t=5735
void show_commands(){
	 clearConsole();
	 
	 printf("+----------------------------------+\n");
     printf("| Command Menu for Linked List     |\n");
     printf("+----------------------------------+\n");
     printf("| Option | Description             |\n");
     printf("+----------------------------------+\n");
     printf("|   1    | Populate Linked List    |\n");
     printf("|   2    | Traversal and Display   |\n");
     printf("|   3    | Insert at beginning     |\n");
     printf("|   4    | Insert at nth position  |\n");
     printf("|   5    | Insert at last	   |\n");
     printf("|   6    | delete at nth position  |\n");
     printf("|   7    | Exit                    |\n");
     printf("+----------------------------------+\n");
    
}

void enter_choice(LIST *A){
	int choice;

	printf("Command #");

   	if (scanf(" %d", &choice) != 1 || !isInputValid())
  	{
   		printf("Error: Invalid input\n");
    //	exit(1);
 	}

 	int num, ndx;

        switch (choice) {
          
		    case 1:
                printf("\nYou selected Option 1 : Populate Linked List\n");
                // Add code for Option 1 here
                break;
                
            case 2:
                printf("\nYou selected Option 2 : Traversal and Display\n");
                // Add code for Option 2 here
                traversal_display(*A); // Display the current list
                printf("\n\n");
                printf("To continue press Enter");
                getchar();
        	//	portableSleep(2000);  // Sleep for 2 seconds
                break;
                
            case 3:
                printf("\nYou selected Option 3 : Insert front\n");
              
				// Add code for Option 3 here 
                printf("How many times do you want to insert : ");
                scanf(" %d", &num);
                for(ndx = 0; ndx < num; ndx++){
                	int elem;
					printf("\nEnter data[%d] : ", ndx);
                	if (scanf("%d", &elem) != 1 || !isInputValid())
  						{
     					   printf("Error: Invalid input\n");
    					  // exit(1);
    					  break;
 						}
                	insert_beginning(A, elem);
					
				}
                break;
                
            case 4:
                printf("\nYou selected Option 4 : Insert at position\n");
                //int num, ndx;
				printf("How many times do you want to insert? : ");
				scanf("%d", &num);
                for (ndx = 0; ndx < num; ndx++){
                	int pos, data;
                	printf("Attempt # %d\n", ndx + 1);
					printf("Enter value: ");
					if (scanf("%d", &data) != 1 || !isInputValid())
  					{
     				   printf("Error: Invalid input\n");
    				   break;
 					}
					printf("Enter position: ");
					if (scanf("%d", &pos) != 1 || !isInputValid())
  					{
     				   printf("Error: Invalid input\n");
    				   break;
 					}
 					insert_at(A,pos,data);	
				}
				
				break;
			case 6: 
				printf("\nYou have selected Option 6 : Delete at nth position! \n");
				printf("How many times do you want to delete ? \n");
				printf("Enter number of times : ");
				scanf("%d", &num);
				for (ndx = 0; ndx < num; ndx++){
					int pos;
					printf("Deletion # %d\n", ndx + 1);
					printf("Enter position to delete : ");
					scanf("%d", &pos);
					delete_at(A, pos);
				}
				break;
            case 7: 
				printf("Exiting!");
				portableSleep(2000);
				clearConsole();
				exit(0);
				break;    
            default:
                printf("\nInvalid choice. Please enter a valid option.\n");
				printf("Can re-enter after this message is hidden");
				portableSleep(1000);
				getchar(); //handles non-integer errors( infinity loop preventor); 
				// VERY IMPORTANT this line keeps the code working from user input errors;
				
				break;
        }
}
