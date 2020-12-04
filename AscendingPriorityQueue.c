//Ascending Priority Queue
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#define MAX 5

int queue[MAX],front=-1,rear=-1,ct=0;
int flag=-1;

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
    enqueue(55);
    enqueue(12);

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
            queue[front]=e;
            ct++;

        }
        else
        {
            int h=ct-1;
            for(int i=front; i<=h; i++)
            {
                if(queue[i]>e)
                {
                    for(int j=h; j>=i; j--)
                    {
                        queue[j+1]=queue[j];
                    }
                    queue[i]=e;
                    ct++;
                    break;
                }
                else
                {
                    if(i==h)
                    {
                        queue[ct++]=e;
                    }
                }
            }
        }
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
        printf("element dequeued %d\n",item);
        front++;

        printf("%d \n",front);
        if(front==ct)
        {
            //reset
            front=-1;
            ct=0;
        }
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
        for(int i=front; i<ct; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
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
        printf("%d\n",queue[ct-1]);
    }
    else
    {
        printf("Queue is empty!\n");
    }
}

bool isEmpty()
{
    if (front==-1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if(ct==MAX)
    {
        return true;
    }
    return false;
}
