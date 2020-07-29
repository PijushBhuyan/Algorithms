/*
    CPP Program to Implement Heapsort Sorting Algorithm using Max Heap Data Structure
    Author- Pijush Bhuyan
    Created on - 29/07/2020
*/
#include<iostream>
using namespace std;


void maxHeapify(int *A, int i, int heap_size)   // function to heapify a binary tree at a particular node with index i
{
    int l = 2*i+1;
    int r  =2*i+2;
    int largest = i;
    if(l<heap_size && A[l]>A[i])
        largest = l;
    if(r<heap_size && A[r]>A[largest])
        largest=r;
    if(largest!=i)
    {
        int temp = A[i];                        // swap nodes with index i and largest
        A[i] = A[largest];
        A[largest]=temp;
        maxHeapify(A,largest,heap_size);        // heapify the subtree with root having index = largest
    }
}
void buildMaxHeap(int *arr,int n)               // function to build a max heap
{
    for(int i=n/2-1;i>=0;i--)
        maxHeapify(arr,i,n);
}

void heapsort(int *arr,int n)                   // main heapsort function
{
    int heap_size = n;
    buildMaxHeap(arr,n);    
    for(int i=n-1;i>=1;i--)
    {
        int temp = arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heap_size--;
        maxHeapify(arr,0,heap_size);
    }
}

void display(int* A,int n)                      // utility function to print the elements of the array
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<"\t";
    cout<<endl;
}

int main()                                      // main driver function
{
    int n ,*arr;
    cout<<"Size of list : ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    heapsort(arr,n);                            // run heapsort algorithm on array arr
    cout<<"The sorted list is : ";
    display(arr,n);                             // display the sorted array arr
    return 0;
}