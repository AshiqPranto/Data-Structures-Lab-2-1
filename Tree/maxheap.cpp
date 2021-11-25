#include<iostream>
using namespace std;
const int capacity = 500;

int min_heap[capacity+5];
int heap_size = 0;
void insert(int value)
{
    if(heap_size == capacity)
    {
        printf("OVERFLOW\n");
        return;
    }
    heap_size++;
    int i = heap_size;
    min_heap[i] = value;
    while (i>1 && min_heap[i/2]>min_heap[i])
    {
        swap(min_heap[i/2],min_heap[i]);
        i =i/2;
    }
}
void show_min_heap()
{
    for(int i = 1;i<=heap_size;i++)
    {
        printf("min_heap[%d] = %d\n",i,min_heap[i]);
    }
}

int main()
{
    printf("Enter the number of node your want to insert: ");
    int num_of_node;
    scanf("%d",&num_of_node);
    while (num_of_node--)
    {
        int temp;
        scanf("%d",&temp);
        insert(temp);
    }
    show_min_heap();
    
}