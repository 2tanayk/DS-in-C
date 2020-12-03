#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAX 5

int queue[MAX],front=-1,rear=-1;

void enqueue(int);
int dequeue();
void display();
void peekFront();
void peekRear();
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
        rear=(rear+1) % MAX;
        queue[rear]=e;
    }
    else
    {
        printf("Queue is Full!\n");
    }
}

int dequeue()
{
    if(!isEmpty())
    {
        int item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
        printf("element dequeued %d\n",item);
        return item;
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
        for(int i=front; i!=rear; i=(i+1)%MAX)
        {
            printf("%d ", queue[i]);
        }
        printf("%d",queue[rear]);
        printf("\n");
    }else{
        printf("Queue is empty!\n");
    }

}

void peekFront()
{
    if(!isEmpty())
    {
        printf("%d\n",queue[front]);
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
    if (front == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if((front==0 && rear==MAX-1) || (front == rear + 1) )
    {
        return true;
    }
    return false;
}
