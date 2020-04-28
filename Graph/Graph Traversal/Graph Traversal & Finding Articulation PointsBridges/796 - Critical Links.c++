#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;

int n,m,u,v,id;
int vis[N],low[N],ids[N];
vector<int> adj[N];
vector< pair<int, int> > bridge;

void findBridge(int current,int parent)
{
    low[current] = ids[current] = ++id;
    vis[current]=1;
    for(int to:adj[current])
    {
        if(!vis[to])
        {
            findBridge(to,current);
            low[current]=min(low[current],low[to]);
            if(low[to]>ids[current])current<to?bridge.push_back({current,to}):bridge.push_back({to,current});
        }
        else if(parent!=to)low[current]=min(low[current], ids[to]);
    }
}

void init()
{
    for(auto &it:adj)it.clear();
    memset(vis,0,sizeof vis);
    id=0;
    bridge.clear();
}
int main()
{
    while(~scanf("%d", &n))
    {
        init();
        for(int i=0; i<n; i++)
        {
            scanf("%d",&u);
            scanf(" (%d)",&m);
            for(int j=0; j<m; j++)
            {
                scanf("%d",&v);
                adj[u].push_back(v);
            }
        }

        for(int i=0; i<n; i++)if(!vis[i])findBridge(i,-1);

        sort(bridge.begin(), bridge.end());
        printf("%d critical links\n",bridge.size());
        for(int i=0; i<bridge.size(); i++)
            printf("%d - %d\n",bridge[i].first,bridge[i].second);
        printf("\n");
    }
    return 0;
}
