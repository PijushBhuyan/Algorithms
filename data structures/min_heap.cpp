/*
    CPP Program to Implement a Min Heap 
    Author- Pijush Bhuyan
    Created on - 2/08/2020
*/
#include<iostream>
using namespace std;

class MinHeap                                               // MinHeap Class
{
    public:
    int * Q;                                                // Q points to the min heap created
    int heap_size;                                          // keeps track so size of the heap
    
    MinHeap(int *arr,int n)                                 // constructor builds heap from i/p array arr of size n
    {
        heap_size =n;                                       
        Q = new int[heap_size];                             // allocate memory for heap of size n
        for(int i=0;i<n;i++)
            Q[i]=arr[i];
        buildMinHeap();                                     // build the min heap
    }
    private:
    void minHeapify(int i);                                 // heapify at root i whose left and right sub trees are min heaps
    void buildMinHeap();                                    // build the min heap using heapify
    public:
    int extractMin();                                       // removes and returns the min element
    void insert(int k);                                     // insert new element into heap

};
void MinHeap :: minHeapify(int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if(l<heap_size && Q[l]<Q[smallest])
        smallest = l;
    if(r<heap_size && Q[r]<Q[smallest])
        smallest = r;
    if(smallest!=i)                                         // swap elements at index i and smallest
    {
        int temp = Q[i];
        Q[i] = Q[smallest];
        Q[smallest]=temp;
        minHeapify(smallest);                               // fix sub tree with root index smallest 
    }
}
void MinHeap :: buildMinHeap()
{
    for(int i=heap_size/2-1;i>=0;i--)                       // build min heap from the lowest non leaf node and build upwards 
    {
        minHeapify(i);
    }
}

int MinHeap :: extractMin()
{
    int min = Q[0];                                         // min is at root
    Q[0]=Q[heap_size-1];                                    // put last element at root
    heap_size--;                                            // decrease heapsize
    minHeapify(0);                                          // heapify at root 
    return min;
}
void MinHeap :: insert(int k)
{
    heap_size++;                                            // increase heapsize
    Q[heap_size-1]=k;                                       // put key at last index
    int i = heap_size-1;
    while(i>0 && Q[i]<Q[(i-1)/2])                           // travel from key to root and swap if child is smaller then parent to rebuild the heap
    {
        int temp = Q[(i-1)/2];
        Q[(i-1)/2]=Q[i];
        Q[i] = temp;
        i=(i-1)/2;
    }
    
}
void display(int *A, int n)                                 // utility function to display an array of size n
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<"\t";
    cout<<endl;
}

int main()                                                  // main driver function
{   
    int arr[10] = {5,3,10,6,2,9,1,15,24,17};                
    MinHeap * h = new MinHeap(arr,10);                      // create min heap from arr[10] and return ref to h
    display(h->Q,h->heap_size);
    cout<<h->extractMin()<<endl;
    cout<<h->extractMin()<<endl;
    display(h->Q,h->heap_size);
    h->insert(16);
    display(h->Q,h->heap_size);
    return 0;
}