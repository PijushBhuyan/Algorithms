/* CPP Program to Implement a Maximum Binary Heap 
    Author- Pijush Bhuyan
    Created on - 30/04/2021
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class MaxHeap
{
    private:
        void swap(int *x, int *y);      // basic swap function
        void MaxHeapify(int index);     // heapify the sub tree rooted at given index
        void buildMaxHeap();            // build the max heap 
    public:
        int heap_size;      // tracks the sizeof the max heap
        vector<int> heap;   // actual max heap
        
        MaxHeap(int arr[],int size);   // constructor to initialize max heap
        void display();     // display the max heap
        int extractMax();   // extract the maximum key from the max heap
        bool decreaseKey(int index, int key);   // decrease a particular key at given index to new value
        bool increaseKey(int index, int key);   // increase a particular key at given index to new value
        void insertKey(int key);    // insert a new key into the max heap
        bool deleteKey(int index);  // remove a key located at given index from the max heap
};

void MaxHeap:: swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MaxHeap::MaxHeapify(int index)
{
    if(index>=heap_size)
        return;
    int lchild = 2*index+1;
    int rchild = 2*index+2;
    int largest = index;
    if(lchild <heap_size && heap[lchild]>heap[largest])
        largest = lchild;
    if(rchild <heap_size && heap[rchild]>heap[largest])
        largest = rchild;
    if(largest!=index)
    {
        swap(&heap[index],&heap[largest]);
        MaxHeapify(largest);
    }
}

void MaxHeap::buildMaxHeap()
{
    for(int i=heap_size/2;i>=0;i--)
    {
        MaxHeapify(i);
    }
}

MaxHeap::MaxHeap(int arr[],int size)
{
    heap_size= size;
    for(int i=0;i<heap_size;i++)
    {
        heap.push_back(arr[i]);
    }
    buildMaxHeap();
}
        
void MaxHeap::display()
{
    for(int i=0;i<heap_size;i++)
    {
        cout<<heap[i]<<"\t";
    }
    cout<<endl;
}

int MaxHeap::extractMax()
{
    int max = heap[0];
    heap[0] = heap[heap_size-1];
    heap_size--;
    heap.pop_back();
    MaxHeapify(0);
    return max;
}

bool MaxHeap::increaseKey(int index, int key)
{
    if (index>=heap_size || key<heap[index])
        return false;
    heap[index] = key;
    while(index>0 && heap[index]>heap[(index-1)/2])
    {
        swap(&heap[index],&heap[(index-1)/2]);
        index/=2;
    }
    return true;
}

bool MaxHeap::decreaseKey(int index, int key)
{
    if (index>=heap_size || key>heap[index])
        return false;
    heap[index] = key;
    MaxHeapify(index); 
    return true;
}

void MaxHeap::insertKey(int key)
{
    heap_size++;
    heap.push_back(key);
    int index = heap_size-1;
    while(index>0 && heap[index]>heap[(index-1)/2])
    {
        swap(&heap[index],&heap[(index-1)/2]);
        index/=2;
    }
}

bool MaxHeap::deleteKey(int index)
{
    if(index>=heap_size)
        return false;
    (index,INT_MAX);
    extractMax();
    return true;
}

int main()  // driver code
{
    int arr[] = {10,20,30,40,50,60,70,80};  // sample array used to build a max heap
    MaxHeap h(arr,8);
    h.display();        // should dispaly 80 50 70 40 10 60 30 20
    h.decreaseKey(4,5);
    h.display();        // should dispaly 80 50 70 40 5 60 30 20
    h.increaseKey(7,90);
    h.display();        // should dispaly 90 80 70 50 5 60 30 40
    h.insertKey(45);
    h.display();        // should dispaly 90 80 70 50 5 60 30 40 45
    h.insertKey(72);
    h.display();        // should dispaly 90 80 70 50 72 60 30 40 45 5
    h.deleteKey(1);
    h.display();        // should dispaly 90 72 70 50 5 60 30 40 45
    cout<<"heap size : "<<h.heap_size<<endl;    // should display 9
    return 0;
}