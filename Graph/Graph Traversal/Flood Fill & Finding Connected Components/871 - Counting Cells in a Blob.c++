#include<bits/stdc++.h>
using namespace std;
const int N=30;
int t,n,maxi,cnt;
string grid[N];
char str[N];
int vis[N][N];
int dr[]= {1,1,0,-1,-1,-1, 0, 1};
int dc[]= {0,1,1, 1, 0,-1,-1,-1};

bool valid(int r,int c)
{
    return r>=0&&r<n&&c>=0&&c<n&&grid[r][c]!='0'&&!vis[r][c];
}

void connectedComponent(int r,int c)
{
    if(!valid(r,c))return;
    vis[r][c]=1;
    cnt++;
    for(int d=0; d<8; ++d)connectedComponent(r+dr[d],c+dc[d]);
}

void init()
{
    memset(vis,0,sizeof vis);
    maxi=n=0;
}

int main()
{
    scanf("%d ",&t);
    while(t--)
    {
        init();
        while(gets(str))
        {
            if(str[0]=='\0')break;
            grid[n++]=str;
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(grid[i][j]=='1'&&!vis[i][j])
                {
                    cnt=0;
                    connectedComponent(i,j);
                    maxi=max(maxi,cnt);
                }
            }
        }
        printf("%d\n",maxi);
        if(t)puts("");
    }
    return 0;
}
