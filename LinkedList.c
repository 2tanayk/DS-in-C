/**
 * Author:Tanay Kamath
 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
struct node
{
    //self-referential structure to create a node of the linked list
    int data;
    struct node *address;
};
//function prototypes
struct node *add_at_end(struct node*,int);
void traverse(struct node*);
struct node* insert(struct node*,int,int);
struct node* delete_element(struct node*,int);

//main function
void main()
{
    //head of the linked list
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->address=NULL;

    struct node *current=head;

    bool flag=true;

    //adding elements to the linked list in O(1) time complexity using current pointer
    current=add_at_end(current,34);
    current=add_at_end(current,12);
    current=add_at_end(current,67);
    current=add_at_end(current,100);
    do
    {

        int ch;
        printf("Enter your choice:\n1)add\n2)insert\n3)delete\n4)display\n5)exit\n");
        scanf("%d",&ch);

        int e,pos;
        switch(ch)
        {
        case 1:
            printf("Enter the element you want to add:");
            scanf("%d",&e);
            current=add_at_end(current,e);
            break;
        case 2:
            printf("Enter the element you want to insert and its position:");
            scanf("%d%d",&e,&pos);
            if(pos==1)
            {
                head=insert(head,e,pos);
            }
            else
            {
                insert(head,e,pos);
            }
            break;
        case 3:
            printf("Enter the position of the element you want to delete:");
            scanf("%d",&pos);
            if(pos==1)
            {
                head=delete_element(head,pos);
            }
            else
            {
                delete_element(head,pos);
            }
            break;
        case 4:
            traverse(head);
            break;
        case 5:
            flag=false;
            break;
        default:
            printf("Invalid choice");
        }
    }
    while(flag);

    // traverse(head);
    //insert(head,23,3);
    //delete_element(head,4);
    //head=delete_element(head,4);
    //traverse(head);
}

struct node* add_at_end(struct node* current,int data)
{
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->address=NULL;

    current->address=temp;
    return temp;
}

void traverse(struct node* temp)
{

    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->address;
    }
    printf("\n");
}

struct node* insert(struct node* head,int data,int pos)
{
    struct node *ptr=head; //pointer for traversing the linked list

    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->address=NULL;
    if(pos==1)
    {
        new_node->address=head;
        head=new_node;
        return head;  //we return pointer head so that it points to the new first element
    }
    else
    {

        pos--;
        while(pos!=1)
        {
            ptr=ptr->address;
            pos--;
        }

        new_node->address=ptr->address;//initializing address of inserted node to that of its next node
        ptr->address=new_node;//re-initializing address of the previous node to that of the new node
        return;//we don't have anything to return hence we return none
    }
}
struct node* delete_element(struct node* head,int pos)
{
    struct node *current=head;
    struct node *previous=head;

    if(head==NULL)
    {
        printf("List is empty!");
        return;
    }
    else if(pos==1) //checking if linked list contains only one element
    {
        head=head->address;
        free(current);//we need to free the heap memory allocated by us
        current=NULL;//to avoid a dangling pointer we assign NULL to it

        return head;//we return pointer head so that it points to the new first element
    }
    else
    {
        while(pos!=1)
        {
            previous=current;
            current=current->address;
            pos--;
        }
        previous->address=current->address;
        free(current);//we need to free the heap memory allocated by us
        current=NULL;//to avoid a dangling pointer we assign NULL to it
        return;//we don't have anything to return hence we return none
    }
}


