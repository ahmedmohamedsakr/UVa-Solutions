#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e2+5,M=1e6+5,OO=0x3f3f3f3f;
int n,m,u,v,vis[N];
vector<int>adj[N];

void dfs(int src)
{
    vis[src]=1;
    for(auto it:adj[src])if(!vis[it])dfs(it);
    printf("%d ",src);
}

void init()
{
    memset(vis,0,sizeof vis);
    for(int i=0; i<=n; ++i)adj[i].clear();
}
int main ()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(!n&&!m)break;
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            adj[v].push_back(u);
        }
        for(int i=1; i<=n; ++i)if(!vis[i])dfs(i);
        puts("");
    }
    return 0;
}
