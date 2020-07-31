/*
    CPP Program to Implement Selection sort Sorting Algorithm 
    Author- Pijush Bhuyan
    Created on - 31/07/2020
*/

#include<iostream>
using namespace std;
void selectionSort(int *A, int n)               // selection sort fucntion
{
    for(int i=0;i<n-1;i++)                      // search for index of min element in A[i,n]
    {
        int min = i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
                min=j;
        }
        int temp = A[i];                        // put A[min] just before the unsorted part i.e. before A[i+1]
        A[i] = A[min];
        A[min] = temp;
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
    selectionSort(arr,n);                        // run selection sort algorithm on array arr
    cout<<"The sorted list is : ";
    display(arr,n);                              // display the sorted array arr
    return 0;
}