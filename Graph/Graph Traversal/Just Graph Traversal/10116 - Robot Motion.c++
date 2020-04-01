#include<bits/stdc++.h>
using namespace std;
const int N=11;

int n,m,c,r,ans,v;
string maze[N];
int vis[N][N];

void init()
{
    v=r=ans=0;
    c--;
    memset(vis,0,sizeof vis);
}

bool valid()
{
    return r<n&&r>=0&&c<m&&c>=0;
}


void excuteInstructions()
{
    if(maze[r][c]=='W')c--;
    else if(maze[r][c]=='E')c++;
    else if(maze[r][c]=='N')r--;
    else if(maze[r][c]=='S')r++;
}

void traverse()
{
    init();
    while(true)
    {
        if(!valid())
        {
            v=1;
            break;
        }
        if(vis[r][c])break;
        vis[r][c]=++ans;
        excuteInstructions();

    }
}


int main()
{
    while(scanf("%d%d%d",&n,&m,&c))
    {
        if(!n&&!m&&!c)break;
        for(int i=0; i<n; ++i)cin>>maze[i];
        traverse();
        if(v)printf("%d step(s) to exit\n",ans);
        else
        {
            vis[r][c]--;
            printf("%d step(s) before a loop of %d step(s)\n",vis[r][c],ans-vis[r][c]);
        }
    }
    return 0;
}
