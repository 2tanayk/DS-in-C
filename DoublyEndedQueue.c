#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdbool.h>

#define MAX 5

int front=-1,rear=-1,deque[MAX];

void enqueueFront(int);
void enqueueRear(int);
int dequeueFront();
int dequeueRear();
void peekFront();
void peekRear();
void displayFromFront();
void displayFromRear();
bool isFull();
bool isEmpty();

void main()
{
    int c,n;
    bool condn=true;

    do
    {
        printf("Enter a no.:\n1)Enqueue Front\n2)Enqueue Rear\n3)Dequeue Front\n4)Dequeue Rear\n5)Display Front\n6)Display Rear\n7)Peek Front\n8)Peak Rear\n9)Exit\n");
        scanf("%d",&c);

        switch(c)
        {
        case 1:
            printf("Enter a no. :");
            scanf("%d",&n);
            enqueueFront(n);
            break;
        case 2:
            printf("Enter a no. :");
            scanf("%d",&n);
            enqueueRear(n);
            break;
        case 3:
            dequeueFront();
            break;
        case 4:
            dequeueRear();
            break;
        case 5:
            displayFromFront();
            break;
        case 6:
            displayFromRear();
            break;
        case 7:
            peekFront();
            break;
        case 8:
            peekRear();
            break;
        case 9:
            condn=false;
            break;
        default:
            printf("Invalid choice!\n");
        }
    }
    while(condn);
}

void enqueueFront(int e)
{
    if(!isFull())
    {
        if(front==-1)
        {
            front++;
            rear++;
        }
        else
        {
            front--;
            if(front==-1)
            {
                front=MAX-1;
            }
        }
        deque[front]=e;
    }
    else
    {
        printf("Queue is Full!\n");
    }
}

void enqueueRear(int e)
{
    if(!isFull())
    {
        if(front==-1)
        {
            front++;
        }
        rear=(rear+1) % MAX;
        deque[rear]=e;
    }
    else
    {
        printf("Queue is Full!\n");
    }
}

int dequeueFront()
{
    if(!isEmpty())
    {
        int item=deque[front];
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

int dequeueRear()
{
    if(!isEmpty())
    {
        int item=deque[rear];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
        {
            rear=rear-1;
            if(rear==-1)
            {
                rear=MAX-1;
            }
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

void peekFront()
{
    if(!isEmpty())
    {
        printf("%d\n",deque[front]);
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
        printf("%d\n",deque[rear]);
    }
    else
    {
        printf("Queue is empty!\n");
    }
}
void displayFromFront()
{
    int i;
    if(!isEmpty())
    {
        i=front;
        if( front<=rear )
        {
            while(i<=rear)
            {
                printf("%d ",deque[i++]);
            }
        }
        else
        {
            while(i<=MAX-1)
            {
                printf("%d ",deque[i++]);
            }
            i=0;
            while(i<=rear)
            {
                printf("%d ",deque[i++]);
            }
        }
        printf("\n");
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

void displayFromRear()
{
    int i;
    if(!isEmpty())
    {
        i=rear;
        if(rear>=front)
        {
            while(i>=front)
            {
                printf("%d ",deque[i--]);
            }
        }
        else
        {
            while(i>=0)
            {
                printf("%d ",deque[i--]);
            }
            i=MAX-1;
            while(i>=front)
            {
                printf("%d ",deque[i--]);
            }
        }
        printf("\n");
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
    if((front==0 && rear==MAX-1) ||  (front==rear+1))
    {
        return true;
    }
    return false;
}
