#include <bits/stdc++.h>
using namespace std;
const int N=1e2+5,M=1e6+5,OO=0x3f3f3f3f;
int n,r,id,outEdgeCount,d,f;
int vis[N],ids[N],low[N],artsPoint[N];
vector<int>adj[N];
vector<string>ans;
map<string,int>cities;
string city,u,v;

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
            if(low[to]>=ids[current])artsPoint[current]=1;
        }
        else if(to!=parent)low[current]=min(low[current],ids[to]);
    }
}

void findArtsPoint()
{
    id=0;
    for(int i=0; i<n; ++i)if(!vis[i]){
            outEdgeCount=0;
            ArticulationPoint(i,i,-1);
            artsPoint[i]=(outEdgeCount>1);
        }
    for(auto it:cities)if(artsPoint[it.second])ans.push_back(it.first);
    sort(ans.begin(),ans.end());
}


void init()
{
    for(auto &it:adj)it.clear();
    cities.clear();
    memset(vis,0,sizeof vis);
    memset(low,0,sizeof low);
    memset(ids,0,sizeof ids);
    memset(artsPoint,0,sizeof artsPoint);
    ans.clear();
}

int main ()
{
    while(~scanf("%d",&n)&&n)
    {
        init();
        for(int i=0; i<n; ++i)
        {
            cin>>city;
            cities[city]=i;
        }
        scanf("%d",&r);
        for(int i=0; i<r; ++i)
        {
            cin>>u>>v;
            adj[cities[u]].push_back(cities[v]);
            adj[cities[v]].push_back(cities[u]);
        }
        findArtsPoint();
        if(f)puts("");
        printf("City map #%d: %d camera(s) found\n",++d,ans.size());
        for(int i=0; i<ans.size(); ++i)cout<<ans[i]<<endl;
        f=1;
    }
    return 0;
}
