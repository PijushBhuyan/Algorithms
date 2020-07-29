/*
    CPP Program to Implement Mergesort Sorting Algorithm
    Author- Pijush Bhuyan
    Created on - 28/07/2020
*/
#include<iostream>
using namespace std;

void merge(int *A, int *A_temp,int p, int q, int r) // merge function to merge two sorted sub arrays A[p,q] and A[q+1,r] 
{
    int n1 = q-p+1;                                 // len of A[p,q]
    int n2 = r-q;                                   // len of A[q+1,r]
    for(int i=0;i<n1;i++)                           // copy A[p,q] to global array A_temp
        A_temp[i] = A[p+i];
    for(int i=0;i<n2;i++)                           // copy A[q+1,r] to global array A_temp
        A_temp[n1+i] = A[q+1+i];
    int i=0,j=0,k=p;
    while(i<n1&&j<n2)                               // merge and overwrite to A[p,r]
    {
        if(A_temp[i]<=A_temp[n1+j])
        {
            A[k] = A_temp[i];
            i++;
            k++;
        }
        else
        {
            A[k] = A_temp[n1+j];
            j++;
            k++;
        }
    }
    while(i<n1)
    {
        A[k] = A_temp[i];
        i++;
        k++;
    } 
    while(j<n2)
    {
        A[k] = A_temp[n1+j];
        j++;
        k++;
    }
}
void mergeSort(int *A,int *A_temp, int p, int r)    // function which runs mergesort on array A[p,r]
{
    if(p<r)
    {
        int q = (p+r)/2;
        mergeSort(A,A_temp,p,q);                    // run mergesort on left half i.e. A[p,q]
        mergeSort(A,A_temp,q+1,r);                  // run mergesort on right half i.e. A[q+1,r]
        merge(A,A_temp,p,q,r);                      // merge the two sorted halves
    }
}
void mergeSortDriver(int *A, int n)                 // mergesort driver function
{
    int *A_temp = new int[n];                       // allocate array A_temp with same size , used as extra space required during merging
    mergeSort(A,A_temp,0,n-1);
}

void display(int* A,int n)                          // utility function to print the elements of the array
{
    for(int i=0;i<n;i++)
        cout<<A[i]<<"\t";
    cout<<endl;
}

int main()                                          // main driver function
{
    int n ,*arr;
    cout<<"Size of list : ";
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements :\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    mergeSortDriver(arr,n);                         // run mergesort on array arr
    cout<<"The sorted list is : ";
    display(arr,n);                                  // display the sorted array
    return 0;
}
