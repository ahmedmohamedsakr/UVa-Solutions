#include<bits/stdc++.h>
using namespace std;
const int N=105;
int t,n,m,maxi,u,v,ending,ans;
vector<int>adj[N];
int w[N];
bool vis[N];

void dfs(int p=0)
{
    vis[p]=1;
    maxi=-1;
    for(int i=0; i<adj[p].size(); ++i)
    {
        int ch=adj[p][i];
        if(maxi<w[ch]&&!vis[ch])
        {
            maxi=w[ch];
            ending=ch;
        }
    }
    if(!vis[ending])
    {
        ans+=maxi;
        dfs(ending);
    }
}

void init()
{
    for(int i=0; i<n; ++i)adj[i].clear();
    ending=ans=0;
    memset(w,0,sizeof w);
    memset(vis,0,sizeof vis);
}

int main()
{
    scanf("%d",&t);
    for(int q=1; q<=t; ++q)
    {
        scanf("%d%d",&n,&m);
        init();
        for(int i=0; i<n; ++i)scanf("%d",w+i);
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
        }
        dfs();
        printf("Case %d: %d %d\n",q,ans,ending);
    }
    return 0;
}
