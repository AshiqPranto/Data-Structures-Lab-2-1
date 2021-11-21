#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>
using namespace std;
 
#define mx  (int)20
#define inf 100000000
 
float st[mx];
int top = -1;
char temp[50];
float item;
 
void push(float value)
{
   if(top == mx-1)
   {
       printf("Your stack is empty...! :(\n");
       return;
   }
   st[++top] = value;
}
float pop()
{
   if(top == -1)
   {
       printf("Can't perform the operation. Because the stack has no element to pop..! :(\n");
       return inf;
   }
   return st[top--];
}
void showStack()
{
   printf("show stack called\n");
   for(int t = 0;t<=top;t++)
   {
       printf("%f,",st[t]);
   }
}
float do_operation(float op1, float op2, char ch)
{
   if(ch=='+') return op2+op1;
   else if(ch=='-') return op2-op1;
   else if(ch=='*') return op2*op1;
   else if(ch=='/') return op2/op1;
   else return pow(op2,op1);
 
}
 
int main()
{
 
   char arr[200];
   printf("Enter Your Postpix expression: ");
   fgets(arr,20,stdin);
 
   int sz = strlen(arr);
//    printf("size = %d\n",sz);
//    for(int i =0 ;i<sz;i++) printf("%c",arr[i]);
//    cout<<endl;
 
   int i = 0;
 
   while (i!=sz)
   {
        // printf("i = %d\n",i);
       int j = 0;
       if(isdigit(arr[i]))
       {
        //    printf("isdigit called\n");
           while (arr[i]!=',' && arr[i]!='\0')
           {
               temp[j++] = arr[i++];
           }
           temp[j] = '\0';
           item = atof(temp);
           // printf("item = %f\n",item);
           // printf("top = %d\n",top);
           push(item);
           // printf("top = %d\n",top);
           // showStack();
       }
       else if(arr[i]==',')
       {
           i++;
        //    printf("COMMA called\n");
       }
       else{
        //    printf("else called\n");
        //    showStack();
           float op1 = pop();
           float op2 = pop();
           item = do_operation(op1,op2,arr[i]);
           push(item);
          i++;
       }
    //    else
       
   }
   printf("%f",pop());
  
 
   // while (1)
   // {
   //     int choice;
   //     printf("Enter your choice: ");
   //     printf("1 for push a value into stack\n");
   //     printf("2 for pop from stack\n");
   //     scanf("%d",&choice);
 
   //     switch (choice)
   //     {
   //     case 1:
   //         push();
   //         break;
   //     case 2:
   //         pop();
   //         break;
      
   //     default:
   //         break;
   //     }
   // }
  
  
}
