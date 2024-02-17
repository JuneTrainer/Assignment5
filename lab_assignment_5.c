#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	int counter = 0;
	node* temp = (node*)malloc(sizeof(node));
	temp = head;
	if(temp->next != NULL){
		while(temp != NULL){
			temp = temp->next;
			counter++;
		}
	}
	else{
		counter++;
		return counter;
	}
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	node* temp = (node*)malloc(sizeof(node));
	temp = head;
	char* string = malloc(sizeof(char));     
	int C=0;
		while(temp!=NULL){
			string[C] = temp->letter;
        	temp = temp->next;
			C++;
    }
	
	}



// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node*));
	node* lastN = *pHead;
    newNode->letter = c;
    newNode->next = NULL;
    if(pHead == NULL){
    *pHead = newNode;
	return;
	}
	while(lastN->next != NULL){
		lastN = lastN->next;
	}
	lastN->next = newNode;
}


// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* temp = (node*)malloc(sizeof(node));
	pHead = temp;
	while(temp !=NULL){
		 pHead = &temp->next;
		 pHead = temp;
		 free(temp);
	}
	temp = NULL;
	pHead = temp;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
	//	deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}