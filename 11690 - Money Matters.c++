#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int tc,ow,n,m,u,v,x,f,a[N],vis[N];
vector<int>adj[N];
void init()
{
    memset(vis,0,sizeof vis);
    memset(adj,0,sizeof adj);
    f=0;
}
void dfs(int u)
{
    vis[u]=1;
    for(int ch:adj[u])
    {
        if(!vis[ch])x+=a[ch],dfs(ch);
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
            scanf("%d",&ow),a[i]=ow;
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0; i<n; ++i)
        {
            if(!vis[i])x=a[i],dfs(i);
            if(x)
            {
                puts("IMPOSSIBLE");
                f=1;
                break;
            }
        }
        if(!f)puts("POSSIBLE");
    }
}
