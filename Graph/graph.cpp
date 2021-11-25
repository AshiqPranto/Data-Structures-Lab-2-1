#include<iostream>
#include<cstring>
using namespace std;
 
int graph[500][500];
int num_of_nodes,num_of_edge,u,v;
 
void display()
{
   for(int i = 1;i<=num_of_nodes;i++)
   {
       for(int j = 1;j<=num_of_nodes;j++)
       {
           printf("%d ",graph[i][j]);
       }
       printf("\n");
   }
}
 
void print_adjacent_node()
{
   for(int i = 1;i<=num_of_nodes;i++)
   {
       printf("Adjacent of %d -> ",i);
       for (int j = 1; j<=num_of_nodes; j++)
       {
           if(graph[i][j]==1)
           {
               printf("%d, ",j);
           }
       }
       cout<<endl;
   }
}
void copy(int (&a)[500][500],int (&b)[500][500])
{
   for(int i =1;i<=num_of_nodes;i++)
   {
       for(int j = 1;j<=num_of_nodes;j++)
       {
           b[i][j] = a[i][j];
       }
   }
 
}

void multi(int (&a)[500][500],int (&b)[500][500],int (&c)[500][500])
{
    for(int i = 1;i<=num_of_nodes;i++)
    {
        for(int j = 0;j<=num_of_nodes;j++)
        {
            int sum = 0;
            for(int k = 1;k<=num_of_nodes;k++)
            {
                sum+= a[i][k]*b[k][j];
            }
            c[i][j] = sum;
        }
    }
}

void num_of_path_of_length_2()
{
    int b[500][500],c[500][500];
    copy(graph,b);
    multi(graph,b,c);
    
    printf("Num of path of length 2\n");
    printf("Enter source and destination node:\n");
    int u,v;
    scanf("%d %d",&u,&v);
    printf("Number of path %d\n",c[u][v]);
}
void num_of_path_of_length_3()
{
    int p = 3;
    int b[500][500],c[500][500];
    copy(graph,b);
    multi(graph,b,c);
    copy(c,b);
    multi(graph,b,c);
    printf("Num of path of length 3\n");
    printf("Enter source and destination node:\n");
    int u,v;
    scanf("%d %d",&u,&v);
    printf("Number of path %d\n",c[u][v]);
}
void num_of_path_of_length_4()
{
    int b[500][500],c[500][500];
    copy(graph,b);
    for(int i = 1;i<4;i++)
    {
        multi(graph,b,c);
        copy(c,b);
    }
    printf("Num of path of length 4\n");
    printf("Enter source and destination node:\n");
    int u,v;
    scanf("%d %d",&u,&v);
    printf("Number of path %d\n",c[u][v]);
}
 
int main()
{
   printf("Enter the number of nodes of your graph: ");
   scanf("%d",&num_of_nodes);
   // int graph[num_of_nodes+5][num_of_nodes+5];
 
   // initializing my graph array with all index 0
 
   memset(graph,0,sizeof(graph));
 
 
   printf("Enter number of edge:");
   scanf("%d",&num_of_edge);
 
   printf("Enter your all edges:\n");
   while (num_of_edge--)
   {
       scanf("%d %d",&u,&v);
       graph[u][v] = 1;
   }
//    display();
//    print_adjacent_node();
//    num_of_path_of_length_2();
//     num_of_path_of_length_3();
    // num_of_path_of_length_4();
}
