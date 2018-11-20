#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=64,M=10,OO=0x3f3f3f3f;
int k,ans;
int board[M][M],vis_col[M],right_daig[2*M],left_diag[2*M];
void solve(int row=0,int sum=0)
{
    if(row==8)
    {
        ans=max(ans,sum);
        return;
    }
    for(int col=0; col<8; ++col)
    {
        if(!vis_col[col]&&!right_daig[col+row]&&!left_diag[col-row+8])
        {
            vis_col[col]=right_daig[col+row]=left_diag[col-row+8]=1;
            solve(row+1,sum+board[row][col]);
            vis_col[col]=right_daig[col+row]=left_diag[col-row+8]=0;
        }
    }

}

int main()
{
    scanf("%d",&k);
    while(k--)
    {
        for(int i=0; i<8; ++i)
            for(int j=0; j<8; ++j)scanf("%d",&board[i][j]);
        ans=0;
        solve();
        printf("%5d\n", ans);
    }

    return 0;
}
