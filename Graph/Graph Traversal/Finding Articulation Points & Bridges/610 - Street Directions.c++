#include <bits/stdc++.h>
using namespace std;
const int N=1e3+5,M=1e6+5,OO=0x3f3f3f3f;
int n,m,u,v,id,outEdgeCount,d,t;
int vis[N],ids[N],low[N];
vector<int>adj[N];
vector<pair<int,int> >ans;

void Bridges(int current,int parent)
{
    vis[current]=1;
    low[current]=ids[current]=++id;
    for(int to:adj[current])
    {
        if(!vis[to])
        {
            ans.push_back({current,to});
            Bridges(to,current);
            low[current]=min(low[current],low[to]);
            if(low[to]>ids[current])ans.push_back({to,current});
        }
        else if(to!=parent)
        {
            if(ids[to]<ids[current])ans.push_back({current,to});
            low[current]=min(low[current],ids[to]);
        }
    }
}

void findBridges()
{
    id=0;
    for(int i=1; i<=n; ++i)if(!vis[i])Bridges(i,-1);
}


void init()
{
    for(auto &it:adj)it.clear();
    memset(vis,0,sizeof vis);
    memset(low,0,sizeof low);
    memset(ids,0,sizeof ids);
    ans.clear();
}

int main ()
{
    while(~scanf("%d%d",&n,&m) &&(n||m))
    {
        init();
        for(int i=0; i<m; ++i)
        {
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        findBridges();
        sort(ans.begin(),ans.end());
        printf("%d\n\n",++t);
        printf("%d %d\n",ans[0].first,ans[0].second);
        for(int i=1; i<ans.size(); ++i)
        {
            if(ans[i].first==ans[i-1].first&&ans[i].second==ans[i-1].second)swap(ans[i].first,ans[i].second);
            printf("%d %d\n",ans[i].first,ans[i].second);
        }
        puts("#");
    }
    return 0;
}
