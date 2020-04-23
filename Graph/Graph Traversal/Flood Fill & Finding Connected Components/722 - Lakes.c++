#include<bits/stdc++.h>
using namespace std;
const int N=100;
int m,x,y,n,cnt;
char grid[N][N],str[N];
int vis[N][N];
int dr[]= {1,0,-1,0};
int dc[]= {0,1,0,-1};

bool valid(int r,int c)
{
    return r>=0&&c>=0&&!vis[r][c]&&grid[r][c]=='0'&&grid[r][c]!='c';
}

void connectedComponent(int r,int c)
{
    if(!valid(r,c))return;
    vis[r][c]=1;
    cnt++;
    for(int d=0; d<4; ++d)connectedComponent(r+dr[d],c+dc[d]);
}

void init()
{
    memset(vis,0,sizeof vis);
    cnt=n=0;
    memset(grid,'c',sizeof grid);
}


int main()
{
    scanf("%d ",&m);
    while(m--)
    {
        init();
        gets(str);
        sscanf(str,"%d %d",&x,&y);
        while(gets(str))
        {
            if(str[0]=='\0')break;
            sscanf(str,"%s",grid[n++]);
        }

        connectedComponent(--x,--y);
        printf("%d\n",cnt);
        if(m)puts("");
    }
    return 0;
}
