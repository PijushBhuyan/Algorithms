/*
    CPP Program to Implement Quicksort Sorting Algorithm with randomized pivot
    Author- Pijush Bhuyan
    Created on - 29/07/2020
*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void swap(int *a, int *b)                           // utility swap function
{
    int temp = *a;
    *a=*b;
    *b=temp;
}
int partition(int *A, int p,int r)                  // partition function with randomized pivot
{
    srand(time(0));
    int rand_index = p + rand()%(r-p+1);            // generate a random index in range [p,r]
    swap(&A[rand_index],&A[r]);                     // swap contents of random index and r                    
    int pivot = A[r];                               // now take pivot as A[r]
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        if(A[j]<=pivot)
        {
            i+=1;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;                                     // return pivoted index
}

void quicksort(int *A, int p, int r)                // main quicksort function
{
    if(p<r)
    {
        int q = partition(A,p,r);                   // element at index q is  now sorted
        quicksort(A,p,q-1);                         // sort left half i.e. A[p,q-1]
        quicksort(A,q+1,r);                         // sort right half i.e. A[q+1,r]
    }
}

void display(int* A,int n)                          // utility function to print the elements of the array
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<"\t";
    cout<<endl;
}

int main()
{
    int n ,*arr;
    cout<<"Size of list : ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    quicksort(arr,0,n-1);                           // run quicksort sort algorithm on array arr
    cout<<"The sorted list is : ";
    display(arr,n);                                 // display the sorted array arr
    return 0;
}