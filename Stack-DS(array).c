#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>

//structure from which we create our stack
struct stack
{
    int top;//to keep track of the top position of the stack
    int capacity;//to accept stack size
    int* array;//to implement stack
};

typedef struct stack Stack;// alias for struct stack
Stack* s=NULL;//initializing struct pointer to null

//function prototypes
Stack* createStack(int);
bool isFull();
bool isEmpty();
void push(int);
int peek();
void pop();
void display();
bool isNotNull();


void main()
{
    int size,v,flag=1,ch;
    do
    {
        printf("Enter your choice:\n1)create stack\n2)push\n3)peek\n4)pop\n5)display elements\n6)exit\n");
        scanf("%d",&ch);

        switch(ch)
        {

        case 1:
            printf("Enter the size of the stack you want to create:");
            scanf("%d",&size);
            s=createStack(size);
            break;
        case 2:
            printf("Enter the value you want to push:");
            scanf("%d",&v);
            push(v);
            break;
        case 3:
            printf("%d\n",peek());
            break;
        case 4:
            pop();
            break;
        case 5:
            display();
            break;
        case 6:
            flag=0;
            break;
        default:
            printf("Invalid choice\n");
        }

    }
    while(flag);



    /* push(10);
     push(7);
     push(-9);
     push(-89);
     push(100);

     pop();
     pop();*/




    // printf("%d\n",peek());

    //pop();

    //push(123);


    //display();

}

Stack* createStack(int capacity)
{
    Stack* i=(Stack*)malloc(sizeof(Stack));//dynamic memory allocation to create an array
    i->top=-1;
    i->capacity=capacity;
    i->array=(int*)malloc(i->capacity * sizeof(int));

    printf("Stack of size %d created\n",capacity);

    return i;
}

bool isFull()
{
    if(isNotNull())
    {
        return (s->top == s->capacity-1);
    }
    return false;
}

bool isNotNull()
{
    if(s==NULL)
    {
        printf("Create the stack first!\n");
        return false;
    }
    return true;
}

bool isEmpty()
{
    if(isNotNull())
    {
        return (s->top == -1);
    }
    return false;
}

void push(int e)
{
    if(isFull())
    {
        printf("Stack is full\n");
        return;
    }
    else
    {
        if(isNotNull())
        {
            s->array[++s->top]=e;
            printf("%d pushed to top of the stack\n",e);
        }

    }
}

int peek()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
        return;
    }
    else
    {
        if(isNotNull())
        {
            return s->array[s->top];
        }

    }
}

void pop()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        if(isNotNull())
        {
            printf("%d popped from the top of the stack\n",s->array[s->top--]) ;
        }

    }
}

void display()
{
    if(isEmpty())
    {
        printf("Stack is empty\n");
    }
    else
    {
        if(isNotNull())
        {
            for(int i=0; i<=s->top; i++)
            {
                printf("%d ",s->array[i]);
            }
            printf("\n");
        }

    }
}
