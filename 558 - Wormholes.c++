#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
const int N=1e3+5,OO=0x3f3f3f3f;
int dis[N],n,m,x,y,t,c;
vector<ii>adj[N];
void init()
{
    memset(dis,OO,sizeof dis);
    memset(adj,0,sizeof adj);
}
void BellmanFord(int src)
{
    dis[src]=0;
    for(int i=0; i<n-1; ++i)
        for(int u=0; u<n; ++u)
            for(ii ch:adj[u])
                dis[ch.first]=min(dis[ch.first],dis[u]+ch.second);
}
bool CheckNegativeCycle()
{
    for(int u=0; u<n; ++u)
        for(ii ch:adj[u])
            if(dis[ch.first]>dis[u]+ch.second)return 0;
    return 1;
}
int main()
{
    scanf("%d",&c);
    while(c--)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d%d",&x,&y,&t);
            adj[x].push_back({y,t});
        }
        BellmanFord(0);
        puts(CheckNegativeCycle()?"not possible":"possible");
    }
    return 0;
}
