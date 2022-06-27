/*
Author: Varun Kakathiya
Contest: -
Problem: Hamiltonian Cycle
*/
 
#include <stdio.h>
#include<stdbool.h>
int g[10][10];
int x[10];
int flag=0;
int n,start;
void hamiltonian(int k)
{
    x[1]=start;
    do
    {
        nextvalue(k);
        if( x[k] == 0) return;
        if(k==n)
        {
            flag=1;
            for(int i=1;i<=n;i++)
            printf("%d    ",x[i]);
              printf("\n");
        }
        else
        hamiltonian(k+1);
    }
    while(true);
}
void nextvalue(int k)
{
    int j=0;
    do{
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0) return;
        if(g[x[k-1]][x[k]]==1)
        {
            for(j=1;j<=k-1;j++)
                if(x[j]==x[k]) break;
                if(j==k)
                    if(  k<n || ((k==n) && g[x[n]][x[1]]==1))
                     return;
        }
    }
    while(true);
}
 
int main() {
 
        scanf("%d",&n); //total no of vertices
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            scanf("%d",&g[i][j]);
        }
//      printf("Enter starting node\n");
        scanf("%d",&start); //starting node
        hamiltonian(2);
        if(!flag)
        printf("Hamilton  cycle does not exist\n");
        return 0;
}
 
/* INPUT:
   6
0 1 1 0 0 1
1 0 1 0 0 1
1 1 0 1 0 0
0 0 1 0 1 0
0 0 0 1 0 1
1 1 0 0 1 0
1
 
OUTPUT:
1    2    3    4    5    6    
1    2    6    5    4    3    
1    3    4    5    6    2    
1    6    5    4    3    2  
 
*/
