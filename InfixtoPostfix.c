#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define MAX 50

char stack[MAX];
int top=-1;

void push(char);
bool isOperator(char);
char pop();
int precedence(char);

void main()
{

    char infix[MAX],postfix[MAX],item,temp;
    int i=0,j=0;

    printf("Enter arithmetic expression in infix notation:");
    scanf("%[^\n]s",infix);

    while(infix[i]!='\0')
    {
        item=infix[i];

        if(item=='(')
        {
            push(item);
        }
        else if(item>='A' && item<='Z' || item>='a' && item<='z' || item>='0' && item<='9')
        {
            postfix[j]=item;
            j++;
        }
        else if(isOperator(item))
        {
            temp=pop();

            while(isOperator(temp) && precedence(temp)>=precedence(item))
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }

            if(temp !='\0')
            {
                push(temp);
            }
            push(item);
        }
        else if(item==')')
        {
            temp=pop();
            while(temp!='(')
            {
                postfix[j]=temp;
                j++;
                temp=pop();
            }
        }
        else
        {
            printf("Invalid expression");
            // exit(0);
        }

        i++;
    }

    while(top>-1)
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    printf("\nArithmetic expression in postfix notation is : %s",postfix);

}

void push(char item)
{
    if(top!=MAX-1)
    {
        top++;
        stack[top]=item;
    }
    else
    {
        printf("Stack overflow!");
    }

}

char pop()
{
    if(top!=-1)
    {
        char item=stack[top];
        top--;
        return item;
    }
    return '\0';

}

bool isOperator(char item)
{
    if(item=='^' || item=='$' || item=='/' || item=='*' || item=='%' || item=='+' || item=='-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int precedence(char item)
{
    if(item=='$' || item=='^')
    {
        return 3;
    }
    else if(item=='*' || item=='/')
    {
        return 2;
    }
    else if(item=='+' || item=='-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


