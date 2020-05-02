#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,OO=0x3f3f3f3f;
int n,u,v,id,m,outEdgeCount;
int vis[N],ids[N],low[N],artsPoint[N];
vector<int>adj[N];
vector<pair<int,int> >ans;

void ArticulationPoint(int root,int current,int parent)
{
    vis[current]=1;
    if(root==parent)outEdgeCount++;
    low[current]=ids[current]=++id;
    for(int to:adj[current])
    {
        if(!vis[to])
        {
            ArticulationPoint(root,to,current);
            low[current]=min(low[current],low[to]);
            if(low[to]>=ids[current])artsPoint[current]++;
        }
        else if(to!=parent)low[current]=min(low[current],ids[to]);
    }
}

void findArtsPoint()
{
    id=outEdgeCount=0;
    for(int i=0; i<n; ++i)if(!vis[i]){
            ArticulationPoint(i,i,-1);
            artsPoint[i]=(outEdgeCount>1);
        }
        
    for(int i=0; i<n; ++i)ans.push_back({i,++artsPoint[i]});
}

bool cmp(pair<int,int> &l,pair<int,int> &r){
    return l.second==r.second ?l.first<r.first:l.second>r.second;
}

void init()
{
    for(auto &it:adj)it.clear();
    memset(vis,0,sizeof vis);
    memset(artsPoint,0,sizeof artsPoint);
    ans.clear();
}

int main ()
{
    while(~scanf("%d%d",&n,&m) and (n||m))
    {
        init();
        while(~scanf("%d%d",&u,&v) and u!=-1)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        findArtsPoint();
        sort(ans.begin(),ans.end(),cmp);
        for(int i=0; i<m; i++)printf("%d %d\n",ans[i].first,ans[i].second);
        puts("");
    }
    return 0;
}
