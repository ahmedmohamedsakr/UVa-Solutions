#include<bits/stdc++.h>
using namespace std;
const int N=104;
bool vis[N];
int n,from,to,q,u,cnt,f;
vector <int>ans[N];
vector <int>adj[N];

void dfs(int u)
{
    if(f)vis[u]=1;
    f=1;
    for(int i=0; i<adj[u].size(); ++i)
    {
        int ch=adj[u][i];
        if(!vis[ch])dfs(ch);
    }
}

void findInaccessible(int u)
{
    memset(vis,0,sizeof vis);
    f=0;
    dfs(u);
    for(int i=1; i<=n; ++i)if(!vis[i])ans[u].push_back(i);

}

void init()
{
    memset(adj,0,sizeof adj);
    for(int i=1;i<=n;++i)ans[i].clear();
}

int main()
{
    while(cin>>n)
    {
        if(!n)break;
        init();
        while(cin>>from)
        {
            if(!from)break;
            while(cin>>to)
            {
                if(!to)break;
                adj[from].push_back(to);
            }
        }

        for(int i=1; i<=n; ++i)
        {
            findInaccessible(i);
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&u);
            cnt=ans[u].size();
            printf("%d",cnt);
            for(int i=0; i<cnt; ++i)printf(" %d",ans[u][i]);
            puts("");
        }

    }
    return 0;
}
