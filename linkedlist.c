/*linked list */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};
struct node *START=NULL;
struct node * create_node()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
}
void insertnode()
{
    struct node *temp,*ptr;
    temp=create_node();
    printf("\nenter the data");
    scanf("%d",&temp->info);
    temp->link=NULL;
    if(START==NULL)
    START=temp;
    else
    {
        ptr=START;
while(ptr->link!=NULL)
   ptr=ptr->link;

   ptr->link=temp;
    }

}
void deletenode()
{
    struct node *r;
    if(START==NULL)
    printf("\nlist is empty");
    else
    {
        r=START;
        START=START->link;
        free(r);
    }
}
void view()
{
    struct node *t;
    if(START==NULL)
    printf("\nList is empty");
    else{
        t=START;
        while(t!=NULL)
        {
            printf("\t%d",t->info);
            t=t->link;
        }

    }
}

void main()
{
    int n;
    while(1)
    {
        
        printf("\n1.add a value at end\n2.delete a first value\n3.view the list\n4.exit ");
        printf("\nenter the choice:");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            insertnode();
            break;

        case 2:
            deletenode();
            break;
        case 3:
            view();
            break;
        case 4: 
        exit(0);
        default:
        printf("\nwrong choice");
    }
    }    getch();
    

    
    }
