#include<stdlib.h>
#include <stdio.h>
     
void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
void displayPointerValue();
 
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()     
{
        int choice;
        while(1){
               
                printf("\nMENU \n");
                printf("\n1.Create");
                printf("\n2.Display");
                printf("\n3.Insert at the beginning");
                printf("\n4.Insert at the end");
                printf("\n5.Insert at specified position");
                printf("\n6.Delete from beginning");
                printf("\n7.Delete from the end");
                printf("\n8.Delete from specified position");                
                // printf("\n9.Display Using Pointer Value");
                printf("\n9.Exit");
                printf("\n--------------------------------------\n");
                printf("\nEnter your choice:\t");
                scanf("%d",&choice);
                printf("\n--------------------------------------\n");
                switch(choice)
                {
                        case 1:
                                        create();
                                        break;
                        case 2:
                                        display();
                                        break;
                        case 3: 
                                        insert_begin();
                                        break;
                        case 4:
                                        insert_end();
                                        break;
                        case 5:
                                        insert_pos();
                                        break;
                        case 6:
                                        delete_begin();
                                        break;
                        case 7:
                                        delete_end();
                                        break;
                        case 8:
                                        delete_pos();
                                        break;
                        
                        // case 9:
                        //                 displayPointerValue();
                        //                 break;

                        case 9:
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}
void create()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                exit(0);
        }
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->info);
        printf("\n--------------------------------------\n");
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                printf("\n--------------------------------------\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        //Value
                        printf("\nValue: %d\t",ptr->info );                        
                        
                        //Pointer Address
                        printf("Pointer Address: %p", (void*)*(&ptr));

                        //Value at the Pointer Address
                        //printf("\n%d", **(&ptr));    

                        //Value - Pointer Address - Pointer
                        //printf("\n%d\t%p\t%p\n",(ptr)->info,ptr,&ptr);                    
                        
                        ptr=ptr->next ;
                }
                printf("\n--------------------------------------\n");
        }
}
void displayPointerValue()
{
        char pointer[8];
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                printf("\n--------------------------------------\n");
                return;
        }
        else
        {
                printf("\nEnter Pointer Value:\t");
                scanf("%s",pointer);
                printf("\n%d", **(&pointer));
                printf("\n--------------------------------------\n");
        }
}
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                printf("\n--------------------------------------\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        printf("\n--------------------------------------\n");
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                printf("\n--------------------------------------\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info );
        printf("\n--------------------------------------\n");
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                printf("\n--------------------------------------\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->info) ;
        printf("\n--------------------------------------\n");
  
        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++) { ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                printf("\n--------------------------------------\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\nList is Empty:\n");
                printf("\n--------------------------------------\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is: %d\t",ptr->info);
                free(ptr);
        }
        printf("\n--------------------------------------\n");
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nList is Empty:");
                printf("\n--------------------------------------\n");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is: %d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is: %d\t",ptr->info);
                free(ptr);
        }
        printf("\n--------------------------------------\n");
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                printf("\n--------------------------------------\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is: %d\t",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) { temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is: %d\t",ptr->info );
                        free(ptr);
                }
        }
        printf("\n--------------------------------------\n");
}