#include<stdio.h>
#include<conio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
} tnode;

tnode* root=NULL;

void insert(int);
tnode* search(int,tnode**);
void preOrderTraversal(tnode*);
void postOrderTraversal(tnode*);
void inOrderTraversal(tnode*);
void deleteNode(tnode*,int);

void main()
{
    int ch,n;
    bool flag=true;
    tnode* parent=(tnode*)malloc(sizeof(tnode));

    do
    {
        printf("Enter a no.\n1)insert\n2)search\n3)pre-order traversal\n4)post-order traversal\n5)in-order traversal\n6)delete node\n7)exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
        case 1:
            printf("Enter a no.:");
            scanf("%d",&n);
            insert(n);
            break;
        case 2:
            printf("Enter the element to be searched:");
            scanf("%d",&n);
            tnode* e=search(n,&parent);
            if(e!=NULL)
            {
                printf("\nElement found : %d\n",e->data);
            }
            else
            {
                printf("\nElement not found\n");
            }
            break;
        case 3:
            preOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            postOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            inOrderTraversal(root);
            printf("\n");
            break;
        case 6:
            printf("Enter the element to be deleted:");
            scanf("%d",&n);
            deleteNode(root,n);
            break;
        case 7:
            flag=false;
            break;
        default:
            printf("Invalid choice!\n");
        }

    }
    while(flag);
}

void insert(int data)
{
    tnode* temp=(tnode*)malloc(sizeof(tnode));
    tnode* current;
    tnode* parent;

    temp->data=data;
    temp->leftChild=NULL;
    temp->rightChild=NULL;

    if(root==NULL)
    {
        root=temp;
    }
    else
    {
        current=root;
        parent=NULL;

        while(true)
        {
            parent=current;

            if(data < parent->data)
            {
                current=current->leftChild;

                if(current == NULL)
                {
                    parent->leftChild=temp;
                    return;
                }
            }
            else
            {
                current=current->rightChild;

                if(current == NULL)
                {
                    parent->rightChild=temp;
                    return;
                }

            }

        }

    }
}

tnode* search(int data,tnode** parent)
{
    tnode* current=root;
    *parent=root;

    while(current->data != data)
    {
        *parent=current;
        if(current !=NULL)
        {
            printf("%d ",current->data);
        }

        if(current->data > data)
        {
            current = current->leftChild;
        }
        else
        {
            current= current->rightChild;
        }

        if(current == NULL)
        {
            return NULL;
        }
    }
    return current;
}

void preOrderTraversal(tnode* root)
{
    if(root != NULL)
    {
        printf("%d ",root->data);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void inOrderTraversal(tnode* root)
{
    if(root != NULL)
    {
        inOrderTraversal(root->leftChild);
        printf("%d ",root->data);
        inOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(struct node* root)
{
    if(root != NULL)
    {
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ", root->data);
    }
}

void deleteNode(tnode* root,int data)
{
    tnode* parent=(tnode*)malloc(sizeof(tnode));

    tnode* current=search(data,&parent);

    if(current==NULL)
    {
        return;
    }

    if(current->leftChild==NULL && current->rightChild==NULL)
    {
        if(current!=NULL)
        {
            if(parent->leftChild==current)
            {
                parent->leftChild=NULL;
            }
            else
            {
                parent->rightChild=NULL;
            }
        }
        else
        {
            root=NULL;
        }
        free(current);
    }
    else if(current->leftChild && current->rightChild)
    {

        tnode* inOrderSuccesor=NULL;

        tnode* temp=current->rightChild;

        while(temp->leftChild!=NULL)
        {
            //printf("%d",current->leftChild->data);
            temp=temp->leftChild;
        }

        inOrderSuccesor=temp;

        int v=inOrderSuccesor->data;

        deleteNode(root,v);

        current->data=v;

    }
    else
    {
        tnode* child=(current->leftChild)?current->leftChild:current->rightChild;

        if(current!=root)
        {
            if(current==parent->leftChild)
            {
                parent->leftChild=child;
            }
            else
            {
                parent->rightChild=child;
            }
        }
        else
        {
            root = child;
        }

        free(current);

    }

}




