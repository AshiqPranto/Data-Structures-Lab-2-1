#include<iostream>
using namespace std;
 
struct node
{
   int info;
   struct node *next;
};
struct node *start = NULL;
 
 
void create_node()
{
   struct node *temp,*ptr;
 
   temp = (struct node*)malloc(sizeof(struct node));
 
   temp->next = NULL;
   printf("Enter the data value for the node: ");
   scanf("%d",&temp->info);
 
   if(start == NULL)
   {
       start = temp;
       return ;
   }
   else{
 
       ptr = start;
       while (ptr->next!=NULL)
       {
           ptr = ptr->next;
       }
       ptr->next = temp;
      
   }
}
 
void insert_begin()
{
   struct node *temp;
   temp = (struct node*)malloc(sizeof(struct node));
   if(temp == NULL)
   {
       printf("OUT of Memory\n");
       return;
   }
   else if(start == NULL)
   {
       printf("Please Create a node First\n");
       return;
   }
   else
   {
       printf("Enter your value: ");
       scanf("%d",&temp->info);
       temp->next = NULL;
   }
  
   if(start==NULL)
   {
       start = temp;
   }
   else{
       temp->next = start;
       start = temp;
   }
 
}
void insert_end()
{
   struct node *temp,*ptr;
   temp = (struct node*)malloc(sizeof(struct node));
 
   if(temp == NULL)
   {
       printf("OUT of Memory\n");
       return;
   }
   printf("Enter the data value for the node\n");
   scanf("%d",&temp->info);
   temp->next = NULL;
 
   if(start == NULL)
   {
       start = temp;
   }
   else
   {
       ptr = start;
       while (ptr->next!=NULL)
       {
           ptr = ptr->next;
       }
       ptr->next = temp;
      
   }
 
}
void delete_begin()
{
   if(start == NULL)
   {
       printf("Linked list is EMPTY..!\n");
       return;
   }
   struct node *ptr;
   ptr = start;
   start = start->next;
   printf("Deleted file is %d\n",ptr->info);
   free(ptr);
}
 
void delete_end()
{
    struct node *ptr,*prev;
   if(start == NULL)
   {
       printf("Linked list is EMPTY....!\n");
       return;
   }
   else if (start->next == NULL)
   {
       ptr = start;
       printf("Deleted element is %d\n",ptr->info);
       free(ptr);
       start = NULL;
       return;
   }
   else{
        ptr = start;
        while (ptr->next!=NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        printf("Deleted element is %d\n",ptr->info);
        free(ptr);
           
   }
  
}

void insert_node_pos()
{
    struct node *temp,*ptr;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp==NULL)
    {
        printf("Out of Memory..!\n");
        return;
    }
    int pos = 0;
    printf("Enter the pos you want to insert node.(Index start at 0)");
    scanf("%d",&pos);
    printf("Enter the value of your node: ");
    scanf("%d",&temp->info);
    temp->next = NULL;
    if(pos == 0)
    {
        temp->next = start;
        start = temp;
        return;
    }
    ptr = start;
    for(int i = 0; i<pos-1;i++)
    {
        ptr = ptr->next;
        if(ptr == NULL) 
        {
            printf("Invalid position!\n");
            return;
        }
    }
    temp->next = ptr->next;
    ptr->next = temp;
}
 
void display()
{
   struct node *ptr;
   if(start==NULL)
   {
       printf("Linked list is empty....! :( \n");
       return ;
   }
 
   printf("The Elements are: ");
 
   ptr = start;
   while (ptr!=NULL)
   {
       printf("%d, ",ptr->info);
       ptr = ptr->next;
   }
  
}
 
 
int main()
{
 
   int choice;
   while (true)
   {
       printf("Enter your Choice...\n");
       printf("1 for Create Node\n");
       printf("2 for Insert Node Begin\n");
       printf("3 for Insert Node End\n");
       printf("4 for Insert Node Pos\n");
       printf("5 for Delete Begin\n");
       printf("6 for Delete End\n");
       printf("9 for display node\n");
       printf("0 for exit\n");
 
       scanf("%d",&choice);
      
       switch (choice)
       {
       case 1:
           create_node();
           break;
       case 2:
           insert_begin();
           break;
       case 3:
           insert_end();
           break;
       case 4:
           insert_node_pos();
           break;
        case 5:
            delete_begin();
            break;
        case 6:
            delete_end();
            break;
       case 9:
           display();
           break;
       case 0:
           return 0;
      
       default:
           break;
       }
 
       printf("\n\n");
      
   }
  
   // create_node();
  
   // insert_node();
  
   // display();  
}
