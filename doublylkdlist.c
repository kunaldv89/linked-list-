//doubly linked list
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node *START=NULL;
struct node* insertbeg(struct node *START,int item)
{
    struct node * newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    if(START==NULL)
    {
    newnode->prev=NULL;
    newnode->next=NULL;
    START=newnode;
    }
    else
    {
        START->prev=newnode;
        newnode->prev=NULL;
        newnode->next=START;
        START=newnode;
    }
    return START;

}
struct node* deletebeg(struct node *START)
{
    struct node *r;
    int item;
    if(START==NULL)
    printf("\nlist is empty");
    else
    {
        r=START;
        item=r->info;
        START=START->next;
        free(r);
        printf("\ndeleted item=%d",item);
    }
    return START;
}
struct node* insertend(struct node *START,int item)
{
    struct node *newnode,*ptr=START,*preptr;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=item;
    while(ptr!=NULL)
    {
        preptr=ptr;
        ptr=ptr->next;
    }
    preptr->next=newnode;
    newnode->prev=preptr;
    newnode->next=NULL;
    return(START);
    

}
struct node* deleteend(struct node *START)
{
    struct node *r,*preptr,*ptr=START;
    int item;
    if(START==NULL)
    printf("\nlist is empty");
    else
    {
        while(ptr!=NULL)
        {
            preptr=ptr;
            ptr=ptr->next;
        }
        (preptr->prev)->next=NULL;
        r=preptr;
        item=r->info;
        
        free(r);
        printf("\ndeleted item:%d",item);
    }
    return(START);
}


struct node* display(struct node *START)
{
    struct node *ptr;
    if(START==NULL)
    printf("\nlist is empty.");
    else
    {
        ptr=START;
        while(ptr!=NULL)
        {
            printf("\t%d\t",ptr->info);
            ptr=ptr->next;
        }
    }
    return START;
}
void main()
{
    int value,choice;
    while(1)
    {
    
    printf("\n ENTER YOUR CHOICE:\n 1.insert at begining\n 2.delete at begining\n 3.display the list\n 4.insert at end\n 5.delete at end\n 6.exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        printf("\nenter the value:");
        scanf("%d",&value);
        START=insertbeg(START,value);
        break;
        case 2:
        START=deletebeg(START);
        break;
        case 3:
        START=display(START);
        break;
        case 4:
        printf("\nenter the value:");
        scanf("%d",&value);
        START=insertend(START,value);
        break;
        case 5:
        START=deleteend(START);
        break;
        case 6:
        exit(0);
        default:
        printf("\nwrong choice");
        break;
    }
    }
    getch();

} 

