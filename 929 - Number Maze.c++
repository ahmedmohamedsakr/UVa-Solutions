#include <bits/stdc++.h>

using namespace std;

const int N =1e3,OO = 0x3f3f3f3f;
int tc,n,m;
int dis[N][N],maz[N][N];
int di[]= {1,-1,0,0};
int dj[]= {0,0,1,-1};
bool Valid(int i,int j)
{
    return (i>=0&&i<n&&j>=0&&j<m);
}
void init()
{
    memset(maz,0,sizeof maz);
    memset(dis,OO,sizeof dis);
}
void Dijkstra(int i,int j)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    pq.push({maz[i][j],{i,j}});
    dis[i][j]=maz[i][j];
    while(!pq.empty())
    {
        int d=pq.top().first,pi=pq.top().second.first,pj=pq.top().second.second;
        pq.pop();
        if(d>dis[pi][pj])continue;
        for(int i=0; i<4; ++i)
        {
            int ni=di[i]+pi,nj=dj[i]+pj;
            if(Valid(ni,nj))
            {
                if(dis[ni][nj]>d+maz[ni][nj])
                {
                    dis[ni][nj]=d+maz[ni][nj];
                    pq.push({dis[ni][nj],{ni,nj}});
                }
            }
        }
    }
}
int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                scanf("%d",&maz[i][j]);
        Dijkstra(0,0);
        printf("%d\n",dis[n-1][m-1]);
    }
}
