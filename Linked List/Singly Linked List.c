/****************************************************/
|                                                    |
|          All Singly Linked List Operations         |
|    1. Create                                       |
|    2. Display                                      |
|    2. Insert                                       |
|        2.1. Insert Node at Beginning               |
|        2.2. Insert Node at End                     |
|        2.3. Insert Node at Position                |
|        2.4. Insert After a Node                    |
|        2.5. Insert Before a Node                   |
|    3. Delete                                       |
|        3.1. Delete Node                            |
|        3.2. Delete Node at Beginning               |      
|        3.3. Delete Node at End                     |
|        3.4. Delete Node at Position                |
|        3.5. Delete After a Node                    |
|        3.6. Delete Before a Node                   |
|        3.7. Delete All Nodes                       |
|    3. Reverse                                      |
|    4. Search                                       |
|    5. Sort                                         |
|                                                    |
/****************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* Generic Structure for List */
typedef struct Node
{
    int Data;
    struct Node *Link;
}Node;


/* Enum for all Linked List Operations */ 
typedef enum ListOp
{
    eExit             = 0,
    eCreate           = 1,
    eDisplay          = 2,
    eSearch           = 3,
    eSort             = 4,
    eReverse          = 5,
    eInsertAtBeg      = 6,
    eInsertAtEnd      = 7,
    eInsertAtPos      = 8,
    eInsertAfterNode  = 9,
    eInsertBeforeNode = 10,
    eDeleteNode       = 11,
    eDeleteAtBeg      = 12,
    eDeleteAtEnd      = 13,
    eDeleteAtPos      = 14,
    eDeleteAfterNode  = 15,
    eDeleteBeforeNode = 16,
    eDeleteAllNode    = 17,
}ListOp;


/* Function Declaration */
Node* Create(Node *Head);
void  Display(Node *Head);
void  Search(Node *Head, int Element);
Node* Sort(Node *Head);
Node* Reverse(Node *Head);
Node* InsertAtBeg(Node *Head, int Element);
Node* InsertAtEnd(Node *Head, int Element);
Node* InsertAtPos(Node *Head, int Element, int Pos);
Node* InsertBeforeNode(Node *Head, int Element, int Value);
Node* InsertAfterNode(Node *Head, int Element, int Value);
Node* DeleteNode(Node *Head, int Value);
Node* DeleteAtBeg(Node *Head);
Node* DeleteAtEnd(Node *Head);
Node* DeleteAtPos(Node *Head, int Pos);
Node* DeleteBeforeNode(Node *Head, int Value);
Node* DeleteAfterNode(Node *Head, int Value);
Node* DeleteAllNode(Node *Head);


