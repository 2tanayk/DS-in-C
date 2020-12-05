#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
void main()
{
    int n,i,choice,search,posn,e,f=-1;
    bool flag=true;

    printf("Enter the no. of elements in the array:");
    scanf("%d",&n);

    int a[n+1];

    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
    {
        printf("Enter element %d:",(i+1));
        scanf("%d",&a[i]);
    }
    do
    {

        printf("Enter a number:\n1)Search for an element in the array\n2)Insert an element in the array\n3)Delete an element from the array\n4)exit\n");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            printf("Enter the element you want to search:");
            scanf("%d",&search);

            for(i=0; i<sizeof(a)/sizeof(a[0]); i++)
            {
                if(a[i]==search)
                {
                    f++;
                    printf("%d element found at position %d\n",search,(i+1));

                }
            }
            if(f==-1)
            {
                printf("Element not found\n");

            }

            break;

        case 2:
            printf("Enter the position where you want to insert the element as well as the element:");

            scanf("%d%d",&posn,&e);

            if(posn>=1 && posn<=n)
            {



                for(i=n; i>=posn; i--)
                {
                    a[i]=a[i-1];
                }

                a[posn-1]=e;

                printf("Array after insertion:\n");

                for(i=0; i<n+1; i++)
                    printf("%d\n",a[i]);
            }
            else
            {
                printf("Invalid position\n");
            }

            break;

        case 3:
            printf("Enter the position where you want to delete the element:");

            scanf("%d",&posn);

            if(posn>=1 && posn<=n+1)
            {



                for(i=posn-1; i<n; i++)
                {
                    a[i]=a[i+1];
                }


                printf("Array after deletion:\n(Huge nos. represent the garbage values generated when you delete before inserting in the array )\n");

                for(i=0; i<n; i++)
                {
                    printf("%d\n",a[i]);
                }

            }
            else
            {
                printf("Invalid position\n");
            }

            break;

        case 4:
            flag=false;
            break;


        default:
            printf("please enter a valid choice!");
        }







    }
    while(flag);
}

