#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *address;
};

struct node *add_at_end(struct node*,int);
void traverse(struct node*);
struct node* insert(struct node*,int,int);
struct node* delete_element(struct node*,int);

void main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->address=NULL;

    struct node *current=head;

    current=add_at_end(current,34);
    current=add_at_end(current,12);
    current=add_at_end(current,67);
    current=add_at_end(current,100);


    traverse(head);
    insert(head,23,3);

    //head=delete_element(head,4);

    traverse(head);


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
    struct node *ptr=head;

    struct node *new_node=(struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    new_node->address=NULL;
    if(pos==1)
    {
        new_node->address=head;
        head=new_node;
        return head;
    }
    else
    {

        pos--;
        while(pos!=1)
        {
            ptr=ptr->address;
            pos--;
        }

        new_node->address=ptr->address;
        ptr->address=new_node;
        return;
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
    else if(pos==1)
    {
        head=head->address;
        free(current);
        current=NULL;

        return head;
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
        free(current);
        current=NULL;
        return;
    }
}


