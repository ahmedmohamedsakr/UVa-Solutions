#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int M=10,OO=0x3f3f3f3f;
int n,N,line;
int sudo[M][M];

bool FindUnassignedLocation(int &row,int &col)
{

    for(row=0; row<N; ++row)
        for(col=0; col<N; ++col)if(sudo[row][col]==0)return 1;
    return 0;
}

bool UsedInCol(int col, int num)
{
    for(int row=0; row<N; ++row)if(sudo[row][col]==num)return 1;
    return 0;
}

bool UsedInRow(int row, int num)
{
    for(int col=0; col<N; ++col)if(sudo[row][col]==num)return 1;
    return 0;
}
bool UsedInBox(int boxStartRow, int boxStartCol, int num)
{
    for(int row=0; row<n; ++row)
        for(int col=0; col<n; ++col)if(sudo[boxStartRow+row][boxStartCol+col]==num)return 1;
    return 0;
}

bool isSafe(int row, int col, int num)
{
    return
        !UsedInRow(row, num) &&
        !UsedInCol(col, num) &&
        !UsedInBox(row - row%n, col - col%n, num)&&
        sudo[row][col]==0;
}

bool solve()
{
    int row,col;
    if(!FindUnassignedLocation(row,col))return 1;
    for(int num=1; num<=N; ++num)
    {
        if(isSafe(row, col, num))
        {
            sudo[row][col]=num;
            if(solve())return 1;
            sudo[row][col]=0;
        }
    }
    return 0;
}

void print()
{
    for (int row = 0; row <N; row++)
    {
        printf("%d",sudo[row][0]);
        for (int col = 1; col < N; col++)
            printf(" %d", sudo[row][col]);
        puts("");
    }
}
int main()
{
    while(scanf("%d",&n)==1)
    {
        N=n*n;
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                scanf("%d",&sudo[i][j]);
        if(line)puts("");
        else line=1;
        if(solve())print();
        else puts("NO SOLUTION");
    }
    return 0;
}
