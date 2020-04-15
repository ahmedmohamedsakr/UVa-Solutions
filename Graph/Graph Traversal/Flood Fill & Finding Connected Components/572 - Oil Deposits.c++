#include<bits/stdc++.h>
using namespace std;
const int N=104;
int n,m,deposits;
char grid[N][N];
int vis[N][N];
int dr[]= {1,1,0,-1,-1,-1, 0, 1};
int dc[]= {0,1,1, 1, 0,-1,-1,-1};

bool valid(int r,int c)
{
    return r>=0&&r<m&&c>=0&&c<n&&grid[r][c]!='*'&&!vis[r][c];
}

void connectedComponent(int r,int c)
{
    if(!valid(r,c))return;
    vis[r][c]=1;
    for(int d=0; d<8; ++d)connectedComponent(r+dr[d],c+dc[d]);
}

void init()
{
    memset(vis,0,sizeof vis);
    deposits=0;
}

int main()
{
    while(~scanf("%d%d",&m,&n)){
        if(!m)break;
        init();
        for(int i=0; i<m; ++i)scanf("%s",grid[i]);
        for(int i=0; i<m; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]=='@'&&!vis[i][j])
                {
                    deposits++;
                    connectedComponent(i,j);
                }
            }
        }
        printf("%d\n",deposits);
    }
    return 0;
}