/************************************************************************/
/* FUNCTION: main()                                                     */
/************************************************************************/
int main()
{
    int Choice, Element, Pos, Value;
    
    Node *Head = NULL;
    
    while(true)
    {
        printf("\n*** Singly Linked List Menu ***\n");
        printf(" 1.  Create List\n");
        printf(" 2.  Display List\n");
        printf(" 3.  Search in List\n");
        printf(" 4.  Sort the List\n");
        printf(" 5.  Reverse the List\n");
        printf(" 6.  Insert node at Beg\n");
        printf(" 7.  Insert node at End\n");
        printf(" 8.  Insert node at Pos\n");
        printf(" 9.  Insert After a node\n");
        printf(" 10. Insert Before a node\n");
        printf(" 11. Delete node\n");
        printf(" 12. Delete node at Beg\n");
        printf(" 13. Delete node at End\n");
        printf(" 14. Delete node at Pos\n");
        printf(" 15. Delete After a node\n");
        printf(" 16. Delete Before a node\n");
        printf(" 17. Delete all nodes\n");
        printf(" 0.  EXIT\n");
        printf("Enter Choice: ");
        scanf("%d", &Choice);
        
        switch(Choice)
        {
            case eCreate:
            {
                Head = Create(Head);
                break;
            }
            case eDisplay:
            {
                Display(Head);
                break;
            }
            case eSearch:
            {
                printf("Enter the element to search: ");
                scanf("%d", &Element);
                Search(Head, Element);
                break;
            }
            case eSort:
            {
                Head = Sort(Head);
                break;
            }
            case eReverse:
            {
                Head = Reverse(Head);
                break;
            }
            case eInsertAtBeg:
            {
                printf("Enter the element to insert: ");
                scanf("%d", &Element);
                Head = InsertAtBeg(Head, Element);
                break;
            }
            case eInsertAtEnd:
            {
                printf("Enter the element to insert: ");
                scanf("%d", &Element);
                Head = InsertAtEnd(Head, Element);
                break;
            }
            case eInsertAtPos:
            {
                printf("Enter the element to insert: ");
                scanf("%d", &Element);
                printf("Enter the position to insert: ");
                scanf("%d", &Pos);
                Head = InsertAtPos(Head, Element, Pos);
                break;
            }
            case eInsertBeforeNode:
            {
                printf("Enter the element to insert: ");
                scanf("%d", &Element);
                printf("Enter the value to insert before: ");
                scanf("%d", &Value);
                Head = InsertBeforeNode(Head, Element, Value);
                break;
            }
            case eInsertAfterNode:
            {
                printf("Enter the element to insert: ");
                scanf("%d", &Element);
                printf("Enter the value to insert after: ");
                scanf("%d", &Value);
                Head = InsertAfterNode(Head, Element, Value);
                break;
            }
            case eDeleteNode:
            {
                printf("Enter the value to delete: ");
                scanf("%d", &Value);
                Head = DeleteNode(Head, Value);
                break;
            }            
            case eDeleteAtBeg:
            {
                Head = DeleteAtBeg(Head);
                break;
            }
            case eDeleteAtEnd:
            {
                Head = DeleteAtEnd(Head);
                break;
            }
            case eDeleteAtPos:
            {
                printf("Enter the position to delete: ");
                scanf("%d", &Pos);
                Head = DeleteAtPos(Head, Pos);
                break;
            }
            case eDeleteBeforeNode:
            {
                printf("Enter the value to delete before: ");
                scanf("%d", &Value);
                Head = DeleteBeforeNode(Head, Value);
                break;
            }
            case eDeleteAfterNode:
            {
                printf("Enter the value to delete after: ");
                scanf("%d", &Value);
                Head = DeleteAfterNode(Head, Value);
                break;
            }
            case eDeleteAllNode:
            {
                Head = DeleteAllNode(Head);
                break;
            }
            case eExit:
            {
                exit(0);
            }
            default:
            {
                printf("Bad Input, Try again\n");
                break;
            }
        }
    }

    return 0;
}


/************************************************************************/
/* FUNCTION: Node* Create(Node *Head)                                   */
/************************************************************************/
Node* Create(Node *Head)
{
    int n, data;
    
    if(Head != NULL)
    {
        printf("List already exist\n");
        return Head;
    }
    
    printf("Enter no of nodes in list: ");
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++)
    {
        printf("Enter %d node data: ", i);
        scanf("%d", &data);
        
        if(Head == NULL)
        {
            Head = InsertAtBeg(Head, data);
        }
        else
        {
            Head = InsertAtEnd(Head, data);
        }
    }
    
    return Head;
}


/************************************************************************/
/* FUNCTION: void Display(Node *Head)                                   */
/************************************************************************/
void Display(Node *Head)
{
    if(Head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    Node *ptr = Head;
    printf("List: ");
    while(ptr != NULL)
    {
        printf(" %d", ptr->Data);
        ptr = ptr->Link;
    }
    printf("\n");
}


/************************************************************************/
/* FUNCTION: void Search(Node *Head, int Element)                       */
/************************************************************************/
void Search(Node *Head, int Element)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return;
    }    
    
    Node *ptr = Head;
    while(ptr->Link != NULL)
    {
        if(ptr->Data == Element)
        {
            printf("%d found in list\n", Element);
            return;
        }
        ptr = ptr->Link;
    }
    printf("%d not found in list\n", Element);
}


