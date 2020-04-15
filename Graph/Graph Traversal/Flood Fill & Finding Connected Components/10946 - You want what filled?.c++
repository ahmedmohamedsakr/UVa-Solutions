#include<bits/stdc++.h>
using namespace std;
const int N=55;
int x,y,cnt,problem;
char grid[N][N],w;
int vis[N][N];
vector<pair<char,int> >v;
int dr[]= {1,0,-1,0};
int dc[]= {0,1,0,-1};

bool valid(int r,int c)
{
    return r>=0&&r<x&&c>=0&&c<y&&grid[r][c]!='.'&&!vis[r][c]&&grid[r][c]==w;
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
    v.clear();
}

bool cmp(pair <char,int>&a,pair <char,int>&b)
{
    return (a.second==b.second)?a.first<b.first:a.second>b.second;
}

int main()
{
    while(~scanf("%d%d",&x,&y))
    {
        if(!x&&!y)break;
        init();
        for(int i=0; i<x; ++i)scanf("%s",grid[i]);

        for(int i=0; i<x; ++i)
        {
            for(int j=0; j<y; ++j)
            {
                if(grid[i][j]>='A'&&grid[i][j]<='Z'&&!vis[i][j])
                {
                    cnt=0;
                    w=grid[i][j];
                    connectedComponent(i,j);
                    v.push_back({w,cnt});
                }
            }
        }
        sort(v.begin(),v.end(),cmp);
        printf("Problem %d:\n",++problem);
        for(int i=0; i<v.size(); ++i)printf("%c %d\n",v[i].first,v[i].second);

    }

    return 0;
}
