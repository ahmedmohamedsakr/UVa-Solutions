#include<bits/stdc++.h>
using namespace std;
const int N=104;
int R,C,f,sec,stars;
char grid[N][N];
int vis[N][N];
int dr[]= {1,1,0,-1,-1,-1, 0, 1};
int dc[]= {0,1,1, 1, 0,-1,-1,-1};

bool valid(int r,int c)
{
    return r>=0&&r<R&&c>=0&&c<C&&grid[r][c]!='.'&&!vis[r][c];
}

void connectedComponent(int r,int c)
{
    if(!valid(r,c))return;
    if(grid[r][c]=='*'&&sec)f=1;
    sec=1;
    vis[r][c]=1;
    for(int d=0; d<8; ++d)connectedComponent(r+dr[d],c+dc[d]);
}

void init()
{
    memset(vis,0,sizeof vis);
    stars=0;
}

int main()
{
    while(~scanf("%d%d",&R,&C)){
        if(!R&&!C)break;
        init();
        for(int i=0; i<R; ++i)scanf("%s",grid[i]);
        for(int i=0; i<R; ++i)
        {
            for(int j=0; j<C; ++j)
            {
                if(grid[i][j]=='*'&&!vis[i][j])
                {
                    f=sec=0;
                    connectedComponent(i,j);
                    if(!f)stars++;
                }
            }
        }
        printf("%d\n",stars);
    }
    return 0;
}
