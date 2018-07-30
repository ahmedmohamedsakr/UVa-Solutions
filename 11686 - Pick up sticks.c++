#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,u,v,isdag;
int vis[N];
vector<int>adj[N];
vector<int>a;
void dfs(int p)
{
    vis[p]=2;
    for(int ch:adj[p]){
        if(vis[ch]==2)isdag=0;
        if(!vis[ch])dfs(ch);
    }
    a.push_back(p);
    vis[p]=1;
}
void init()
{
    memset(vis,0,sizeof vis);
    memset(adj,0,sizeof adj);
    a.clear();
    isdag=1;
}
int main()
{

    while(true)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
        }
        for(int i=1;i<=n&&isdag;++i)
        if(!vis[i])dfs(i);
        if(!isdag){
            puts("IMPOSSIBLE");
        }else{
            for(int i=a.size()-1;i>=0;--i)
                printf("%d\n",a[i]);
        }
    }
}
