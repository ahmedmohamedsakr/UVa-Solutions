#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N =35,M=85,OO = 0x3f3f3f3f;
int cnt,t;
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};
char maze[N][M];

bool valid(int x,int y)
{
    return maze[x][y]!='#'&&maze[x][y]!='X';
}

void dfs(int x,int y)
{
    maze[x][y]='#';
    for(int i=0; i<4 ; ++i)
    {
        int nx=dx[i]+x,ny=dy[i]+y;
        if(valid(nx,ny))dfs(nx,ny);
    }
}

int main()
{
    scanf("%d ",&t);
    while(t--)
    {
        cnt=0;
        while(gets(maze[cnt]))
        {
            if(maze[cnt][0]=='_')break;
            cnt++;
        }
        for(int i=0; i<cnt; ++i)
            for(int j=0; maze[i][j]; ++j)if(maze[i][j]=='*')dfs(i,j);
        for(int i=0; i<=cnt; ++i)puts(maze[i]);
    }
    return 0;
}
