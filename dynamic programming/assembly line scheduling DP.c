#include<stdio.h>
#include<stdlib.h>
int min(int a, int b)
{
    return a<b?a:b;
}
int* findOptimalPathDP(int n, int a[][2], int t[][2])   // function to find the optimal path and cost for travelling throught the assembly
{
    int T[n][2];
    int path[n][2];
    int* optimal_soln = (int*)malloc((n+1)*sizeof(int));
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            T[i][0] = t[n][0] + a[i][0];    // optimal time for exiting station 1 of track 1
            T[i][1] = t[n][1] + a[i][1];    // optimal time for exiting station 1 of track 2
        }
        else
        {
            T[i][0] = min(T[i-1][0]+a[i][0],T[i-1][1]+t[i-1][1]+a[i][0]);     // optimal time for exiting station i+1 of track 1
            path[i][0] = (T[i-1][0]+a[i][0] ==min(T[i-1][0]+a[i][0],T[i-1][1]+t[i-1][1]+a[i][0]))?0:1;
            T[i][1] = min(T[i-1][1]+a[i][1],T[i-1][0]+t[i-1][0]+a[i][1]);     // optimal time for exiting station i+1 of track 2
            path[i][1] = (T[i-1][0]+t[i-1][0]+a[i][1]==min(T[i-1][1]+a[i][1],T[i-1][0]+t[i-1][0]+a[i][1]))?0:1;
        }
        
    }
    int optimal_time = min(T[n-1][0]+t[n-1][0],T[n-1][1]+t[n-1][1]);
    optimal_soln[n]=optimal_time;
    optimal_soln[n-1] = (T[n-1][0]+t[n-1][0]==optimal_time)?0:1;
    for(int i=n-1;i>=1;i--)
    {
        optimal_soln[i-1] = path[i][optimal_soln[i]];
    }
    
    return optimal_soln;    // optimal_soln[:-2] contains path and optimal_soln[-1] gices the min cost
}   

int main()  // driver function
{
    int n = 5;     // no of stations per track
    int e1 = 10, e2 = 12; // entry times into track 1 and 2
    int x1 = 18, x2 = 7; // exit times from track 1 and 2
    int a[][2] = {{4,2},{15,10},{3,1},{2,7},{5,4}};    // working time for each station of tracks 1 and 2
    int t[][2] = {{9,7},{2,11},{4,3},{2,9},{x1,x2},{e1,e2}};  // transfer time to each station of tracks 1 and 2 with t[n-1]=exit times and t[n]=entry times
    int* optimal_soln = findOptimalPathDP(n,a,t);
    printf("Min time = %d\n",optimal_soln[n]);
    printf("optimal path constructed: ");
    for(int i=0;i<n;i++)
        printf("\t%d",optimal_soln[i]+1);
    printf("\n");
    return 0;
}