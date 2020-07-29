/*
    CPP Program to Implement InsertionSort Sorting Algorithm 
    Author- Pijush Bhuyan
    Created on - 29/07/2020
*/
#include<iostream>
using namespace std;

void insertionSort(int *A, int n)               // main insertion sort function
{
    for(int j=1;j<n;j++)
    {
        int i=j-1;
        int key = A[j];                         // find correct position for placing key into sorted left half A[0,j-1]
        while(i>=0 && A[i]>key)
        {
            A[i+1]=A[i];                        // shift elements greater than key to the right
            i--;
        }
        i+=1;                                   
        A[i]=key;                               // insert key into correct index found as i
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
    insertionSort(arr,n);                        // run insertion sort algorithm on array arr
    cout<<"The sorted list is : ";
    display(arr,n);                             // display the sorted array arr
    return 0;
}