#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=1e5,M=10,OO=0x3f3f3f3f;
int cnt,t,f,f1;
int sudo[M][M];
bool FindUnassignedLocation(int &row,int &col)
{

    for(row=0; row<9; ++row)
        for(col=0; col<9; ++col)if(sudo[row][col]==0)return 1;
    return 0;
}

bool isSafe(int row, int col, int num)
{
    for(int i = 0; i < 9; i++)
    {
        if(sudo[row][i] == num && col != i)     return 0;     //Used In row
        if(sudo[i][col] == num && row != i)     return 0;   //used in col
    }
    int x=row-row%3,y= col-col%3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if((x+i) != row && (y+j) != col && sudo[x+i][y+j] == num)   return 0;       //Used In Box
    return 1;
}

void solve()
{
    int row,col;
    if(cnt>1)return;
    if(!FindUnassignedLocation(row,col))
    {
        cnt++;
        return;
    }
    for(int num=1; num<=9; ++num)
    {
        if(isSafe(row, col, num))
        {
            sudo[row][col]=num;
            solve();
            sudo[row][col]=0;
        }
    }
}


int main()
{
    while(~scanf("%d",&sudo[0][0]))
    {
        f=f1=cnt=0;
        for(int i=0; i<9; ++i)
            for(int j=0; j<9; ++j)
            {
                if(f)scanf("%d",&sudo[i][j]);
                f=1;
            }

        for(int i=0; i<9; ++i)
        {
            for(int j=0; j<9; ++j)
            {
                if(sudo[i][j])
                    if(!isSafe(i,j,sudo[i][j]))f1=1;
            }
        }
        if(f1)
        {
            printf("Case %d: Illegal.\n", ++t);
            continue;
        }

        solve();
        if(cnt==1)printf("Case %d: Unique.\n",++t);
        else if(!cnt)printf("Case %d: Impossible.\n",++t);
        else printf("Case %d: Ambiguous.\n",++t);
    }
    return 0;
}
