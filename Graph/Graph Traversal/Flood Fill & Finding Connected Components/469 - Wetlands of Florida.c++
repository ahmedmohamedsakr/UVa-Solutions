#include<bits/stdc++.h>
using namespace std;
const int N=101;
int n,t,i,j;
char grid[N][N],str[N];
int vis[N][N];
int dr[]= {1,1,0,-1,-1,-1, 0, 1};
int dc[]= {0,1,1, 1, 0,-1,-1,-1};

bool valid(int r,int c)
{
    return r>=0&&c>=0&&grid[r][c]!=0&&grid[r][c]=='W'&&!vis[r][c];
}

int floodfill(int r,int c)
{
    if(!valid(r,c))return 0;
    vis[r][c]=1;
    int ans=1;
    for(int d=0; d<8; ++d)ans+=floodfill(r+dr[d],c+dc[d]);
    return ans;
}

void init(){
        n=0;
        memset(grid,0,sizeof grid);
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
            if(str[0]!='W'&&str[0]!='L')
            {
                sscanf(str,"%d %d",&i,&j);
                memset(vis,0,sizeof vis);
                printf("%d\n",floodfill(i-1,j-1));
            }
            else
            {
                sscanf(str,"%s",grid[n++]);
            }
        }
        if(t)puts("");
    }
    return 0;
}
