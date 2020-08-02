/*
    CPP Program to solve greedy fractional knapsack problem 
    Author- Pijush Bhuyan
    Created on - 01/08/2020
*/
#include<iostream>
#include<algorithm>
using namespace std;

struct item                                             // structure to hold details of each item
{
    float value;
    float weight;
};
bool compare(item a, item b)                            // comparator function to sort in non increasing order of density(value/weight)
{
    return a.value/a.weight > b.value/b.weight;
}
float greedyKnapsack(item a[],int n,float W)            // greedy algorithm for fractional knapsack with capacity W
{
    float Value=0;
    sort(a,a+n,compare);                                // sort items in non increasing order of value density
    int i;
    for(i=0;i<n;i++)
    {
        if(W>0 && a[i].weight<=W )                      // 1st fill up items that fill as a whole into the knapsack
        {
            Value += a[i].value;
            W-=a[i].weight;
        }
        else break;
    }
    if(W>0)                                             // fill fractional items knapsack is still not full
        Value+=a[i].value*(W/a[i].weight);
    return Value;
}
int main()                                              // main driver function
{
    item a[3] = {{25,18},{24,15},{15,10}};                                              // 3 items are available to fit in knapsack with (value,weight) given
    cout<<"The knapsack contains items are worth : "<<greedyKnapsack(a,3,20);           // solve for a knapsack with capacity 20 units
}
