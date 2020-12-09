#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int matrixChainDP(int p[],int n)
{
    int m[n+1][n+1];        // create 2d array to store intermediate results
    for(int l=0;l<=n;l++)
    {
        for(int i=1;i<=n;i++)
        {
            int j = i+l;
            if(j<=n)
            {
                if(i==j)
                    m[i][j]=0;  // initialize diagonal elements to 0
                else
                {
                    int min =  (int)pow(2,8*sizeof(int)-1) -1;      // initialize min to infinty (here upper limit of int datatype)
                    for(int k=i;k<j;k++)        // explore all partitions possible for A[i]A[i+1]...A[j]
                    {
                        int x = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                        min = x<min?x:min;
                    }
                    m[i][j] = min;  // store min scalar multiplications required for A[i]A[i+1]...A[j]
                }
            }
        }
    }
    return m[1][n]; // return min scalar multiplications requried for A[1]A[2]...A[n]
}

int main()
{
    int p[11] = {10,15,20,25,30,35,40,45,50,55,60}      // dimensions of 10 matrices A[1] to A[10] with dimenison of A[i] = p[i-1]xp[i], i>=1
    printf("The optimal no of scalar multiplications is : %d",matrixChainDP(p,10));

    return 0;
}
