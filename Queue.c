#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAX 10

int queue[MAX],front=-1,rear=-1;

void enqueue(int);
int dequeue();
void display();
void peekFront();
void peakRear();
bool isEmpty();
bool isFull();

void main()
{
    int c,n;
    bool condn=true;
    enqueue(10);
    enqueue(12);
    enqueue(55);

    do
    {
        printf("Enter a no.:\n1)Enqueue\n2)Dequeue\n3)Display\n4)Peek Front\n5)Peak Rear\n6)Exit\n");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("Enter a no. :");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peekFront();
            break;
        case 5:
            peekRear();
            break;
        case 6:
            condn=false;
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    while(condn);

}


void enqueue(int e)
{
    if(!isFull())
    {
        if(front==-1)
        {
            front++;
        }
        queue[++rear]=e;
        printf("Enqueued %d\n",e);
    }
    else
    {
        printf("Queue is full!\n");
    }

}
int dequeue()
{
    if(!isEmpty())
    {
        int d=queue[front];
        front++;
        printf("Dequeued %d\n",d);
        if (front > rear)
        {
            front = rear = -1;
        }
        return d;
    }
    else
    {
        printf("Queue is empty!\n");
        return NULL;
    }
}
void display()
{
    if(!isEmpty())
    {
        for(int i=front; i<=rear; i++)
        {
            printf("%d ",queue[i]);
        }
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

void peekFront()
{
    if(!isEmpty())
    {
        printf("%d ",queue[front]);
    }
    else
    {
        printf("Queue is empty!\n");
    }
}


void peekRear()
{
    if(!isEmpty())
    {
        printf("%d\n",queue[rear]);
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

bool isEmpty()
{
    if(front==-1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if(rear==MAX-1)
    {

        return true;
    }
    return false;
}
