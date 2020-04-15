#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,t,f,cnt;
char grid[N][N];
int vis[N][N];
int dr[]= {1,0,-1,0};
int dc[]= {0,1,0,-1};

bool valid(int r,int c)
{
    return r>=0&&r<n&&c>=0&&c<n&&grid[r][c]!='.'&&!vis[r][c];
}

void connectedComponent(int r,int c)
{
    if(!valid(r,c))return;
    if(grid[r][c]=='x')f=1;
    vis[r][c]=1;
    for(int d=0; d<4; ++d)connectedComponent(r+dr[d],c+dc[d]);
}

void init()
{
    memset(vis,0,sizeof vis);
    cnt=0;
}

int main()
{
    scanf("%d",&t);
    for(int q=1; q<=t; ++q)
    {
        init();
        scanf("%d",&n);
        for(int i=0; i<n; ++i)scanf("%s",grid[i]);

        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if((grid[i][j]=='x'||grid[i][j]=='@')&&!vis[i][j])
                {
                    f=0;
                    connectedComponent(i,j);
                    if(f)cnt++;
                }
            }
        }
        printf("Case %d: %d\n",q,cnt);

    }
    return 0;
}