/************************************************************************/
/* FUNCTION: Node* Sort(Node *Head)                                     */
/************************************************************************/
Node* Sort(Node *Head)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    } 
    
    int temp;
    Node *ptr1, *ptr2;
    
    for(ptr1 = Head; ptr1 != NULL; ptr1 = ptr1->Link)
    {
        for(ptr2 = Head; ptr2 != NULL; ptr2 = ptr2->Link)
        {
            if(ptr1->Data < ptr2->Data)
            {
                temp = ptr1->Data;
                ptr1->Data = ptr2->Data;
                ptr2->Data = temp;
            }
        }
    }
    
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* Reverse(Node *Head)                                  */
/************************************************************************/
Node* Reverse(Node *Head)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    } 
    
    Node *prev, *curr, *next;
    prev = NULL;
    curr = Head;
    next = NULL;
    
    while(curr != NULL)
    {
        next = curr->Link;
        curr->Link = prev;
        prev = curr;
        curr = next;
    }
    Head = prev;    

    return Head;
}


/************************************************************************/
/* FUNCTION: Node* InsertAtBeg(Node *Head, int Element)                 */
/************************************************************************/
Node* InsertAtBeg(Node *Head, int Element)
{
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->Data = Element;
    
    if(Head == NULL)
    {
        temp->Link = NULL;
        Head = temp;
        return Head;
    }
    
    temp->Link = Head;
    Head = temp;
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* InsertAtEnd(Node *Head, int Element)                 */
/************************************************************************/
Node* InsertAtEnd(Node *Head, int Element)
{
    if(Head == NULL)
    {
        return InsertAtBeg(Head, Element);
    }

    Node *temp = (Node*) malloc(sizeof(Node));
    temp->Data = Element;  
    
    Node *ptr = Head;
    while(ptr->Link != NULL)
    {
        ptr = ptr->Link;
    }

    ptr->Link = temp;
    temp->Link = NULL;
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* InsertAtPos(Node *Head, int Element, int Pos)        */
/************************************************************************/
Node* InsertAtPos(Node *Head, int Element, int Pos)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->Data = Element;    
    
    if(Pos == 1)
    {
        temp->Link = Head;
        Head = temp;
        return Head;
    }
    
    int count = 0;
    Node *ptr = Head;
    for(int i = 1; i != (Pos - 1); i++)
    {
        if(ptr->Link == NULL)
        {
            if(count < Pos)
            {
                printf("Position %d did not exist in list\n", Pos);
                free(temp);
                return Head;
            }    
        }
        count++;
        ptr = ptr->Link;
    }
    
    temp->Link = ptr->Link;
    ptr->Link = temp;
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* InsertBeforeNode(Node *Head, int Element, int Value) */
/************************************************************************/
Node* InsertBeforeNode(Node *Head, int Element, int Value)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->Data = Element;    
    
    if(Head->Data == Value)
    {
        temp->Link = Head;
        Head = temp;
        return Head;
    }
    
    Node *ptr = Head;
    while(ptr != NULL)
    {
        if(ptr->Link->Data == Value)
        {
            temp->Link = ptr->Link;
            ptr->Link = temp;
            return Head;
        }
        ptr = ptr->Link;
    }
    
    printf("Element %d is not found in list", Value);
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* InsertAfterNode(Node *Head, int Element, int Value)  */
/************************************************************************/
Node* InsertAfterNode(Node *Head, int Element, int Value)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->Data = Element;
    
    Node *ptr = Head;
    while(ptr != NULL)
    {
        if(ptr->Data == Value)
        {
            temp->Link = ptr->Link;
            ptr->Link = temp;
            return Head;
        }
        ptr = ptr->Link;
    }
    
    printf("Element %d is not found in list", Value);
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* DeleteNode(Node *Head, int Value)                    */
/************************************************************************/
Node* DeleteNode(Node *Head, int Value)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *ptr, *temp;
  
    if(Head->Data == Value)
    {
        temp = Head;
        Head = Head->Link;
        free(temp);
        return Head;
    }
    
    ptr = Head;
    while(ptr->Link != NULL)
    {
        if(ptr->Link->Data == Value)
        {
            temp = ptr->Link;
            ptr->Link = ptr->Link->Link;
            free(temp);
            return Head;
        }
        ptr = ptr->Link;
    }
    
    printf("Element %d is not found in list", Value);
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* DeleteAtBeg(Node *Head)                              */
/************************************************************************/
Node* DeleteAtBeg(Node *Head)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *temp = Head;
    
    Head = Head->Link;
    free(temp);
    
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* DeleteAtEnd(Node *Head)                              */
/************************************************************************/
Node* DeleteAtEnd(Node *Head)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }

    if(Head->Link == NULL)
    {
        free(Head);
        return NULL;
    }
    
    Node *temp, *ptr;
    
    ptr = Head;
    while(ptr->Link->Link != NULL)
    {
        ptr = ptr->Link;
    }
    temp = ptr;
    temp = temp->Link;
    ptr->Link = NULL;
    free(temp);
    
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* DeleteAtPos(Node *Head, int Pos)                     */
/************************************************************************/
Node* DeleteAtPos(Node *Head, int Pos)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *ptr, *temp;
    
    if(Pos == 1)
    {
        temp = Head;
        Head = Head->Link;
        free(temp);
        return Head;
    }
    
    int count = 0;
    ptr = Head;
    for(int i = 1; i < (Pos - 1); i++)
    {
        if(ptr->Link == NULL)
        {
            if(count < Pos)
            {
                printf("Position %d did not exist in list\n", Pos);
                return Head;
            }
        }
        ptr = ptr->Link;
    }
    
    temp = ptr->Link;
    ptr->Link = ptr->Link->Link;
    free(temp);
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* DeleteBeforeNode(Node *Head, int Value)              */
/************************************************************************/
Node* DeleteBeforeNode(Node *Head, int Value)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }    
   
   
   if(Head->Data == Value)
   {
       printf("%d is the first node", Value);
       return Head;
   }
   
   Node *ptr, *temp;
   
   ptr = Head;
   //temp = ptr;
   while(ptr->Link != NULL)
   {
       if(ptr->Link->Data == Value)
       {
            ptr = temp;           
            temp = ptr->Link;
            ptr->Link = ptr->Link->Link;
            free(temp);
            return Head;
       }
       temp = ptr;
       ptr = ptr->Link;
   }
    
    printf("Element %d is not found in list", Value);
    return Head;
}


/************************************************************************/
/* FUNCTION: Node* DeleteAfterNode(Node *Head, int Value)               */
/************************************************************************/
Node* DeleteAfterNode(Node *Head, int Value)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
   
   Node *ptr, *temp;
   
   ptr = Head;
   while(ptr->Link != NULL)
   {
       if(ptr->Data == Value)
       {
            temp = ptr->Link;
            ptr->Link = ptr->Link->Link;
            free(temp);
            return Head;
       }
       ptr = ptr->Link;
   }   
   
   printf("Element %d is not found in list", Value);
   return Head; 
}


/************************************************************************/
/* FUNCTION: Node* DeleteAllNode(Node *Head)                            */
/************************************************************************/
Node* DeleteAllNode(Node *Head)
{
    if(Head == NULL)
    {
        printf("List is Empty\n");
        return Head;
    }
    
    Node *ptr, *temp;
    
    ptr = Head;
    while(ptr->Link != NULL)
    {
        temp = ptr;
        ptr = ptr->Link;
        free(temp);
    }
    
    return NULL;
}
