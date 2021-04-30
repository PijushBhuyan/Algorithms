/* CPP Program to Implement a Minimum Binary Heap 
    Author- Pijush Bhuyan
    Created on - 30/04/2021
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MinHeap
{
    private:
        void swap(int *x, int *y);      // basic swap function
        void minHeapify(int index);     // heapify the sub tree rooted at given index
        void buildMinHeap();            // build the min heap 
    public:
        int heap_size;      // tracks the sizeof the min heap
        vector<int> heap;   // actual min heap
        
        MinHeap(int arr[],int size);   // constructor to initialize min heap
        void display();     // display the min heap
        int extractMin();   // extract the minimum key from the min heap
        bool decreaseKey(int index, int key);   // decrease a particular key at given index to new value
        bool increaseKey(int index, int key);   // increase a particular key at given index to new value
        void insertKey(int key);    // insert a new key into the min heap
        bool deleteKey(int index);  // remove a key located at given index from the min heap
};

void MinHeap:: swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::minHeapify(int index)
{
    if(index>=heap_size)
        return;
    int lchild = 2*index+1;
    int rchild = 2*index+2;
    int smallest = index;
    if(lchild <heap_size && heap[lchild]<heap[smallest])
        smallest = lchild;
    if(rchild <heap_size && heap[rchild]<heap[smallest])
        smallest = rchild;
    if(smallest!=index)
    {
        swap(&heap[index],&heap[smallest]);
        minHeapify(smallest);
    }
}

void MinHeap::buildMinHeap()
{
    for(int i=heap_size/2;i>=0;i--)
    {
        minHeapify(i);
    }
}

MinHeap::MinHeap(int arr[],int size)
{
    heap_size= size;
    for(int i=0;i<heap_size;i++)
    {
        heap.push_back(arr[i]);
    }
    buildMinHeap();
}
        
void MinHeap::display()
{
    for(int i=0;i<heap_size;i++)
    {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}

int MinHeap::extractMin()
{
    int min = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
    heap.pop_back();
    minHeapify(0);
    return min;
}

bool MinHeap::decreaseKey(int index, int key)
{
    if (index>=heap_size || key>heap[index])
        return false;
    heap[index] = key;
    while(index>0 && heap[index]<heap[(index-1)/2])
    {
        swap(&heap[index],&heap[(index-1)/2]);
        index/=2;
    }
    return true;
}

bool MinHeap::increaseKey(int index, int key)
{
    if (index>=heap_size || key<heap[index])
        return false;
    heap[index] = key;
    minHeapify(index); 
    return true;
}

void MinHeap::insertKey(int key)
{
    heap_size++;
    heap.push_back(key);
    int index = heap_size-1;
    while(index>0 && heap[index]<heap[(index-1)/2])
    {
        swap(&heap[index],&heap[(index-1)/2]);
        index/=2;
    }
}

bool MinHeap::deleteKey(int index)
{
    if(index>=heap_size)
        return false;
    decreaseKey(index,INT_MIN);
    extractMin();
    return true;
}

int main()  // driver code
{
    int arr[] = {80,70,60,50,40,30,20,10};  // sample array used to build a min heap
    MinHeap h(arr,8);
    h.display();        // should dispaly 10 40 20 50 80 30 60 70
    h.decreaseKey(7,5);
    h.display();        // should dispaly 5 10 20 40 80 30 60 50
    h.increaseKey(2,25);
    h.display();        // should dispaly 5 10 25 40 80 30 60 50
    h.insertKey(45);
    h.display();        // should dispaly 5 10 25 40 80 30 60 50 45
    h.insertKey(72);
    h.display();        // should dispaly 5 10 25 40 72 30 60 50 45 80
    h.deleteKey(1);
    h.display();        // should dispaly 5 40 25 45 72 30 60 50 80
    cout<<"heap size : "<<h.heap_size<<endl;    // should display 9
    return 0;
}