/*
    CPP Program to Implement Bubblesort Sorting Algorithm 
    Author- Pijush Bhuyan
    Created on - 31/07/2020
*/
#include<iostream>
using namespace std;
void BubbleSort(int* A,int n)                   // bubblesort function
{
    bool swapped = false;
    for(int i=0;i<n;i++)                        // after i'th iteration, the i'th largest element gets sorted
    {
        for(int j=0;j<n-1-i;j++)                // compare adjacent element pairs A[j],A[j+1] and swap them to make them relatively sorted
        {
            if(A[j]>A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                swapped=true;
            }
        }
        if(!swapped)                            // exit after the i'th iteration as array has already got fully sorted
            break;
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
    BubbleSort(arr,n);                           // run bubblesort algorithm on array arr
    cout<<"The sorted list is : ";
    display(arr,n);                              // display the sorted array arr
    return 0;
}