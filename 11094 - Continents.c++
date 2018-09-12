#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N=25,M=1e4,OO=0x3f3f3f3f;
int n,m,x,y,vis[N][N],vid,cnt,ans;
char maze[N][N],land;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

bool valid(int x,int y)
{
    return (x>=0&&x<n&&maze[x][y]==land&&vis[x][y]!=vid);
}

void dfs(int i,int j)
{
    vis[i][j]=vid;
    cnt++;
    for(int k=0; k<4; k++)
    {
        int ni=dx[k]+i,nj=((dy[k]+j)%m+m)%m;
        if(valid(ni,nj))dfs(ni,nj);
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ++vid,ans=0;
        for(int i=0; i<n; ++i)scanf("%s",&maze[i]);
        scanf("%d%d",&x,&y);
        land=maze[x][y];
        dfs(x,y);
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(vis[i][j]!=vid&&maze[i][j]==land)
                {
                    cnt=0;
                    dfs(i,j);
                    ans=max(ans,cnt);
                }
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}
